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
    
        while (m_running)
        {
            m_mutex.unlock();
        
            sf::TcpSocket socket;
            
            if (m_listener.accept(socket) == sf::Socket::Done) // FIXME When the server ask to stop, the listern is always waiting for a connection
            {
                std::cout << "Client's connected from " << socket.getRemoteAddress().toString() << std::endl;
                
            }
            else
            {
                std::cout << "Lost connection from " << socket.getRemoteAddress().toString() << std::endl;
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
