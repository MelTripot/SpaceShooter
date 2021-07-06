#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Meteor.hpp>
#include <cmath>

using namespace std;
using namespace sf;

constexpr float pi = 3.141592654 ;
Meteor::Meteor(const float _angle): angle(_angle)
{
	
	// this->x = 800;
    // this->y = 450;
	Vector2f SpawnProjectile = Vector2f(x , y );
	this->meteorTexture.loadFromFile("Asset/laserBlue01.png");
	this->meteorShape.setTexture(this->meteorTexture);
	this->meteorShape.setPosition(SpawnProjectile);
	this->meteorShape.setRotation(_angle);
					
	float radient = ((_angle+270)*pi/180);
	xa = 1.5* cos(radient);
	ya = 1.5* sin(radient);
	
	this->alive = 1;
	
}

Meteor::~Meteor(){}


void Meteor::MeteorUpdate()
{
	// ce que fait le laser a chaque frame
}

Vector2f Meteor::RandomSpawn(){
    int choice = rand() %1 ;
    
    if (choice == 0){
        x  = (-rand() % 21);
    }
    else
    {
        x = (rand() % 1621 + 1600);
    }
    choice = rand() %1;
    if (choice == 0){
        y  = (-rand() % 21);
    }
    else
    {
        x = (rand() % 921 + 920);
    }
    
    return Vector2f(x,y);
}
