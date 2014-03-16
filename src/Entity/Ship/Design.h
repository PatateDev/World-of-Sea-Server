#ifndef DESIGN_H
#define DESIGN_H

#include "../../Main.h"
#include "../../IBuyable.h"

enum DesignId
{
    DES_DEFAULT = 0
};

#include <map>

//Forward class
class Design;

class DesignList
{
public:
    DesignList();
    virtual ~DesignList();
    
    const Design* getDesign(DesignId id);
    
private:
    std::map<DesignId, Design*> m_designs;
};

class Design : public IBuyable
{
public:
    Design(DesignId id, sf::String name, sf::Uint32 price);

    virtual ~Design();

    DesignId getId() const;
    
    sf::String getName() const;

    virtual sf::Uint32 getPrice() const;
    
    static const Design& getDesign(DesignId id);

private:
    const DesignId m_id;
    sf::String m_name;
    sf::Uint32 m_price;
    static DesignList m_designList;
};

#endif
