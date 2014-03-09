#include "LoginService.h"
#include "Main.h"
#include <iostream>

LoginService::LoginService(SQLDatabase &db)
: m_listener(), m_table(db), m_running(false), m_mutex()
{

}
 
 LoginService::~LoginService()
 {
 
 }
 
 void LoginService::run()
 {
    if (m_listener.listen(LOGIN_PORT) != sf::Socket::Done)
    {
        std::cout << "Can't listening on port " << LOGIN_PORT << std::endl;
        std::cout << "Please check your firewall, ";
        std::cout << "or if the port is already listening by another software" << std::endl;
    }
    else
    {
        m_mutex.lock();
        m_running = true;
        sf::SocketSelector selector;
        selector.add(m_listener);
    
        while (m_running)
        {
            m_mutex.unlock();
        
            if (selector.wait(sf::seconds(5)) && selector.isReady(m_listener))
            {
                sf::TcpSocket socket;
            
                if (m_listener.accept(socket) == sf::Socket::Done) 
                {
                    std::cout << "Client's connected from " << socket.getRemoteAddress().toString() << std::endl;
                    sf::Packet packet;
                    socket.receive(packet);
                    sf::Uint8 id;
                    packet >> id;
                    
                    sf::Packet response;
                    
                    switch (id)
                    {
                    case LOGIN:
                    {
                        sf::String username, passwordMD5;
                        packet >> username;
                        packet >> passwordMD5;
                        
                        if (!m_table.isRegistered(username.toAnsiString()))
                        {
                            response << (sf::Uint8) FAIL << (sf::Uint8) UNKNOWN_USER;
                            break;
                        }
                        
                        if (m_table.getPassword(username.toAnsiString()).compare(passwordMD5.toAnsiString()) == 0)
                        {
                            std::string session = generateSession();
                            m_table.setSession(username.toAnsiString(), session);
                            m_table.setIP(username.toAnsiString(), socket.getRemoteAddress());
                            response << (sf::Uint8) SUCCESS << sf::String(session);
                        }
                        else
                        {
                            response << (sf::Uint8) FAIL << (sf::Uint8) BAD_PASSWORD;
                        }
                        
                        break;
                    }
                    default:
                        response << (sf::Uint8) FAIL << (sf::Uint8) BAD_REQUEST;
                        break;
                    }
                    
                    socket.send(response);
                    socket.disconnect();
                }
                else
                {
                    std::cout << "Lost connection from " << socket.getRemoteAddress().toString() << std::endl;
                }
            }
        
            m_mutex.lock();
        }
    
        m_listener.close();
    }
 }
 
 void LoginService::stop()
 {
    m_mutex.lock();
    std::cout << "Stopping the login service" << std::endl;
    m_running = false;
    m_mutex.unlock();
 }
 
 std::string LoginService::generateSession() const
 {
    //TODO
    return "session";
 }
