#include "GameServer.h"
#include <iostream>
#include "Main.h"

GameServer::GameServer(SQLDatabase &db)
: m_users(db), m_listener(), m_clients(),
  m_selector(), m_running(false),
  m_ticksPerSecond(WOS_UPDATE_RATE)
{

}

GameServer::~GameServer()
{

}

void GameServer::run()
{
    if (m_listener.listen(WOS_GAME_PORT) != sf::Socket::Done)
    {
        logger << "Can't listening on port " << WOS_GAME_PORT << endl;
        logger << "Please check your firewall, ";
        logger << "or if the port is already listening by another software" << endl;
    }
    else
    {
        m_running = true;
        m_selector.add(m_listener);
        sf::Time updateDelta(sf::seconds(1 / (double) WOS_UPDATE_RATE));
        sf::Clock updateClock;
        sf::Time lastPoll(updateClock.getElapsedTime());
        int updates(0);
        sf::Time nextUpdate(updateClock.getElapsedTime());
        
        while (m_running)
        {
            if (nextUpdate <= updateClock.getElapsedTime())
            {
                sf::Time currentTime(updateClock.getElapsedTime());
                while (nextUpdate <= currentTime)
                {
                    checkSockets();
                    
                    updateLogic();
                    
                    updates++;
                    
                    sf::Time deltaPoll(currentTime - lastPoll);
                    if (deltaPoll >= sf::seconds(5))
                    {
                        m_ticksPerSecond = updates/(double) deltaPoll.asSeconds();
                        
                        if (m_ticksPerSecond < 17.5)
                        {
                            logger << "It seems that the server is slow (" << m_ticksPerSecond << " ticks per second)";
                            logger << ", perhaps the server is overloaded ?" << endl;
                        }
                        
                        updates = 0;
                        lastPoll = updateClock.getElapsedTime();
                    }
                    
                    nextUpdate += updateDelta;
                }
            }
            else
            {
                sf::Time sleepTime(nextUpdate - updateClock.getElapsedTime());
                sf::sleep(sleepTime);
            }
        }
    }
}

void GameServer::stop()
{
    logger << "Stopping game server" << endl;
    m_running = false;
}

void GameServer::checkSockets()
{

}

void GameServer::updateLogic()
{
    //TODO
}

double GameServer::getTicksPerSecond() const
{
    return m_ticksPerSecond;
}