#define _USE_MATH_DEFINES
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
// nécessaire pour le calcul de la trajectoire du laser 
#include <cmath>

using namespace std;
using namespace sf;




int main()
{
    // ouvre une fenêtre avec les dimension 1600, 900 au nom de SpaceShooter 
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SpaceShooter");
    // déclare le sprite et la texture du vaiseau 
    sf::Sprite ship;
    sf::Texture text;
    // déclare le sprite et la texture du vaiseau 
    sf::Texture laser;
    sf::Sprite proj;
    bool exist = false;
    //Charge la texture du vaiseau
    if (!text.loadFromFile("Asset/playerShip1_blue.png"))
    {
        // not found
    }
    // Ajoute la texture du vaiseau sur son sprite 
    ship.setTexture(text);
    float x = 800;
    float y = 450;
    float xa =0;
    float ya =0;
    
    int r = 0;
    float radient = 0;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::KeyPressed:

                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.key.code == sf::Keyboard::Left)
                    r -=10;
                if(event.key.code == sf::Keyboard::Right)
                    r +=10;                
                if (event.key.code == sf::Keyboard::E)

                {

                    Vector2f SpawnProjectile = Vector2f(x , y );
                    if (!laser.loadFromFile("Asset/laserBlue01.png"))
                    {
                        // not found
                    }
                    proj.setTexture(laser);
                    proj.setPosition(SpawnProjectile);

                    proj.setRotation(r);
                    // ajout de la rotation de 270 du proj (car diff avec le sprite) 
                    radient = ((r+270)*M_PI/180);
                    xa = 10* cos(radient);
                    ya = 10* sin(radient);
                    
                    
                    
                    exist = true;

                }
            }
            if (exist)
            {
//                x += xa;
//                y += ya;
//                proj.setPosition(x,y);
                proj.move(xa,ya);
                // si le projectil sort du cadre, le faire disparaitre et reassigner sa position de départ  
                if (y < -30 || y > 930 || x < -30 || x > 1630)
                {
                    x = 800;
                    y = 450;
                    exist = false;
                }
            }

//            Vector2f truc = Vector2f(x, 450);
            ship.setOrigin(50,38);
            ship.setPosition(800,450);
            ship.setRotation(r);
        }
        window.clear();

        window.draw(proj);
        window.draw(ship);
        window.display();
    }


}
