#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Render : public sf::Drawable, public sf::Transformable
{
	public:

		bool load(const std::string& tileset, sf::Vector2u tileSize, const char* tiles, unsigned int width, unsigned int height);
    
    private:

    	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    	sf::VertexArray m_vertices;
    	sf::Texture m_tileset;
};
