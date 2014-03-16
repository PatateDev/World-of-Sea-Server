#ifndef LOCATION_H
#define LOCATION_H

#include "../Main.h"
#include "../Maths/Vector2D.h"
#include "Map.h"

class Location
{
public:
    Location(Map &map, Vector2Dd coord = Vector2Dd());
    virtual ~Location();
    
    Map& getMap() const;
    
    Vector2Dd getCoordinates() const;
    void setCoordinates(Vector2Dd coord);
    
    double getX() const;
    double getY() const;
    
    void setX(double x);
    void setY(double y);
    
    friend Location& operator+=(Location &left, Vector2Dd const &right);
    friend Location& operator-=(Location &left, Vector2Dd const &right);
    friend Location& operator*=(Location &left, double right);
    friend Location& operator/=(Location &left, double right);

private:
    Map &m_map;
    Vector2Dd m_coordinates;
};

Location& operator+=(Location &left, Vector2Dd const &right);
Location& operator-=(Location &left, Vector2Dd const &right);
Location& operator*=(Location &left, double right);
Location& operator/=(Location &left, double right);

Location operator+(Location const &left, Vector2Dd const &right);
Location operator-(Location const &left, Vector2Dd const &right);
Location operator*(Location const &left, double right);
Location operator/(Location const &left, double right);

bool operator==(Location const &left, Location const &right);
bool operator!=(Location const &left, Location const &right);

#endif
