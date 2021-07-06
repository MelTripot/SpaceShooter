#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Laser {      
private: 
    float angle ; 
	float x;
    float y;
    float xa;
    float ya;
    Texture laserTexture;
    
public:
	int alive;
	Sprite laserShape;
    // Laser(); // empty constructor
    Laser(float angle); // constructor
	Laser(const Laser&); //par copie
    ~Laser(); // Destructor
    void LaserUpdate();
    
};
