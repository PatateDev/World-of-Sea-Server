#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#include "Item.h"
#include "../IBuyable.h"

class ItemStack : public IBuyable
{
public:
    ItemStack(Item const &item, sf::Uint32 amount = 1);
    
    virtual ~ItemStack();
    
    const Item& getType() const;
    
    sf::Uint32 getAmount() const;
    
    void setAmount(sf::Uint32 amount);
    
    sf::Uint32 weight() const;
    virtual sf::Uint32 getPrice() const;
    
    ItemStack& operator+=(sf::Uint32 const &amount);
    ItemStack& operator-=(sf::Uint32 const &amount);
    
    ItemStack& operator=(ItemStack const &right); 

private:
    Item const &m_item;
    sf::Uint32 m_amount;
};

ItemStack operator+(ItemStack const &is, sf::Uint32 const &toAdd);
ItemStack operator-(ItemStack const &is, sf::Uint32 const &toRemove);

bool operator==(ItemStack const &left, ItemStack const &right);
bool operator!=(ItemStack const &left, ItemStack const &right);

#endif
