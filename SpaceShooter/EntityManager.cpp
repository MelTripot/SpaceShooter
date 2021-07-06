#include <SFML/Graphics.hpp>
// nécessaire pour le calcul de la trajectoire du laser 
#include <vector>

#include "EntityManager.hpp"

using namespace std;

EntityManager::EntityManager() {
	
}

void EntityManager::createLaser(float _angle)
{
	// Creer un objet laser et l'intégrer au vector de Laser (laserTab)
	// Laser(LaserAngle);
	this->laserTab.push_back(Laser(_angle));
	
}

void EntityManager::checkLaser()
{
	// Parcourir le vector de Laser (laserTab) et supprimer les   alive==0
	for( Laser& _laser:this->laserTab){
		_laser.LaserUpdate();
		if( _laser.alive == 0){
			_laser.~Laser();
		}
	}
}

void EntityManager::laserDraw(RenderWindow &window)
{
	for( Laser& _laser:this->laserTab){
		window.draw(_laser.laserShape);
	}
}