#ifndef AI_BASE_h
#define AI_BASE_H

#include "../../../Updatable.h"

//Forward class
class EntityShip;

class AIBase : public Updatable
{
protected:
    AIBase(EntityShip &entity);
public:
    virtual ~AIBase();
    
    virtual void update() = 0;
    
protected:
    EntityShip &m_entity;
};

#endif
