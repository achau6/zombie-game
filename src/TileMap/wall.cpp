#include "wall.h"

bool Wall::isCollision(Entity& entity) {
	sf::FloatRect entity_bounds = entity.getSprite().getGlobalBounds();
	sf::FloatRect wall_bounds = getTileBounds();
	obj_next_pos = entity_bounds;
	obj_next_pos.top += entity.getVelocity().x;
	obj_next_pos.left += entity.getVelocity().y;

	if(wall_bounds.intersects(obj_next_pos)) {
		//Right collision
		if (entity_bounds.left < wall_bounds.left
			&& entity_bounds.left + entity_bounds.width < wall_bounds.left + wall_bounds.width
			&& entity_bounds.top < wall_bounds.top + wall_bounds.height
			&& entity_bounds.top + entity_bounds.height > wall_bounds.top
			) {
				std::cout << "Test" << std::endl;
				// entity.getSprite().setPosition(sf::Vector2f(wall_bounds.left - entity_bounds.width, entity_bounds.top));
			}
		//Left collision
		else if (entity_bounds.left > wall_bounds.left
			&& entity_bounds.left + entity_bounds.width > wall_bounds.left + wall_bounds.width
			&& entity_bounds.top < wall_bounds.top + wall_bounds.height
			&& entity_bounds.top + entity_bounds.height > entity_bounds.top
			) {
			// entity.getSprite().setPosition({wall_bounds.left + wall_bounds.width, entity_bounds.top});
		}
		return true;
	}

	return false;
}
