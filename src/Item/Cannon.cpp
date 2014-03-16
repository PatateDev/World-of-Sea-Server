#include "Cannon.h"

Cannon::Cannon(ItemId id, sf::Uint32 weight, sf::Uint32 price, double precision, double range, double cadence)
: Item(id, weight, price),
  m_precision(precision), m_range(range), m_cadence(cadence)
{

}

Cannon::~Cannon()
{

}
    
double Cannon::getPrecision() const
{
    return m_precision;
}
    
double Cannon::getRange() const
{
    return m_range;
}
    
double Cannon::getCadence() const
{
    return m_cadence;
}
