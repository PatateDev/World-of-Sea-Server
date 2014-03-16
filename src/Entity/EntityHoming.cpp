#include "EntityHoming.h"

EntityHoming::EntityHoming(sf::Uint16 id, sf::String name, double maxSpeed, Entity &shooter, EntityDamageable &target)
: EntityProjectile(id, name, maxSpeed, shooter),
  m_target(&target)
{

}

EntityHoming::~EntityHoming()
{

}

void EntityHoming::update()
{    
    if (hitbox().intersects(m_target->hitbox()))
    {
        m_target->damage(*this);
        m_dead = true;
    }
    else
    {
        Vector2Dd pos(m_target->getPosition() + (m_target->getSize() / 2.0));
        setVelocity(Vector2Dd(pos - this->getPosition()));
    }
    
    EntityProjectile::update();
}

EntityDamageable& EntityHoming::getTarget() const
{
    return *m_target;
}

void EntityHoming::setTarget(EntityDamageable &newTarget)
{
    m_target = &newTarget;
}
