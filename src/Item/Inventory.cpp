#include "Inventory.h"

Inventory::Inventory()
: m_items()
{

}

Inventory::~Inventory()
{

}
    
ItemStack Inventory::getItemStack(Item const &type) const
{
    for (int i = 0; i < m_items.size(); i++)
    {
        if (&type == &m_items[i].getType())
        {
            return m_items[i];
        }
    }
    
    return ItemStack(type, 0);
}

int Inventory::getIndexOfItem(Item const& type) const
{
    for (int i = 0; i < m_items.size(); i++)
    {
        if (&type == &m_items[i].getType())
        {
            return i;
        }
    }
    
    return -1;
}
    
void Inventory::addItem(Item const &type, sf::Uint32 amount)
{
    int i = getIndexOfItem(type);
    ItemStack is = getItemStack(type) + amount;
       
    if (i < 0)
        m_items.push_back(is);
    else
        m_items[i] = is;
}

void Inventory::removeAll(Item const &type)
{
    return removeItem(type, getItemStack(type).getAmount());
}

void Inventory::removeItem(Item const &type, sf::Uint32 amount)
{
    ItemStack is = getItemStack(type);
    
    if (is.getAmount() != 0)
    {
        int i = getIndexOfItem(type);
        m_items[i] = is - amount;
    }
}
    
bool Inventory::hasItem(Item const &type)
{
    return getItemStack(type).getAmount() != 0;
}
