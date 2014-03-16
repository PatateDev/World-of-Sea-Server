#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "ItemStack.h"
#include <vector>

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();
    
    ItemStack getItemStack(Item const &type) const;
    
    void addItem(Item const &type, sf::Uint32 amount = 1);
    
    void removeAll(Item const &type);
    void removeItem(Item const &type, sf::Uint32 amount);
    
    bool hasItem(Item const &type);
    
private:
    int getIndexOfItem(Item const& type) const;

private:
    std::vector<ItemStack> m_items;
};

#endif
