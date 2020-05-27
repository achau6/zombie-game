#include "zombie.h"

Zombie::Zombie(sf::Vector2f spawn_pos, sf::Texture* texture) {
	entity_sprite.setTexture(*texture);
	entity_sprite.setPosition(spawn_pos);
	entity_sprite.scale(1.1,1.1);
}

// void Zombie::attack() {

// }

// sf::Vector2u Zombie::FindPlayer(const Player& player) {

// }
