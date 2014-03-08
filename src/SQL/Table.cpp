#include "Table.h"


Table::Table(SQLDatabase& database, std::string name)
: m_database(database), m_name(name)
{

}

Table::~Table()
{
}

