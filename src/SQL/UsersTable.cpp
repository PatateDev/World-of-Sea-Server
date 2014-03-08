#include "UsersTable.h"
#include <memory> //std::auto_ptr

UsersTable::UsersTable(SQLDatabase& db)
: Table(db, "users")
{
    m_statement = db.createStatement();
    m_getStatement = db.prepareStatement("SELECT * FROM users WHERE username=?");
    m_setPasswordStatement = db.prepareStatement("UPDATE users SET password=? WHERE username=?");
    m_setIpStatement = db.prepareStatement("UPDATE users SET ip=? WHERE username=?");
    m_setSessionStatement = db.prepareStatement("UPDATE users SET session=? WHERE username=?");
}

UsersTable::~UsersTable()
{
    delete m_statement;
    delete m_getStatement;
    delete m_setPasswordStatement;
    delete m_setIpStatement;
    delete m_setSessionStatement;
}

std::string UsersTable::getPassword(std::string username) const
{
    std::string password("");

    try
    {
        m_getStatement->setString(1, username);
        std::auto_ptr<sql::ResultSet> set(m_getStatement->executeQuery());

        if (set.get()->next())
        {
            password = set.get()->getString("password");
        }
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    return password;
}

sf::IpAddress UsersTable::getIP(std::string username) const
{
    sf::IpAddress ip;

    try
    {
        m_getStatement->setString(1, username);
        std::auto_ptr<sql::ResultSet> set(m_getStatement->executeQuery());

        if (set.get()->next())
        {
            ip = sf::IpAddress(set.get()->getUInt("ip"));
        }
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    return ip;
}

std::string UsersTable::getSession(std::string username) const
{
    std::string session("");

    try
    {
        m_getStatement->setString(1, username);
        std::auto_ptr<sql::ResultSet> set(m_getStatement->executeQuery());

        if (set.get()->next())
        {
            session = set.get()->getString("session");
        }
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    return session;
}

void UsersTable::setPassword(std::string username, std::string passwordMD5)
{
    try
    {
        m_setPasswordStatement->setString(1, passwordMD5);
        m_setPasswordStatement->setString(2, username);

        m_setPasswordStatement->execute();
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void UsersTable::setIP(std::string username, sf::IpAddress address)
{
    try
    {
        m_setIpStatement->setUInt(1, address.toInteger());
        m_setIpStatement->setString(2, username);

        m_setIpStatement->execute();
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void UsersTable::setSession(std::string username, std::string session)
{
    try
    {
        m_setSessionStatement->setString(1, session);
        m_setSessionStatement->setString(2, username);

        m_setSessionStatement->execute();
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

std::vector<std::string> UsersTable::getUsers() const
{
    std::vector<std::string> v;

    try
    {
        std::auto_ptr<sql::ResultSet> set(m_statement->executeQuery("SELECT * FROM users"));

        while (set.get()->next())
        {
            v.push_back(set.get()->getString("username"));
        }
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

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
