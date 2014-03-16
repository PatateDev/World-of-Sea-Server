#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <SFML/System.hpp>
#include <cmath>

template <typename T>
class Vector2D : public sf::Vector2<T>
{
public:
    Vector2D()
    : sf::Vector2<T>()
    {
    
    }
    
    Vector2D(T x, T y)
    : sf::Vector2<T>(x, y)
    {
    
    }
    
    explicit Vector2D(sf::Vector2<T> const &vector)
    : sf::Vector2<T>(vector.x, vector.y)
    {
    
    }
    
    T getMagnitudeSquare() const
    {
        return pow(this->x, 2) + pow(this->y, 2);
    }
    
    T getMagnitude() const
    {
        return sqrt(getMagnitudeSquare());
    }
    
    T getDotProduct(Vector2D const &vector) const
    {
        return this->x * vector.x + this->y + vector.y;
    }
    
    bool colinearTo(Vector2D const &vector) const
    {
        return this->x * vector.x == this->y * vector.y;
    }
    
    bool orthogonalTo(Vector2D const &vector) const
    {
        return getDotProduct(vector) == 0;
    }
    
    Vector2D& operator=(Vector2D const &vector)
    {
        this->x = vector.x;
        this->y = vector.y;
        return *this;
    }
    
    Vector2D& operator=(sf::Vector2<T> const &vector)
    {
        this->x = vector.x;
        this->y = vector.y;
        return *this;
    } 
    
};

typedef Vector2D<double> Vector2Dd;

#endif
