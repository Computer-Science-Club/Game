#include <SFML/Graphics.hpp>
#include <iostream>

#include "Structures.cpp"
#include "Render.h"
#include "Map.cpp"

int main()
{
    Render mapView;

    int x = 1;
    int y = 1;

    View v;

    sf::RenderWindow window(sf::VideoMode(160, 160), "Tilemap");
    window.setVerticalSyncEnabled(true);

    v.height = 5;
    v.width = 5;

    v.current = new char[v.height * v.width];

    Map * worldMap = new Map(v);
    
    worldMap -> getView(v.current, x - 2, y - 2);

    mapView.load("tilemap.png", sf::Vector2u(32, 32), v.current, 5,  5);

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

                    
                    worldMap -> setTile(' ', x, y);

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

                    if(worldMap -> spaceIsOpen(newX, newY))
                    {
                        x = newX;
                        y = newY;
                        worldMap -> setTile('c', newX, newY);
                    } else {
                        worldMap -> setTile('c', x, y);
                    }

                    worldMap -> getView(v.current, x - 2, y - 2);
                    mapView.load("tilemap.png", sf::Vector2u(32, 32), v.current, 5,  5);

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