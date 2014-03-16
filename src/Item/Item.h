#ifndef ITEM_H
#define ITEM_H

#include "../Main.h"

enum ItemId
{
    // Cannonballs
    CANNONBALLS_WOOD_ID = 100,
    CANNONBALLS_STONE_ID = 101,
    CANNONBALLS_COBBLESTONE_ID = 102,
    CANNONBALLS_METAL_ID = 103,
    
    // Cannons
    CANNON_LIGHT_ID = 200,
    CANNON_HEAVY_ID = 201
};

// Forward class
class Item;

#include <map>

class ItemList
{
public:
    ItemList();
    
    virtual ~ItemList();
    
    const Item* getItem(sf::Uint32 id);

protected:
    std::map<sf::Uint32, Item*> m_map;
};

class Item
{
protected:
    Item(ItemId id, sf::Uint32 weight, sf::Uint32 price);

public:
    virtual ~Item();
    
    ItemId getId() const;
    
    sf::Uint32 getWeight() const;
    
    sf::Uint32 getPrice() const;
    
    static const Item& getItem(ItemId id);
    
protected:
    const ItemId m_id;
    sf::Uint32 m_weight;
    sf::Uint32 m_price;
    static ItemList m_itemList;
};

#endif
