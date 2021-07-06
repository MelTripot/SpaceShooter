#define _USE_MATH_DEFINES
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
// nécessaire pour le calcul de la trajectoire du laser 
#include <cmath>

#include "Ship.hpp"
#include "EntityManager.hpp"


using namespace std;
using namespace sf;


int main()
{
    // ouvre une fenêtre avec les dimension 1600, 900 au nom de SpaceShooter 
    RenderWindow window(sf::VideoMode(1600, 900), "SpaceShooter");
    // déclare le sprite et la texture du vaiseau 
    Sprite ship;
    Texture text;
    // déclare le sprite et la texture du laser 
    // Texture laser;
    // Sprite proj;
	
	EntityManager entityManager;
	
    bool exist = false;
    //Charge la texture du vaiseau
    if (!text.loadFromFile("Asset/playerShip1_blue.png"))
    {
        // not found
    }
    // Ajoute la texture du vaiseau sur son sprite 
    ship.setTexture(text);
    
	ship.setOrigin(50,38);
	ship.setPosition(800,450);
    
    float x = 800;
    float y = 450;
    float xa =0;
    float ya =0;
    
    float r = 0;
    float radient = 0;
    while (window.isOpen())
    {
        ship.setRotation(r);
		entityManager.checkLaser();
		
		
		// Controles different inputs pour plusieurs bouttons en meme temps
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			r -=0.3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			r +=0.3;
		}
		
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::KeyPressed:

                if (event.type == sf::Event::Closed)
                    window.close();
                //if (event.key.code == sf::Keyboard::Left)
                //    r -=10;
                //if(event.key.code == sf::Keyboard::Right)
                //    r +=10;                
                if (event.key.code == sf::Keyboard::E)
                {
                    
					entityManager.createLaser(r);
					
					
					/*
					Vector2f SpawnProjectile = Vector2f(x , y );
                    if (!laser.loadFromFile("Asset/laserBlue01.png"))
                    {
                        // not found
                    }
                    proj.setTexture(laser);
                    proj.setPosition(SpawnProjectile);
                    proj.setRotation(r);
                    // ajout de la rotation de 270 du proj (car diff avec le sprite) 
                    //TODO up le deplacement en dehors de la boucle 
                    radient = ((r+270)*M_PI/180);
					// On peut changer la valeur (0.1) pour chager la vitesse
					xa = 1.5* cos(radient);
                    ya = 1.5* sin(radient);
                    exist = true;
					*/
					
                }
            }
                      
        }
		
		
		
		/*
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
		*/
		
        window.clear();
        // window.draw(proj);
        window.draw(ship);
		entityManager.laserDraw(window);
        window.display();
    }


}
