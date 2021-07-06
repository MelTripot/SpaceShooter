#include "Laser.hpp"
#include <SFML/Graphics.hpp>
// nécessaire pour le calcul de la trajectoire du laser 
#include <vector>

using namespace std;

EntityManager::EntityManager() {}

EntityManager::createLaser(const float _angle) : LaserAngle(_angle)
{
	// Creer un objet laser et l'intégrer au vector de Laser (laserTab)
	// Laser(LaserAngle);
	this->laserTab.push_back(new Laser(LaserAngle));
	
}

EntityManager::checkLaser()
{
	// Parcourir le vector de Laser (laserTab) et supprimer les   alive==0
	
	
}