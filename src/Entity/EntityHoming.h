 #ifndef ENTITY_HOMING_H
 #define ENTITY_HOMING_H
 
 #include "EntityProjectile.h"
 #include "EntityDamageable.h"

class EntityHoming : public EntityProjectile
{
protected:
    EntityHoming(sf::Uint16 id, sf::String name, double maxSpeed, Entity &shooter, EntityDamageable &target);
    
public:
    virtual ~EntityHoming();
    
    EntityDamageable& getTarget() const;
    
    void setTarget(EntityDamageable &newTarget);
    
    virtual sf::Uint32 getDamagePoints() const = 0;
    
    virtual void update();
    
protected:
    EntityDamageable *m_target;
};
 
 #endif
