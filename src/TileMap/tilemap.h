#pragma once

#include <memory>
#include "wall.h"
// #include "Collision/EntityCollision.h"
#include "Entities/entity_pool.h"

class TileMap {
	typedef std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> GameMap;
public:
	TileMap(std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
	void Update(Player& player, EntityPool& pool);
	void Render(sf::RenderWindow* window);

	sf::Vector2u getGridSize() {return grid_size;}
	size_t getObjectLayerNum() const {return 1;}
	size_t getBaseLayerNum() const {return 0;}
	GameMap& GetGameMap() {return game_map;}
	const GameMap& GetGameMap() const {return game_map;}
	size_t GetLayers() {return layers;}

private:
	const size_t layers = 2;
	sf::Vector2u grid_size = {50,50};
	sf::Vector2f tile_size = {70,70};

	GameMap game_map;
};