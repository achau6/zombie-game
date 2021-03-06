#pragma once

#include "Algorithms/astar.h"
#include "player/player.h"

class TileMap;

class Zombie : public Entity {
public:
	Zombie() = default;
	Zombie(sf::Vector2f spawn_pos, sf::Texture* texture, const TileMap& tilemap);

	void Update(Player& player);
	void Render(sf::RenderTarget& target);

	void Look(Player& player);
	void Movement(Player& player);
	void MoveOneTile(sf::Vector2u tohere);
	void Attack(Player& player);
	void Damage(float dmg) {hp-=dmg;}
	bool IsDead() {return this->hp <= 0;}
	std::vector<std::shared_ptr<Node>> FindPlayer(Player& player, TileMap& tilemap);
	// sf::Vector2u getGridPosition(const sf::Vector2u& grid_size);

private:
	void initSprite(sf::Texture* texture);
	void initHitbox();

	const sf::Vector2u grid_size;
	float movement_speed = 0;
	const float zombie_damage = 10.0/144.f;

	sf::Vector2u next_pos;

	std::vector<std::vector<std::shared_ptr<Node>>> node_grid;

	std::vector<std::shared_ptr<Node>> path_to_player;
};