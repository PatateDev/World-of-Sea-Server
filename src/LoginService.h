#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "SQL/UsersTable.h"
#include "SQL/SQLDatabase.h"

enum LoginPacketId //Stored in sf::Uint8
{
    LOGIN = 0,
    SUCCESS = 1,
    FAIL = 2
};

enum LoginErrorId //Stored in sf::Uint8
{
    INTERNAL_ERROR = 0,
    UNKNOWN_USER = 1,
    BAD_PASSWORD = 2,
    BAD_REQUEST = 3
};

class LoginService
{
public:
    LoginService(SQLDatabase &db);
    virtual ~LoginService();
    
    void run();
    void stop();
    
private:
    std::string generateSession() const;
    
private:
    sf::TcpListener m_listener;
    UsersTable m_table;
    bool m_running;
    sf::Mutex m_mutex;
    const unsigned int m_dictionnaryLength;
    const char* m_dictionnary;
};

#endif
