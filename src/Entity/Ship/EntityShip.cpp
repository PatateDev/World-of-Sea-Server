#include "EntityShip.h"
#include "../../Item/Cannon.h"
#include "../../Item/Cannonballs.h"

EntityShip::EntityShip(sf::Uint16 id, sf::String name, double maxSpeed, sf::Uint32 maxHealth, Map &map, Design const &design)
: EntityDamageable(id, name, maxSpeed, maxHealth, map),
  m_design(&design),
  m_cannons(Item::getItem(CANNON_LIGHT_ID)), m_munitions(Item::getItem(CANNONBALLS_WOOD_ID)),
  m_pathFinder(*this)
{

}
    
EntityShip::~EntityShip()
{

}

void EntityShip::update()
{
    EntityDamageable::update();
    
    m_pathFinder.update();
}

ItemStack EntityShip::getCannons() const
{
    return m_cannons;
}

void EntityShip::setCannons(ItemStack cannons)
{
    if (dynamic_cast<Cannon const*>(&cannons.getType()))
    {
        m_cannons = cannons;
    }
    else
    {
        logger << "Warning : trying to set non-cannon item as cannon : " << cannons.getType().getId() << endl;
    }
}
    
ItemStack EntityShip::getMunitions() const
{
    return m_munitions;
}

void EntityShip::setMunitions(ItemStack munitions)
{
    if (dynamic_cast<Cannonballs const*>(&munitions.getType()))
    {
        m_munitions = munitions;
    }
    else
    {
        logger << "Warning : trying to set non-cannonballs item as cannonballs : " << munitions.getType().getId() << endl;
    }
}
    
const Design& EntityShip::getDesign() const
{
    return *m_design;
}

void EntityShip::setDesign(Design const &design)
{
    m_design = &design;
}
    
PathFinder& EntityShip::getPathFinder()
{
    return m_pathFinder;
}
