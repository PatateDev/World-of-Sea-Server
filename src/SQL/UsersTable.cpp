#include "UsersTable.h"
#include <iostream>
#include <sstream>

UsersTable::UsersTable(SQLDatabase& db)
: Table(db, "users"),
  m_usernameIndex(0), m_passwordIndex(1), m_ipIndex(2), m_sessionIndex(3)
{

}

UsersTable::~UsersTable()
{

}

std::string UsersTable::getPassword(std::string username) const
{
    std::string password("");
    std::ostringstream query;
    query << "SELECT * FROM " << m_name;
    query << " WHERE username='" << username << "'";

    MYSQL_RES *result = m_database.executeQuery(query.str());
    
    if (result != 0)
    {
        MYSQL_ROW row = mysql_fetch_row(result);
        
        if (row)
            password = row[m_passwordIndex];
        else
            std::cout << "No username matching with \"" << username << "\"" << std::endl;
    }
    
    mysql_free_result(result);

    return password;
}

sf::IpAddress UsersTable::getIP(std::string username) const
{
    sf::IpAddress ip;
    
    std::ostringstream query;
    query << "SELECT * FROM " << m_name;
    query << " WHERE username='" << username << "'";
    
    MYSQL_RES *result = m_database.executeQuery(query.str());

    if (result != 0)
    {
        MYSQL_ROW row = mysql_fetch_row(result);
        
        if (row)
        {
            std::string ipString = row[m_ipIndex];
            std::istringstream ipStream(ipString);
            sf::Uint32 ipBytes;
            ipStream >> ipBytes;
            ip = sf::IpAddress(ipBytes);
        }
        else
            std::cout << "No username matching with \"" << username << "\"" << std::endl;
    }
    
    mysql_free_result(result);

    return ip;
}

std::string UsersTable::getSession(std::string username) const
{
    std::string session("");

    std::ostringstream query;
    query << "SELECT * FROM " << m_name;
    query << " WHERE username='" << username << "'";

    MYSQL_RES *result = m_database.executeQuery(query.str());
    
    if (result != 0)
    {
        MYSQL_ROW row = mysql_fetch_row(result);
        
        if (row)
            session = row[m_sessionIndex];
        else
            std::cout << "No username matching with \"" << username << "\"" << std::endl;
    }
    
    mysql_free_result(result);

    return session;
}

void UsersTable::setPassword(std::string username, std::string password)
{
    std::ostringstream query;
    query << "UPDATE " << m_name;
    query << " SET password='" << password << "'";
    query << " WHERE username='" << username << "'";
    m_database.executeQuery(query.str());
}

void UsersTable::setIP(std::string username, sf::IpAddress address)
{
    std::ostringstream query;
    query << "UPDATE " << m_name;
    query << " SET ip='" << address.toInteger() << "'";
    query << " WHERE username='" << username << "'";
    m_database.executeQuery(query.str());
}

void UsersTable::setSession(std::string username, std::string session)
{
    std::ostringstream query;
    query << "UPDATE " << m_name;
    query << " SET session='" << session << "'";
    query << " WHERE username='" << username << "'";
    m_database.executeQuery(query.str());
}

std::vector<std::string> UsersTable::getUsers() const
{
    std::vector<std::string> v;

    std::ostringstream query;
    query << "SELECT * FROM " << m_name;
    
    MYSQL_RES *result = m_database.executeQuery(query.str());
    MYSQL_ROW row;

    if (result)
    {
        while ((row = mysql_fetch_row(result)))
        {
            v.push_back(row[m_usernameIndex]);
        }
    }
    else
        std::cout << "Can't fetch usernames" << std::endl;
    
    return v;
}

bool UsersTable::isRegistered(std::string username)
{
    std::vector<std::string> users = getUsers();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].compare(username) == 0)
            return true;
    }

    return false;
}
