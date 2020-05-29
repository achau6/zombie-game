#include "zombie.h"

Zombie::Zombie()
{
}

Zombie::Zombie(sf::Vector2f spawn_pos, sf::Texture* texture) {
	entity_sprite.setTexture(*texture);
	entity_sprite.setPosition(spawn_pos);
	entity_sprite.scale(1.1,1.1);

	/*
	To get the hitbox area to check if bullet touches it
	*/
	hitbox.setSize({entity_sprite.getGlobalBounds().width, entity_sprite.getGlobalBounds().height});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(5);
	hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setPosition(spawn_pos);
	hitbox.setScale(1,1);


}


