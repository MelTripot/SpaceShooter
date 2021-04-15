#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "SpaceShooter");
    sf::Sprite shape;
    sf::Texture text;
    sf::Texture laser;
    sf::Sprite proj;
    bool exist = false;
    
    if (!text.loadFromFile("Asset/playerShip1_blue.png"))
    {
        // not found
    }
    shape.setTexture(text);
    //sf:Vector2f truc = Vector2f(100, 20);
    //shape.setPosition(truc);
    int x = 20;
    int y = 820;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::KeyPressed:

                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.key.code == sf::Keyboard::D)
                    x += 10;
                if (event.key.code == sf::Keyboard::Q)
                    x -= 10;
                if (event.key.code == sf::Keyboard::E)

                {
                    Vector2f SpawnProjectile = Vector2f(x + 50, 820);
                    if (!laser.loadFromFile("Asset/laserBlue01.png"))
                    {
                        // not found
                    }
                    proj.setTexture(laser);
                    proj.setPosition(SpawnProjectile);
                    exist = true;


                }
            }
            if (exist)
            {
                y -= 30;
                proj.setPosition(x+50 ,y);
                if (y < -30)
                {
                    y = 820;
                    //proj.setPosition(x + 50, 820);
                    exist = false;
                }
            }



            Vector2f truc = Vector2f(x, 900);
            shape.setPosition(truc);
        }
        window.clear();

        window.draw(proj);
        window.draw(shape);
        window.display();
    }


}
