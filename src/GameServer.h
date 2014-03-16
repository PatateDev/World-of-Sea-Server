#ifndef GAME_SERVER_H
#define GAME_SERVER_H

#include <list>
#include <SFML/Network.hpp>
#include "SQL/SQLDatabase.h"
#include "SQL/UsersTable.h"

#define WOS_UPDATE_RATE 20

enum WosPacketId // Stored as sf::Uint16
{

};

class GameServer
{
public:
    GameServer(SQLDatabase &db);
    
    virtual ~GameServer();
    
    void run();
    
    void stop();
    
    double getTicksPerSecond() const;
    
private:
    void checkSockets();
    
    void updateLogic();
    
private:
     UsersTable m_users;
     sf::TcpListener m_listener;
     std::list<sf::TcpSocket*> m_clients;
     sf::SocketSelector m_selector;
     bool m_running;
     double m_ticksPerSecond;
};

#endif
