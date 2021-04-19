#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

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
    int x = 800;
    int y = 450;
    
    int r = 0;
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
                if (event.key.code == sf::Keyboard::D)
                    x += 10;
                if (event.key.code == sf::Keyboard::Q)
                    x -= 10;
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
                    
                    exist = true;

                }
            }
            if (exist)
            {
                y -= 30;
                proj.setPosition(x+50 ,y);
                // si le projectil sort du cadre, le faire disparaitre 
                if (y < -30 || y > 930 || x < -30 || x > 1630)
                {
                    
                    y = 450;
                    //proj.setPosition(x + 50, 820);
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
