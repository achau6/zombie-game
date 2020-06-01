#pragma once

#include <memory>
#include "wall.h"
#include "Entities/entity_pool.h"

// TODO: first test if tilemap works then try to add another layer
// Tilemap only does first layer right now

class TileMap {
public:
	TileMap(std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
	void Update(Player& player, EntityPool& pool);
	void Render(sf::RenderWindow* window);

	std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> GetTileMapVector() {return game_map;}
	sf::Vector2u getGridSize() {return grid_size;}
	size_t getObjectLayerNum() {return 1;}
	size_t getBaseLayerNum() {return 0;}

private:
	size_t layers = 2;
	sf::Vector2u grid_size = {50,50};
	sf::Vector2f tile_size = {70,70};

	std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> game_map;
};