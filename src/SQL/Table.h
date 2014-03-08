#ifndef TABLE_H_
#define TABLE_H_

#include "SQLDatabase.h"
#include <string>

class Table
{
protected:
    Table(SQLDatabase &database, std::string name);

public:
    virtual ~Table();

protected:
    SQLDatabase &m_database;
    std::string m_name;
};

#endif /* TABLE_H_ */
