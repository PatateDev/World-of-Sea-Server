#include "SQLDatabase.h"
#include "../Logger.h"
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
        logger << "Connect successfully to MySQL database" << endl;

        return setupTables();
    }
    else
    {
        logger <<  "Can't connect to the database :" << endl;
        logger << "Error in " << __FILE__;
        logger << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        logger << mysql_error(m_mysql) << endl;
        return false;
    }
}

MYSQL_RES* SQLDatabase::executeQuery(std::string query)
{
    sf::Lock lock(m_mutex);
    
    if (mysql_query(m_mysql, query.c_str()) != 0)
    {
        logger << "Can't execute query : \"" << query << "\", error thrown : ";
        logger << mysql_error(m_mysql) << endl;
    }
    
    return mysql_use_result(m_mysql);
}

bool SQLDatabase::setupTables()
{
    logger << "Setting up tables ..." << endl;

    if (mysql_query(m_mysql, "CREATE TABLE IF NOT EXISTS users (username VARCHAR(16) NOT NULL, password CHAR(16) NOT NULL, ip INT UNSIGNED, session CHAR(16), PRIMARY KEY (username)) ENGINE=INNODB;") != 0)
    {
        logger <<  "Can't setup tables : ";
        logger << mysql_error(m_mysql) << endl;
        return false;
    }
    
    return true;
}

