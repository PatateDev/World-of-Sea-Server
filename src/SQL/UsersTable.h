#ifndef USERSTABLE_H_
#define USERSTABLE_H_

#include "Table.h"
#include <vector>

class UsersTable : public Table
{
public:
    UsersTable(SQLDatabase &db);
    virtual ~UsersTable();

public:
    std::string getPassword(std::string username) const;

    sf::IpAddress getIP(std::string username) const;

    std::string getSession(std::string username) const;

    void setPassword(std::string username, std::string password);

    void setIP(std::string username, sf::IpAddress address);

    void setSession(std::string username, std::string session);

    std::vector<std::string> getUsers() const;

    bool isRegistered(std::string username);
    
private:
    const unsigned int m_usernameIndex, m_passwordIndex, m_ipIndex, m_sessionIndex;
};

#endif /* USERSTABLE_H_ */
