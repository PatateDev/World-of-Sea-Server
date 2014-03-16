#ifndef WORLD_H
#define WORLD_H

#include "../Main.h"
#include "../Updatable.h"
#include "Map.h"
#include <vector>

enum MapId
{
    //TODO
};

class World
{
public:
    World();
    virtual ~World();
    
    virtual void update();
    
    Map* getMap(unsigned int index);
    
private:
    std::vector<Map*> m_maps;
};

#endif
