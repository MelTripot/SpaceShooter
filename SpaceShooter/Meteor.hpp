#ifndef DEF_SHIP
#define DEF_SHIP

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Meteor {      
private: 
    float angle ; 
	float x;
    float y;
    float xa;
    float ya;
	int alive;
    Sprite meteorShape;
    Texture meteorTexture;
    
public:
    // Meteor(); // empty constructor
    Meteor(float angle); // constructor
    ~Meteor(); // Destructor
    void MeteorUpdate();
    Vector2f RandomSpawn();
};

#endif