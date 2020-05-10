#include <vector>
#include <iostream>
#include "Platform/Platform.hpp"

class Tile {
public:
	Tile() = default;
	Tile(sf::Vector2f size, sf::Vector2f pos)
		: tile_size{size} {
		shape.setSize(tile_size);
		shape.setFillColor(sf::Color(139,69,19));
		shape.setPosition(pos);
	}
	void Render(sf::RenderWindow* window) {
		window->draw(shape);
	}
	sf::Vector2f getTileSize() {return tile_size;}
private:
	sf::RectangleShape shape;
	sf::Vector2f tile_size;
};