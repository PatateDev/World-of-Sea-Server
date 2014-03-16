#include "EntityDamageable.h"

EntityDamageable::EntityDamageable(sf::Uint16 id, sf::String name, double maxSpeed, sf::Uint32 maxHealth, Map &map)
: Entity(id, name, maxSpeed, map),
  m_maxHealth(maxHealth), m_health(maxHealth),
  m_lastDamager(0), m_lastHealer(0)
{

}
    
EntityDamageable::~EntityDamageable()
{

}

sf::Uint32 EntityDamageable::getMaxHealth() const
{
    return m_maxHealth;
}
    
sf::Uint32 EntityDamageable::getHealth() const
{
    return m_health;
}
    
void EntityDamageable::setMaxHealth(sf::Uint32 maxHealth)
{
    m_maxHealth = maxHealth;
}
    
void EntityDamageable::setHealth(sf::Uint32 health)
{
    if (health <= m_maxHealth)
    {
        m_health = health;
    }
    else
    {
        m_health = m_maxHealth;
    }
    
    m_dead = (m_health == 0);
}
    
void EntityDamageable::damage(IDamager &damager)
{
    sf::Uint32 damages = damager.getDamagePoints();
    setHealth(damages >= m_health ? 0 : m_health - damages);
    m_lastDamager = &damager;
}
    
void EntityDamageable::heal(IHealer &healer)
{
    sf::Uint32 heal = healer.getHealPoints();
    setHealth(heal);
    m_lastHealer = &healer;
}
    
IDamager& EntityDamageable::getLastDamager() const
{
    return *m_lastDamager;
}
    
IHealer& EntityDamageable::getLastHealer() const
{
    return *m_lastHealer;
}
