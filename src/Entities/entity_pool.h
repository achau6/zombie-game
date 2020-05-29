#ifndef ENTITIYPOOL_H
#define ENTITIYPOOL_H
#include "zombie.h"

class EntityPool {
public:
	EntityPool();

	void Update();
	void Render(sf::RenderTarget& target);
	void Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
	int zombie_pool();
//private:
	std::vector<std::shared_ptr<Zombie>> pool;
};

#endif // ENTITIYPOOL_H