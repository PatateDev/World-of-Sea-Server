#ifndef MAP_H
#define MAP_H

class Entity;

#include "../Main.h"
#include "../Updatable.h"
#include <vector>

class Map : public Updatable
{
public:
    Map(sf::Uint8 id, sf::String name);
    virtual ~Map();
    
    virtual void update();
    
    sf::Uint8 getId() const;
    
    sf::String getName() const;
    
    unsigned int getEntityCount() const;
    
    Entity* getEntity(unsigned int index);
    
    bool isEntityAllowed(sf::Uint8 id) const;
    
protected:
    void removeEntity(Entity *entity);

protected:
    const sf::Uint8 m_id;
    const sf::String m_name;
    std::vector<Entity*> m_entities;
    std::vector<sf::Uint8> m_entityIdsAllowed;
};

#endif
