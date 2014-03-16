#ifndef I_BUYABLE_H
#define I_BUYABLE_H

class IBuyable
{
public:
    virtual sf::Uint32 getPrice() const = 0;
};

#endif
