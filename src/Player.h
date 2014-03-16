#ifndef PLAYER_H
#define PLAYER_H

// Forward class
class PlayerShip;

#include "Main.h"
#include <vector>
#include "Item/Inventory.h"
#include "Entity/Ship/Design.h"

class Player
{
public:
    Player(sf::String pseudo, sf::String session, sf::Uint32 golds);
    
    virtual ~Player();
    
    sf::String getPseudo() const;
    
    sf::String getSession() const;
    
    sf::Uint32 getGolds() const;
    
    PlayerShip* getShip() const;
    
    Inventory& getInventory();
    
    DesignId getDesign() const;
    
    void setDesign(DesignId design);

private:
    const sf::String m_pseudo, m_session;
    sf::Uint32 m_golds;
    //TODO SQL table
    PlayerShip *m_ship;
    Inventory m_inventory;
    DesignId m_design;

friend class PlayerShip;
};

#endif
