#include <vector>
#include <iostream>
#include <memory>
#include "Platform/Platform.hpp"

class Tile {
public:
	Tile() = default;
	Tile(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
		: tile_size{size} {
		shape.setSize(tile_size);
		shape.setFillColor(color);
		shape.setPosition(pos);
		texture = std::make_unique<sf::Texture>();
		if (!texture->loadFromFile("../zombie-game/content/dirt.png")){
			std::cout<<"failed to load tile texture\n";
		}
		shape.setTexture(&*texture);
	}
	void Render(sf::RenderWindow* window) {
		window->draw(shape);
	}

	sf::FloatRect getTileBounds() {return shape.getGlobalBounds();}
	sf::Vector2f getTileSize() {return tile_size;}
	virtual std::string isType() {return "tile";}
private:
	sf::RectangleShape shape;
	std::unique_ptr<sf::Texture> texture;
	sf::Vector2f tile_size;
};