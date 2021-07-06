#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Laser.hpp"

using namespace std;
using namespace sf;

class EntityManager {      
private: 
    vector<Laser> laserTab;
	// float LaserAngle; 
public:
    void createLaser(float LaserAngle);
    void checkLaser();
	EntityManager();
};
