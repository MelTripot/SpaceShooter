#include "Laser.hpp"
#include <SFML/Graphics.hpp>
// nécessaire pour le calcul de la trajectoire du laser 
#include <cmath>

using namespace std;

// Laser::Laser(){}

Laser::Laser(const float _angle): angle(_angle), x(800) , y(450)
{
	
	// this->x = 800;
    // this->y = 450;
	Vector2f SpawnProjectile = Vector2f(x , y );
	this->laserTexture.loadFromFile("Asset/laserBlue01.png");
	this->laserShape.setTexture(this->laserShape);
	this->laserShape.setPosition(SpawnProjectile);
	this->laserShape.setRotation(_angle);
					
	float radient = ((_angle+270)*M_PI/180);
	xa = 1.5* cos(radient);
	ya = 1.5* sin(radient);
	
	this->alive = 1;
	
}

Laser::~Laser(){}


Laser::LaserUpdate()
{
	// ce que fait le laser à chaque frame
	proj.move(this->xa,this->ya);
	this->x =+ this->xa;
	this->y =+ this->ya;
	// si le projectile sort du cadre, le faire disparaitre et reassigner sa position de départ  
	if (y < -30 || y > 930 || x < -30 || x > 1630)
	{
		// gerer la desctruction
		this->alive = 0;
	}

}
