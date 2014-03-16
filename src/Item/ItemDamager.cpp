#include "ItemDamager.h"

ItemDamager::ItemDamager(ItemId id, sf::Uint32 weight, sf::Uint32 price, sf::Uint32 damages)
: Item(id, weight, price),
  m_damages(damages)
{

}
    
sf::Uint32 ItemDamager::getDamages() const
{
    return m_damages;
}

