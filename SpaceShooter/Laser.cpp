#include "Laser.hpp"
#include <SFML/Graphics.hpp>
// nécessaire pour le calcul de la trajectoire du laser 
#include <cmath>

using namespace std;

// Laser::Laser(){}

Laser::Laser(float _angle): angle(_angle), x(800) , y(450)
{
	
	// this->x = 800;
    // this->y = 450;
	Vector2f SpawnProjectile = Vector2f(x , y );
	this->laserTexture.loadFromFile("Asset/laserBlue01.png");
	this->laserShape.setTexture(this->laserTexture);
	this->laserShape.setPosition(SpawnProjectile);
	this->laserShape.setRotation(_angle);
					
	float radient = ((_angle+270)*3.141592654/180);
	xa = 1* cos(radient);
	ya = 1* sin(radient);
	
	this->alive = 1;
	
}

Laser::~Laser(){}


void Laser::LaserUpdate()
{
	// ce que fait le laser à chaque frame
	this->laserShape.move(this->xa,this->ya);
	this->x =+ this->xa;
	this->y =+ this->ya;
	// si le projectile sort du cadre, le faire disparaitre 
	if (y < -30 || y > 930 || x < -30 || x > 1630)
	{
		// gerer la desctruction
		this->alive = 0;
		
	}
	

}

Laser::Laser(const Laser& source) : x(800), y(450), xa(source.xa), ya(source.ya), alive(1), laserShape(source.laserShape), laserTexture(source.laserTexture)
{
	
}