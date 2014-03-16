#include "Location.h"

Location::Location(Map &map, Vector2Dd coord)
: m_map(map), m_coordinates(coord)
{

}

Location::~Location()
{

}
    
Map& Location::getMap() const
{
    return m_map;
}
    
Vector2Dd Location::getCoordinates() const
{
    return m_coordinates;
}

void Location::setCoordinates(Vector2Dd coord)
{
    m_coordinates = coord;
}
    
double Location::getX() const
{
    return m_coordinates.x;
}

double Location::getY() const
{
    return m_coordinates.y;
}

void Location::setX(double x)
{
    m_coordinates.x = x;
}

void Location::setY(double y)
{
    m_coordinates.y = y;
}

Location& operator+=(Location &left, Vector2Dd const &right)
{
    left.m_coordinates += right;
    return left;
}

Location& operator-=(Location &left, Vector2Dd const &right)
{
    left.m_coordinates -= right;
    return left;
}

Location& operator*=(Location &left, double right)
{
    left.m_coordinates *= right;
    return left;
}

Location& operator/=(Location &left, double right)
{
    left.m_coordinates /= right;
    return left;
}

Location operator+(Location const &left, Vector2Dd const &right)
{
    Location result(left);
    return result += right;
}

Location operator-(Location const &left, Vector2Dd const &right)
{
    Location result(left);
    return result -= right;
}

Location operator*(Location const &left, double right)
{
    Location result(left);
    return result *= right;
}

Location operator/(Location const &left, double right)
{
    Location result(left);
    return result /= right;
}

bool operator==(Location const &left, Location const &right)
{
    return &left.getMap() == &right.getMap() && left.getCoordinates() == right.getCoordinates();
}

bool operator!=(Location const &left, Location const &right)
{
    return !(left == right);
}
