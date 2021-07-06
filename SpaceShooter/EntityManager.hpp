#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class EntityManager {      
private: 
    vector<Laser> laserTab;
	float LaserAngle;
public:
    createLaser(float LaserAngle);
    checkLaser();
};
