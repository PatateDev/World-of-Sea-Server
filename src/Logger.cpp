#include "Logger.h"

Logger& logger = Logger::instance();
const std::string endl = "\n";

Logger::Logger()
: m_mutex(), m_file("world-of-sea-server.log", std::ios::app)
{

}

Logger::~Logger()
{
    m_file.close();
}

void Logger::log(sf::String str)
{
    *(this) << str.toAnsiString();
}

Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

Logger& operator<< (Logger &log, sf::String const &data)
{
    return log << data.toAnsiString();
}

Logger& operator<<(Logger &log, std::string const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, char const *data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Uint8 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Uint16 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Uint32 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Uint64 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Int8 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Int16 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Int32 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, sf::Int64 const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, float const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}

Logger& operator<<(Logger &log, double const &data)
{
    sf::Lock lock(log.m_mutex);
    std::cout << data;
    log.m_file << data;
    return log;
}
