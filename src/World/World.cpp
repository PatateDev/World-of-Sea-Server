#include "World.h"

World::World()
: m_maps()
{
    //TODO m_maps.push_back();
}

World::~World()
{
    while (m_maps.size() > 0)
    {
        Map *map = m_maps[m_maps.size() - 1];
        m_maps.pop_back();
        delete map;
    }
}

void World::update()
{
    for (unsigned int i = 0; i < m_maps.size(); i++)
    {
        m_maps[i]->update();
    }
}

Map* World::getMap(unsigned int index)
{
    return index >= m_maps.size() ? 0 : m_maps[index];
}
