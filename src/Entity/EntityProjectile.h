#ifndef ENTITY_PROJECTILE_H
#define ENTITY_PROJECTILE_H

#include "Entity.h"
#include "../IDamager.h"

class EntityProjectile : public Entity, public IDamager
{
protected:
    EntityProjectile(sf::Uint16 id, sf::String name, double maxSpeed, Entity &shooter);

public:
    virtual ~EntityProjectile();
    
    virtual sf::Uint32 getDamagePoints() const = 0;
    
    Entity& getShooter() const;
    
protected:
    Entity &m_shooter;
};

#endif
