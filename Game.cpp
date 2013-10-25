#include <SFML/Graphics.hpp>
#include <iostream>

#include "Structures.cpp"
#include "Render.h"
#include "Map.cpp"

Render mapView;

int x = 1;
int y = 1;

View v;

Map worldMap;

char camera[25];

int updateCamera()
{
    worldMap.getView(camera, x - 2, y - 2);

    if(!mapView.load("tilemap.png", sf::Vector2u(32, 32), camera, 5,  5))
    {
        return -1;
    }

    return 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(160, 160), "Tilemap");
    window.setVerticalSyncEnabled(true);

    v.height = 5;
    v.width = 5;

    v.current = new char[v.height * v.width];
    v.previous = new char[v.height * v.width];

    worldMap.setView(v);
    
    worldMap.getView(camera, x, y);

    updateCamera();

    int newX;
    int newY;

    while(window.isOpen())
    {

        newX = x;
        newY = y;

        sf::Event event;

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::LostFocus:
                    //.pause();
                    break;

                case sf::Event::GainedFocus:
                    //.resume();
                    break;

                case sf::Event::KeyPressed:

                    
                    worldMap.setTile(' ', x, y);

                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            newY--;

                            break;

                        case sf::Keyboard::Down:
                            newY++;

                            break;

                        case sf::Keyboard::Left:
                            newX--;

                            break;

                        case sf::Keyboard::Right:
                            newX++;

                            break;

                        default:
                            
                            break;
                    }

                    if(worldMap.spaceIsOpen(newX, newY))
                    {
                        x = newX;
                        y = newY;
                        worldMap.setTile('c', newX, newY);
                    } else {
                        worldMap.setTile('c', x, y);
                    }

                    updateCamera();

                    break;

                default:
                   
                    break;
            }
        }

        window.clear();
        window.draw(mapView);
        window.display();
    }

    return 0;
}