#include "Player.h"
#include "Entity/Ship/PlayerShip.h"

Player::Player(sf::String pseudo, sf::String session, sf::Uint32 golds)
: m_pseudo(pseudo), m_session(session), m_golds(golds), m_ship(0),
  m_inventory()
{
    //TODO Retrieve in SQL
    m_design = DES_DEFAULT;
}
    
Player::~Player()
{

}
    
sf::String Player::getPseudo() const
{
    return m_pseudo;
}
    
sf::String Player::getSession() const
{
    return m_session;
}
    
sf::Uint32 Player::getGolds() const
{
    return m_golds;
}
    
PlayerShip* Player::getShip() const
{
    return m_ship;
}

Inventory& Player::getInventory()
{
    return m_inventory;
}

DesignId Player::getDesign() const
{
    return m_design;
}
    
void Player::setDesign(DesignId design)
{
    m_design = design;
}
