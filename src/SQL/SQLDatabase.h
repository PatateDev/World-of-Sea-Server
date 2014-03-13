#ifndef SQLDATABASE_H_
#define SQLDATABASE_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <mysql/mysql.h>

class SQLDatabase
{
public:
	SQLDatabase();
public:
	virtual ~SQLDatabase();

	bool init(char* login, char* password, char* address, char* database);
	
	MYSQL_RES* executeQuery(std::string query);

private:
	/*
	 * Setup the database's tables
	 */
	bool setupTables();

private:
	sf::Mutex m_mutex;
	MYSQL *m_mysql;
};

#endif /* SQLDATABASE_H_ */
