 #ifndef ENTITY_SHIP_H
 #define ENTITY_SHIP_H
 
 #include "../EntityDamageable.h"
 #include "../../Item/ItemStack.h"
 #include "Design.h"
 #include "AI/PathFinder.h"
 
 class EntityShip : public EntityDamageable
 {
 protected:
    EntityShip(sf::Uint16 id, sf::String name, double maxSpeed, sf::Uint32 maxHealth, Map &map, Design const &design = Design::getDesign(DES_DEFAULT));
    
public:
    virtual ~EntityShip();
    
    virtual void update();
    
    ItemStack getCannons() const;
    void setCannons(ItemStack cannons);
    
    ItemStack getMunitions() const;
    void setMunitions(ItemStack munitions);
    
    const Design& getDesign() const;
    void setDesign(Design const &design);
    
    PathFinder& getPathFinder();
    
protected:
    const Design *m_design;
    ItemStack m_cannons;
    ItemStack m_munitions;
    PathFinder m_pathFinder;
};
 
 #endif
