#ifndef SQLDATABASE_H_
#define SQLDATABASE_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <mysql_driver.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class SQLDatabase
{
public:
	SQLDatabase();
public:
	virtual ~SQLDatabase();

	bool init(char* login, char* password, char* address, char* database);

private:
	sf::Mutex m_mutex;
	sql::mysql::MySQL_Driver *m_driver;
	sql::Connection *m_connection;
};

#endif /* SQLDATABASE_H_ */
