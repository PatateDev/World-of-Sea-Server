#ifndef GAME_SERVER_H
#define GAME_SERVER_H

#include <map>
#include <SFML/Network.hpp>
#include "SQL/SQLDatabase.h"
#include "SQL/UsersTable.h"
#include "World/World.h"
#include "Player.h"

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
    
    Player* getPlayer(sf::String name);
    
    bool isOnline(sf::String name);
    
private:
    void checkSockets();
    
    void updateLogic();
    
    void addPlayer(sf::String username, sf::String session, sf::TcpSocket *socket);
    
    void removePlayer(sf::String username);
    
private:
     UsersTable m_users;
     sf::TcpListener m_listener;
     std::map<Player*, sf::TcpSocket*> m_clients;
     sf::SocketSelector m_selector;
     bool m_running;
     double m_ticksPerSecond;
     World m_world;
};

#endif
