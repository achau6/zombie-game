#include "entity.h"

void Entity::Update() {

}

void Entity::Render(sf::RenderTarget& target) {
	target.draw(entity_sprite);
}

void Entity::addHp() {
	if (hp + 25.f > 100.f)
		hp = 100.f;
	else
		hp += 25.00;
}