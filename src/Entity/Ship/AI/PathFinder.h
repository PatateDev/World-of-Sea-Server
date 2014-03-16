#ifndef PATH_FINDER_AI_H
#define PATH_FINDER_AI_H

#include "../../../Updatable.h"
#include "../../../Main.h"
#include "../../../World/Location.h"

//Forward class
class Entity;

class PathFinder : public Updatable
{
public:
    PathFinder(Entity &entity);
    virtual ~PathFinder();
    
    virtual void update();
    
    Entity& getEntity() const;
    
    const Location* getLocationTarget() const;
    
    void setLocationTarget(Location const &loc);
    
    bool hasLocationTarget() const;
    
    Entity* getEntityTarget() const;
    
    void setEntityTarget(Entity &target);
    
    bool hasEntityTarget() const;
    
protected:
    Entity &m_entity;
    Location *m_locationTarget;
    Entity *m_entityTarget;
};

////////////////////////////////
///
/// A Path Finder that will try,
/// first to reach entity target
/// if any, and then position
/// target still if any.
///
////////////////////////////////

#endif
