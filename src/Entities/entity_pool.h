#pragma once

#include "zombie.h"
// #include "TileMap/tilemap.h"

class TileMap;

class EntityPool {
public:
	EntityPool();

	void Render(sf::RenderTarget& target);
	void Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures, const TileMap& tilemap);
	void Update(Player& player);
	void Movement(Player& player);
	void FindPlayer(Player& player, TileMap& tilemap);

	int GetPoolSize() {return pool.size();}

	std::vector<std::shared_ptr<Zombie>> GetPool() {return pool;}
private:
	std::vector<std::shared_ptr<Zombie>> pool;
};
