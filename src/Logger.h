#ifndef LOGGER_H
#define LOGGER_H

#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <fstream>

class Logger
{
private:
    Logger();
public:
    virtual ~Logger();
    
    static Logger& instance();
    
    void log(sf::String str);
    
    // Operators
    friend Logger& operator<<(Logger &log, sf::String const &data);
    friend Logger& operator<<(Logger &log, std::string const &data);
    friend Logger& operator<<(Logger &log, const char *data);
    friend Logger& operator<<(Logger &log, sf::Uint8 const &data);
    friend Logger& operator<<(Logger &log, sf::Uint16 const &data);
    friend Logger& operator<<(Logger &log, sf::Uint32 const &data);
    friend Logger& operator<<(Logger &log, sf::Uint64 const &data);
    friend Logger& operator<<(Logger &log, sf::Int8 const &data);
    friend Logger& operator<<(Logger &log, sf::Int16 const &data);
    friend Logger& operator<<(Logger &log, sf::Int32 const &data);
    friend Logger& operator<<(Logger &log, sf::Int64 const &data);
    friend Logger& operator<<(Logger &log, float const &data);
    friend Logger& operator<<(Logger &log, double const &data);

private:
    sf::Mutex m_mutex;
    std::ofstream m_file;
};

Logger& operator<<(Logger &log, sf::String const &data);
Logger& operator<<(Logger &log, std::string const &data);
Logger& operator<<(Logger &log, const char *data);
Logger& operator<<(Logger &log, sf::Uint8 const &data);
Logger& operator<<(Logger &log, sf::Uint16 const &data);
Logger& operator<<(Logger &log, sf::Uint32 const &data);
Logger& operator<<(Logger &log, sf::Uint64 const &data);
Logger& operator<<(Logger &log, sf::Int8 const &data);
Logger& operator<<(Logger &log, sf::Int16 const &data);
Logger& operator<<(Logger &log, sf::Int32 const &data);
Logger& operator<<(Logger &log, sf::Int64 const &data);
Logger& operator<<(Logger &log, float const &data);
Logger& operator<<(Logger &log, double const &data);

extern const std::string endl;
extern Logger& logger;

#endif
