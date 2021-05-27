#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Laser {      
private: 
    float angle ; 
    float x;
    float y;
    Sprite shape;
    Texture text;
    
public:
    // Laser(); // empty constructor
    Laser(float angle); // constructor
    ~Laser(); // Destructor
    void LaserUpdate();
    
};
