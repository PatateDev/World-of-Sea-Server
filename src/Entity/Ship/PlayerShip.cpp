#include "PlayerShip.h"

PlayerShip::PlayerShip(Map &map, Player &player)
: EntityShip(PLAYER_SHIP, "player_ship", 3.5, 1000, map, Design::getDesign(player.getDesign())),
  m_player(player)
{

}

PlayerShip::~PlayerShip()
{

}
    
void PlayerShip::update()
{
    EntityShip::update();
}
    
Player& PlayerShip::getPlayer()
{
    return m_player;
}
    
sf::String PlayerShip::getPlayerName() const
{
    return m_player.getPseudo();
}
