#pragma once
#include "Render.h"

bool Render::load(const std::string& tileset, sf::Vector2u tileSize, const char* tiles, unsigned int width, unsigned int height)
{
    if (!m_tileset.loadFromFile(tileset))
    {
        return false;
    }

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    int tileNumber = 0;

    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            switch(tiles[i + j * width])
            {
                case 'B':

                    tileNumber = 4;
                    break;

                case 'V':

                    tileNumber = 3;
                    break;

                case 'c':

                    tileNumber = 2;
                    break;

                case 'W':

                    tileNumber = 1;
                    break;

                case ' ':

                    tileNumber = 0;
                    break;

                default:

                    break;
            }

            //loading jpg sprites
            unsigned int tu = (unsigned) tileNumber % (m_tileset.getSize().x / tileSize.x);
            unsigned int tv = (unsigned) tileNumber / (m_tileset.getSize().x / tileSize.x);

            //its a pointer to something it does stuff
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            //four corners in window
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            //position in the jpg
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv  * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv  * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}
