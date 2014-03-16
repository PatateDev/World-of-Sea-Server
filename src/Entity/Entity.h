#ifndef ENTITY_H
#define ENTITY_H

class Map;

#include "../Main.h"
#include "../Updatable.h"
#include "../World/Location.h"
#include <SFML/Graphics.hpp> // for sf::Rect

enum EntityId
{
    ENTITY_CANNONBALLS = 10,
    PLAYER_SHIP = 100
};

class Entity : public Updatable
{
protected:
    Entity(sf::Uint16 id, sf::String name, double maxSpeed, Map &map);
    
public:
    virtual ~Entity();
    
    virtual void update();
    
    sf::Uint16 getId() const;
    
    sf::String getName() const;
    
    double getMaxSpeed() const;
    void setMaxSpeed(double newSpeed);
    
    Map& getMap() const;
    
    Location getLocation() const;
    
    Vector2Dd getPosition() const;
    void setPosition(Vector2Dd newPosition);
    
    Vector2Dd getVelocity() const;
    void setVelocity(Vector2Dd newVelocity);
    
    bool isDead() const;
    
    Vector2Dd getSize() const;
    
    sf::Rect<double> hitbox() const;
    
    
protected:
    void setSize(Vector2Dd size);
    
protected:
    const sf::Uint16 m_id;
    const sf::String m_name;
    double m_maxSpeed;
    Location m_location;
    Vector2Dd m_velocity, m_size;
    bool m_dead;
};

#endif
