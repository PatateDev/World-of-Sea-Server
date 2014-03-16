#ifndef I_DAMAGER_H
#define I_DAMAGER_H

class IDamager
{
protected:
    IDamager() {}
    
public:
    virtual sf::Uint32 getDamagePoints() const = 0;
};

#endif
