#include "SQLDatabase.h"
#include <mysql_connection.h>
#include <sstream>

SQLDatabase::SQLDatabase()
: m_mutex()
{
    m_connection = 0;
    m_driver = sql::mysql::get_driver_instance();
}

SQLDatabase::~SQLDatabase()
{
    if (m_connection)
        delete m_connection;
}

bool SQLDatabase::init(char* login, char* password, char* address, char* database)
{
    if (m_connection)
    {
        std::cerr << "The database has already be initialized" << std::endl;
        return false;
    }

    try
    {
        std::ostringstream stream;
        stream << "tcp://" << address << ":3306/" << database;
        m_connection = m_driver->connect(stream.str(), login, password);
        std::cout << "Connect successfully to MySQL database" << std::endl;

        return setupTables();
    }
    catch(sql::SQLException &e)
    {
        std::cout <<  "Can't connect to the database :" << std::endl;
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        return false;
    }
}

sql::Statement* SQLDatabase::createStatement()
{
    sf::Lock lock(m_mutex);
    return m_connection->createStatement();
}

sql::PreparedStatement* SQLDatabase::prepareStatement(std::string statement)
{
    sf::Lock lock(m_mutex);
    return m_connection->prepareStatement(statement);
}

bool SQLDatabase::setupTables()
{
    std::cout << "Setting up tables ..." << std::endl;

    try
    {
        sql::Statement *statement = m_connection->createStatement();
        statement->execute("CREATE TABLE IF NOT EXISTS users (username VARCHAR(16) NOT NULL, password CHAR(16) NOT NULL, ip INT UNSIGNED, session CHAR(16), PRIMARY KEY (username)) ENGINE=INNODB;");

        delete statement;
    }
    catch(sql::SQLException &e)
    {
        std::cout <<  "Can't setup tables:" << std::endl;
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        return false;
    }
    return true;
}

