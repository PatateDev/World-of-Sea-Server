#include "Design.h"

DesignList::DesignList()
: m_designs()
{
    m_designs[DES_DEFAULT] = new Design(DES_DEFAULT, "default", 0);
}

DesignList::~DesignList()
{
    for (std::map<DesignId, Design*>::iterator it = m_designs.begin(); it != m_designs.end(); it++)
    {
        delete it->second;
    }
}

const Design* DesignList::getDesign(DesignId id)
{
    return m_designs[id];
}

DesignList Design::m_designList = DesignList();

Design::Design(DesignId id, sf::String name, sf::Uint32 price)
: m_id(id), m_name(name), m_price(price)
{

}

Design::~Design()
{

}

DesignId Design::getId() const
{
    return m_id;
}
    
sf::String Design::getName() const
{
    return m_name;
}

sf::Uint32 Design::getPrice() const
{
    return m_price;
}

const Design& Design::getDesign(DesignId id)
{
    return *m_designList.getDesign(id);
}
