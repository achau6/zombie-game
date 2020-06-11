#include "entity_pool.h"
#include "TileMap/tilemap.h"

EntityPool::EntityPool()
{

}
void EntityPool::Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures, const TileMap& tilemap) {
	pool.push_back(std::make_shared<Zombie>(position, game_textures["zombie"].get(), tilemap));
}

void EntityPool::Movement(Player& player) {
	for(auto zombies : pool) {
		zombies->Movement(player);
	}
}

void EntityPool::Update(Player& player) {
	for(auto it = pool.begin(); it != pool.end(); ++it) {
		if(it->get() != nullptr) {
			it->get()->Update(player);
			it->get()->Look(player);
			if(it->get()->IsDead()) {
				pool.erase(it);
				break;
			}
		}
	}
}

void EntityPool::FindPlayer(Player& player, TileMap& tilemap) {
	for(auto zombies : pool) {
		zombies->FindPlayer(player, tilemap);
	}
}

void EntityPool::Render(sf::RenderTarget& target) {
	for(auto zombies : pool) {
		zombies->Render(target);
	}
}

