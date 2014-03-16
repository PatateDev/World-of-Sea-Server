#include "EntityProjectile.h"

EntityProjectile::EntityProjectile(sf::Uint16 id, sf::String name, double maxSpeed, Entity &shooter)
: Entity(id, name, maxSpeed, shooter.getMap()),
  m_shooter(shooter)
{

}

EntityProjectile::~EntityProjectile()
{

}

Entity& EntityProjectile::getShooter() const
{
    return m_shooter;
}
