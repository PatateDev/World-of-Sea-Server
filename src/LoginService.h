#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "SQL/UsersTable.h"
#include "SQL/SQLDatabase.h"

enum LoginPacketId
{
    LOGIN = 0,
    SUCCESS = 1,
    FAIL = 2
};

class LoginService
{
public:
    LoginService(SQLDatabase &db);
    virtual ~LoginService();
    
    void run();
    void stop();
    
private:
    sf::TcpListener m_listener;
    UsersTable m_table;
    bool m_running;
    sf::Mutex m_mutex;
};

#endif
