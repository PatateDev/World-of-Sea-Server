#include "PathFinder.h"
#include "../../Entity.h"

PathFinder::PathFinder(Entity &entity)
: m_entity(entity)
{

}

PathFinder::~PathFinder()
{
    if (m_locationTarget)
    {
        delete m_locationTarget;
        m_locationTarget = 0;
    }
}
    
void PathFinder::update()
{
    if (m_entityTarget)
    {
        //TODO Track entity target
    }
    else if (m_locationTarget)
    {
        Vector2Dd direction(m_locationTarget->getCoordinates() - m_entity.getPosition());
        
        //TODO Check if the distance is lower than the velocity, and reduce it if so
        
        if (!direction.colinearTo(m_entity.getVelocity()))
        {
            m_entity.setVelocity(direction);
        }
        else if (direction == Vector2Dd(0, 0))
        {
            delete m_locationTarget;
            m_locationTarget = 0;            
        }
    }
}
    
Entity& PathFinder::getEntity() const
{
    return m_entity;
}
    
const Location* PathFinder::getLocationTarget() const
{
    return m_locationTarget;
}
    
void PathFinder::setLocationTarget(Location const &loc)
{
    if (m_locationTarget)
    {
        delete m_locationTarget;
        m_locationTarget = 0;
    }
    
    m_locationTarget = new Location(loc);
}
    
bool PathFinder::hasLocationTarget() const
{
    return getLocationTarget() != 0;
}
    
Entity* PathFinder::getEntityTarget() const
{
    return m_entityTarget;
}
    
void PathFinder::setEntityTarget(Entity &target)
{   
    m_entityTarget = &target; 
}
    
bool PathFinder::hasEntityTarget() const
{
    return getEntityTarget() != 0;
}
