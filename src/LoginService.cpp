#include "LoginService.h"
#include "Main.h"
#include <iostream>

LoginService::LoginService(SQLDatabase &db)
: m_listener(), m_table(db), m_running(false), m_mutex(),
  m_dictionnary("0123456789abcdefghijklmnopqrstuvwxyz")
{

}
 
 LoginService::~LoginService()
 {
 
 }
 
 void LoginService::run()
 {
    if (m_listener.listen(LOGIN_PORT) != sf::Socket::Done)
    {
        logger << "Can't listening on port " << LOGIN_PORT << endl;
        logger << "Please check your firewall, ";
        logger << "or if the port is already listening by another software" << endl;
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
        
            if (selector.wait(sf::seconds(5)))
            {
                sf::TcpSocket socket;
            
                if (m_listener.accept(socket) == sf::Socket::Done) 
                {
                    sf::Packet packet;
                    socket.receive(packet);
                    sf::Uint8 id;
                    packet >> id;
                    
                    sf::Packet response;
                    
                    switch (id)
                    {
                    case LOGIN:
                    {
                        sf::String username, password;
                        packet >> username;
                        packet >> password;
                        
                        if (!m_table.isRegistered(username.toAnsiString()))
                        {
                            response << (sf::Uint8) FAIL << (sf::Uint8) UNKNOWN_USER;
                            break;
                        }
                        
                        if (m_table.getPassword(username.toAnsiString()).compare(password.toAnsiString()) == 0)
                        {
                            std::string session = generateSession();
                            m_table.setSession(username.toAnsiString(), session);
                            m_table.setIP(username.toAnsiString(), socket.getRemoteAddress());
                            response << (sf::Uint8) SUCCESS << sf::String(session);
                            logger << "[LOGIN] " << username.toAnsiString() << " has been logged in from " << socket.getRemoteAddress().toString() << endl;
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
                    logger << "[LOGIN] Lost connection from " << socket.getRemoteAddress().toString() << endl;
                }
            }
        
            m_mutex.lock();
        }
    }
    
    m_listener.close();
 }
 
 void LoginService::stop()
 {
    m_mutex.lock();
    logger << "Stopping the login service" << endl;
    m_running = false;
    m_mutex.unlock();
 }
 
 std::string LoginService::generateSession() const
 {
    char session[16];
    
    for (unsigned int i = 0; i < 16; i++)
    {
        session[i] = m_dictionnary[rand() % m_dictionnary.size()];
    }
    
    return std::string(session);
 }
