#pragma once

#include "tile.h"
#include "Entities/entity_pool.h"
// add this

// create an vector of wall pointers then pass them into the tile map
// loop through vector and check if collision

class Wall : public Tile {
public:
	// TODO: add texture parameter
	Wall() = default;
	// Wall constructor
	Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color color, std::shared_ptr<sf::Texture> texture) : Tile(size, pos, color, texture) {}
	// Checks if collision is present and prevents entity from entering
	bool isCollision(Entity& entity);

	bool isWall() {return true;}
	std::string isType() {return "wall";}
private:
	sf::FloatRect obj_next_pos;
};