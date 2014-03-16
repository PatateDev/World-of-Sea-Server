#ifndef CANNONBALLS_H
#define CANNONBALLS_H

#include "ItemDamager.h"

class Cannonballs : public ItemDamager
{
public:
    Cannonballs(ItemId id, sf::Uint32 weight, sf::Uint32 price, sf::Uint32 damages);
    ~Cannonballs();
};

#endif
