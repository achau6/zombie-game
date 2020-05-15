#include "entity.h"

void Entity::Update() {

}

void Entity::Render(sf::RenderTarget& target) {
	target.draw(entity_sprite);
}
