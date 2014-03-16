#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "EntityShip.h"
#include "../../Player.h"

class PlayerShip : public EntityShip
{
public:
    PlayerShip(Map &map, Player &player);
    virtual ~PlayerShip();
    
    virtual void update();
    
    Player& getPlayer();
    
    sf::String getPlayerName() const;
    
protected:
    Player &m_player;
};

#endif
