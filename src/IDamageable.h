#ifndef I_DAMAGEABLE_H
#define I_DAMAGEABLE_H

class IDamager;
class IHealer;

class IDamageable
{
protected:
    IDamageable() {}
    
public:
    virtual sf::Uint32 getMaxHealth() const = 0;
    
    virtual sf::Uint32 getHealth() const = 0;
    
    virtual void setMaxHealth(sf::Uint32 maxHealth) = 0;
    
    virtual void setHealth(sf::Uint32 health) = 0;
    
    virtual void damage(IDamager &damager) = 0;
    
    virtual void heal(IHealer &healer) = 0;
    
    virtual bool isDead() const = 0;
    
    virtual IDamager& getLastDamager() const = 0;
    
    virtual IHealer& getLastHealer() const = 0;
};

#endif
