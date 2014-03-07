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
    try
    {
        std::ostringstream stream;
        stream << "tcp://" << address << ":3306/" << database;
        m_connection = m_driver->connect(stream.str(), login, password);
        std::cout << "Connect successfully to MySQL database" << std::endl;
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

    return true;
}
