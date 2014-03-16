#include "EntityCannonballs.h"

EntityCannonballs::EntityCannonballs(ItemStack const &balls, sf::Uint32 amount, Entity &shooter, EntityDamageable &target)
: EntityHoming(ENTITY_CANNONBALLS, "cannonballs", 5.0, shooter, target),
  m_balls(balls)
{

}
    
EntityCannonballs::~EntityCannonballs()
{

}
    
const Cannonballs& EntityCannonballs::getCannonballType() const
{
    return static_cast<Cannonballs const&>(m_balls.getType());
}
    
sf::Uint32 EntityCannonballs::getAmount() const
{
    return m_balls.getAmount();
}
    
sf::Uint32 EntityCannonballs::getDamagePoints() const
{
    return getAmount() * getCannonballType().getDamages();
}
