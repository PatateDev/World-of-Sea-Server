#ifndef ITEM_DAMAGER_H
#define ITEM_DAMAGER_H

#include "Item.h"

class ItemDamager : public Item
{
protected:
    ItemDamager(ItemId id, sf::Uint32 weight, sf::Uint32 price, sf::Uint32 damages);
    
public:
    sf::Uint32 getDamages() const;
    
protected:
    sf::Uint32 m_damages;
};

#endif
