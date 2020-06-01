#include "entity_pool.h"

void EntityPool::Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures) {
	pool.push_back(std::make_shared<Zombie>(position, game_textures["zombie"].get()));
}

void EntityPool::Movement() {
	for(auto zombies : pool) {
		zombies->Movement();
	}
}

void EntityPool::Update(Player& player) {
	for(auto zombies : pool) {
		zombies->Update();
		zombies->FindPlayer(player);
	}
}

void EntityPool::Render(sf::RenderTarget& target) {
	for(auto zombies : pool) {
		zombies->Render(target);
	}
}