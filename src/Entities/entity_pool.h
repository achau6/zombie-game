#pragma once

#include "zombie.h"
// #include "TileMap/tilemap.h"

class EntityPool {
public:
	EntityPool() = default;

	void Render(sf::RenderTarget& target);
	void Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
	void Update(Player& player);
	void Movement();

	std::vector<std::shared_ptr<Zombie>> GetPool() {return pool;}
private:
	std::vector<std::shared_ptr<Zombie>> pool;
};