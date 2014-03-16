#include "Entity.h"
#include "../World/Map.h"

Entity::Entity(sf::Uint16 id, sf::String name, double maxSpeed, Map &map)
: m_id(id), m_name(name), m_maxSpeed(maxSpeed), m_location(map),
  m_velocity(0, 0), m_size(0, 0), m_dead(false)
{

}

Entity::~Entity()
{

}
    
void Entity::update()
{
    m_location += m_velocity;
}
    
sf::Uint16 Entity::getId() const
{
    return m_id;
}
    
sf::String Entity::getName() const
{
    return m_name;
}
    
double Entity::getMaxSpeed() const
{
    return m_maxSpeed;
}
    
void Entity::setMaxSpeed(double newSpeed)
{
    m_maxSpeed = newSpeed;
}
    
Map& Entity::getMap() const
{
    return m_location.getMap();
}

Location Entity::getLocation() const
{
    return m_location;
}

Vector2Dd Entity::getPosition() const
{
    return m_location.getCoordinates();
}
    
void Entity::setPosition(Vector2Dd newPosition)
{
    m_location.setCoordinates(newPosition);
}
    
Vector2Dd Entity::getVelocity() const
{
    return m_velocity;
}
    
void Entity::setVelocity(Vector2Dd newVelocity)
{
    if (newVelocity.getMagnitudeSquare() > (m_maxSpeed * m_maxSpeed))
    {
        m_velocity = (newVelocity / newVelocity.getMagnitude()) * m_maxSpeed;
    }
    else
    {
        m_velocity = newVelocity;
    }
}

bool Entity::isDead() const
{
    return m_dead;
}

Vector2Dd Entity::getSize() const
{
    return m_size;
}
    
sf::Rect<double> Entity::hitbox() const
{
    double x = m_location.getX(), y = m_location.getY();
    double w = m_size.x, h = m_size.y;
    return sf::Rect<double>(x, y, x + w, y + h);
}

void Entity::setSize(Vector2Dd size)
{
    m_size = size;
}
