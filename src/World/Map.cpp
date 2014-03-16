#include "Map.h"
#include "../Entity/Entity.h"

Map::Map(sf::Uint8 id, sf::String name)
: m_id(id), m_name(name),
  m_entities(), m_entityIdsAllowed()
{
    
}

Map::~Map()
{
    while (m_entities.size() > 0)
    {
        Entity *entity = m_entities[m_entities.size() - 1];
        m_entities.pop_back();
        delete entity;
    }
}
    
void Map::update()
{
    for (unsigned int i = 0; i <  m_entities.size(); i++)
    {
        if (m_entities[i]->isDead())
        {
            Entity *dead = m_entities[i];
            removeEntity(dead);
            delete dead;
        }
        else
        {
            m_entities[i]->update();
        }
    }
}
  
sf::Uint8 Map::getId() const
{
    return m_id;
}

sf::String Map::getName() const
{
    return m_name;
}

unsigned int Map::getEntityCount() const
{
    return m_entities.size();
}
    
Entity* Map::getEntity(unsigned int index)
{
    return index >= m_entities.size() ? 0 : m_entities[index];
}
    
bool Map::isEntityAllowed(sf::Uint8 id) const
{
    for (unsigned int i = 0; i < m_entityIdsAllowed.size(); i++)
    {
        if (m_entityIdsAllowed[i] == id)
        {
            return true;
        }
    }
    
    return false;
}

void Map::removeEntity(Entity *entity)
{
    for (unsigned int i = 0; i < m_entities.size(); i++)
    {
        if (m_entities[i] == entity)
        {
            m_entities.erase(m_entities.begin() + i);
        }
    }
}
