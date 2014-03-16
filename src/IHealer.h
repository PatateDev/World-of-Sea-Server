#ifndef I_HEALER_H
#define I_HEALER_H

class IHealer
{
protected:
    IHealer() {}
    
public:
    virtual sf::Uint32 getHealPoints() const = 0;
};

#endif
