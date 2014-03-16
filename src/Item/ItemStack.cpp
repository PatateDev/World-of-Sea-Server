#include "ItemStack.h"

ItemStack::ItemStack(Item const &item, sf::Uint32 amount)
: m_item(item), m_amount(amount)
{

}
    
ItemStack::~ItemStack()
{

}

const Item& ItemStack::getType() const
{
    return m_item;
}

sf::Uint32 ItemStack::getAmount() const
{
    return m_amount;
}
    
void ItemStack::setAmount(sf::Uint32 amount)
{
    m_amount = amount;
}

sf::Uint32 ItemStack::weight() const
{
    return m_item.getWeight() * m_amount;
}

sf::Uint32 ItemStack::getPrice() const
{
    return m_item.getPrice() * m_amount;
}
    
ItemStack& ItemStack::operator+=(sf::Uint32 const &amount)
{
    m_amount += amount;
    return *this;
}

ItemStack& ItemStack::operator-=(sf::Uint32 const &amount)
{
    if (amount >= m_amount)
        m_amount = 0;
    else
        m_amount-= amount;
    
    return *this;
}

ItemStack& ItemStack::operator=(ItemStack const &right)
{
    if (&right.m_item == &m_item)
    {
        m_amount = right.m_amount;
    }
    
    return *this;
}

ItemStack operator+(ItemStack const &is, sf::Uint32 const &toAdd)
{
    ItemStack stack(is);
    return stack += toAdd;
}

ItemStack operator-(ItemStack const &is, sf::Uint32 const &toRemove)
{
    ItemStack stack(is);
    return stack -= toRemove;
}

bool operator==(ItemStack const &left, ItemStack const &right)
{
    if (&left.getType() == &right.getType())
        return left.getAmount() == right.getAmount();
    else
        return false;
}

bool operator!=(ItemStack const &left, ItemStack const &right)
{
    return !(left == right);
}

