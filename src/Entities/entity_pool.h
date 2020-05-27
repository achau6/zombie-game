#include "zombie.h"

class EntityPool {
public:
	EntityPool() = default;

	void Update();
	void Render(sf::RenderTarget& target);
	void Spawn(sf::Vector2f position, std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
private:
	std::vector<std::shared_ptr<Zombie>> pool;
};