#include "SQLDatabase.h"
#include <iostream>
#include <sstream>

SQLDatabase::SQLDatabase()
: m_mutex()
{
    m_mysql = mysql_init(NULL);
}

SQLDatabase::~SQLDatabase()
{
    mysql_close(m_mysql);
}

bool SQLDatabase::init(char* login, char* password, char* address, char* database)
{
    if (mysql_real_connect(m_mysql, address, login, password, database, 0, NULL, 0) != NULL)
    {
        std::cout << "Connect successfully to MySQL database" << std::endl;

        return setupTables();
    }
    else
    {
        std::cout <<  "Can't connect to the database :" << std::endl;
        std::cout << "Error in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << mysql_error(m_mysql) << std::endl;
        return false;
    }
}

MYSQL_RES* SQLDatabase::executeQuery(std::string query)
{
    sf::Lock lock(m_mutex);
    
    if (mysql_query(m_mysql, query.c_str()) != 0)
    {
        std::cout << "Can't execute query : \"" << query << "\", error thrown : ";
        std::cout << mysql_error(m_mysql) << std::endl;
    }
    
    return mysql_use_result(m_mysql);
}

bool SQLDatabase::setupTables()
{
    std::cout << "Setting up tables ..." << std::endl;

    if (mysql_query(m_mysql, "CREATE TABLE IF NOT EXISTS users (username VARCHAR(16) NOT NULL, password CHAR(16) NOT NULL, ip INT UNSIGNED, session CHAR(16), PRIMARY KEY (username)) ENGINE=INNODB;") != 0)
    {
        std::cout <<  "Can't setup tables : ";
        std::cout << mysql_error(m_mysql) << std::endl;
        return false;
    }
    
    return true;
}

