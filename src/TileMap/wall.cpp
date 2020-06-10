#include "wall.h"

// TODO: MAKE IT BASED OFF A HITBOX INSTEAD OF THE ACTUALY SPRITE SIZE

bool Wall::isCollision(Entity& entity) {
	sf::FloatRect entity_bounds = entity.getHitbox().getGlobalBounds();
	sf::FloatRect wall_bounds = getTileBounds();
	obj_next_pos = entity_bounds;
	obj_next_pos.left += entity.getVelocity().x;
	obj_next_pos.top += entity.getVelocity().y;

	if(wall_bounds.intersects(obj_next_pos)) {
				// top collision
				if (entity_bounds.top < wall_bounds.top
					&& entity_bounds.top + entity_bounds.height < wall_bounds.top + wall_bounds.height
					&& entity_bounds.left < wall_bounds.left + wall_bounds.width
					&& entity_bounds.left + entity_bounds.width > wall_bounds.left
					)
				{
					// std::cout << "top collision" << std::endl;
					entity.getVelocity().y = 0.f;
					// SO ENTITY CAN SLIDE IF THEY KEEP WALKING INTO THE WALL
					// entity.getSprite().setPosition(entity_bounds.left, entity_bounds.top);
					// entity.getHitbox().setPosition(entity_bounds.left, entity_bounds.top);
				}

				// bottom collision
				else if (entity_bounds.top > wall_bounds.top
					&& entity_bounds.top + entity_bounds.height > wall_bounds.top + wall_bounds.height
					&& entity_bounds.left < wall_bounds.left + wall_bounds.width
					&& entity_bounds.left + entity_bounds.width > wall_bounds.left
					)
				{
					// std::cout << "bottom collision" << std::endl;
					entity.getVelocity().y = 0.f;
					// // SO ENTITY CAN SLIDE IF THEY KEEP WALKING INTO THE WALL
					// entity.getVelocity().x = 1.f;
				}

				// left collision
				else if (entity_bounds.left < wall_bounds.left
					&& entity_bounds.left + entity_bounds.width < wall_bounds.left + wall_bounds.width
					&& entity_bounds.top < wall_bounds.top + wall_bounds.height
					&& entity_bounds.top + entity_bounds.height > wall_bounds.top
					)
				{
					// std::cout << "left collision" << std::endl;
					entity.getVelocity().x = 0.f;
					// SO ENTITY CAN SLIDE IF THEY KEEP WALKING INTO THE WALL
					// entity.getVelocity().y = 1.f;
				}

				// right collision
				else if (entity_bounds.left > wall_bounds.left
					&& entity_bounds.left + entity_bounds.width > wall_bounds.left + wall_bounds.width
					&& entity_bounds.top < wall_bounds.top + wall_bounds.height
					&& entity_bounds.top + entity_bounds.height > wall_bounds.top
					)
				{
					//std::cout << "right collision" << std::endl;
					entity.getVelocity().x = 0.f;
					// SO ENTITY CAN SLIDE IF THEY KEEP WALKING INTO THE WALL
					// entity.getVelocity().y = -1.f;
				}
		return true;
	}

	return false;
}

