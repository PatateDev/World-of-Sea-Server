#include "Item.h"
#include "Cannon.h"
#include "Cannonballs.h"

ItemList::ItemList()
: m_map()
{
    m_map[CANNONBALLS_WOOD_ID] = new Cannonballs(CANNONBALLS_WOOD_ID, 4, 1, 10);
    m_map[CANNONBALLS_STONE_ID] = new Cannonballs(CANNONBALLS_STONE_ID, 10, 1, 20);
    m_map[CANNONBALLS_COBBLESTONE_ID] = new Cannonballs(CANNONBALLS_COBBLESTONE_ID, 15, 1, 40);
    m_map[CANNONBALLS_METAL_ID] = new Cannonballs(CANNONBALLS_METAL_ID, 8, 1, 80);

    m_map[CANNON_LIGHT_ID] = new Cannon(CANNON_LIGHT_ID, 1, 1, 0.75, 20, 0.5);
    m_map[CANNON_HEAVY_ID] = new Cannon(CANNON_HEAVY_ID, 1, 1, 0.80, 25, 0.45);
}

ItemList::~ItemList()
{
    for (std::map<sf::Uint32, Item*>::iterator it = m_map.begin(); it != m_map.end(); it++)
    {
        delete it->second;
    }
}

const Item* ItemList::getItem(sf::Uint32 id)
{
    return m_map[id];
}

ItemList Item::m_itemList = ItemList();
    
Item::Item(ItemId id, sf::Uint32 weight, sf::Uint32 price)
: m_id(id), m_weight(weight), m_price(price)
{

}

Item::~Item()
{

}
    
ItemId Item::getId() const
{
    return m_id;
}

sf::Uint32 Item::getWeight() const
{
    return m_weight;
}

sf::Uint32 Item::getPrice() const
{
    return m_price;
}

const Item& Item::getItem(ItemId id)
{
    return *m_itemList.getItem(id);
}

