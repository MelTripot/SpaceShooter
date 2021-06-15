#ifndef DEF_SHIP
#define DEF_SHIP

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>


class Ship {      
private: 
    float r ; 
    int x;
    int y;
    sf::Sprite shape;
    sf::Texture text;
    
public:
    Ship(); // empty constructor
    Ship(float r,int x, int y); // constructor
    ~Ship(); // Destructor sera utile  pour detruire le ship en cas de colision 
    
    void ShipRotation (int rotation);
    
};

#endif