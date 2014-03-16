#ifndef CANNON_H
#define CANNON_H

#include "Item.h"

enum CannonType
{

};

class Cannon : public Item
{
public:
    Cannon(ItemId id, sf::Uint32 weight, sf::Uint32 price, double precision, double range, double cadence);
    ~Cannon();
    
    double getPrecision() const;
    
    double getRange() const;
    
    double getCadence() const;
    
protected:
     double m_precision, m_range, m_cadence;
};

#endif
