#ifndef ENTITY_DAMAGEABLE_H
#define ENTITY_DAMAGEABLE_H

#include "Entity.h"
#include "../IDamageable.h"
#include "../IDamager.h"
#include "../IHealer.h"

class EntityDamageable : public Entity, public IDamageable
{
protected:
    EntityDamageable(sf::Uint16 id, sf::String name, double maxSpeed, sf::Uint32 maxHealth, Map &map);
    
public:
    virtual ~EntityDamageable();
    
    sf::Uint32 getMaxHealth() const;
    
    sf::Uint32 getHealth() const;
    
    void setMaxHealth(sf::Uint32 maxHealth);
    
    void setHealth(sf::Uint32 health);
    
    void damage(IDamager &damager);
    
    void heal(IHealer &healer);
    
    IDamager& getLastDamager() const;
    
    IHealer& getLastHealer() const;
    
protected:
    sf::Uint32 m_maxHealth;
    sf::Uint32 m_health;
    IDamager *m_lastDamager;
    IHealer *m_lastHealer;
};

#endif
