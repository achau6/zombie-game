#pragma once

#include "Algorithms/astar.h"
#include "player/player.h"

class TileMap;

class Zombie : public Entity {
public:
	Zombie() = default;
	Zombie(sf::Vector2f spawn_pos, sf::Texture* texture, const TileMap& tilemap);

	void Update();
	void Render(sf::RenderTarget& target);

	void Movement();
	void Attack();
	bool IsDead() {return is_dead;}
	void FindPlayer(Player& player, TileMap& tilemap);

private:
	void initSprite(sf::Texture* texture);
	void initHitbox();

	const float movement_speed = 3.5;
	bool is_dead = false;

	std::vector<std::vector<std::shared_ptr<Node>>> node_grid;
};