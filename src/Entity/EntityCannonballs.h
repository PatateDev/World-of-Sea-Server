#ifndef ENTITY_CANONBALLS_H
#define ENTITY_CANONBALLS_H

#include "EntityHoming.h"
#include "../Item/Cannonballs.h"
#include "../Item/ItemStack.h"

class EntityCannonballs : public EntityHoming
{
public:
    EntityCannonballs(ItemStack const &balls, sf::Uint32 amount, Entity &shooter, EntityDamageable &target);
    
    virtual ~EntityCannonballs();
    
    const Cannonballs& getCannonballType() const;
    
    sf::Uint32 getAmount() const;
    
    virtual sf::Uint32 getDamagePoints() const;
        
protected:
    ItemStack const &m_balls;
};

#endif
