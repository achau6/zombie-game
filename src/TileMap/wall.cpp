#include "wall.h"

bool Wall::isCollision(Player& p) {
	sf::FloatRect player_bounds = p.getPlayerSprite().getGlobalBounds();
	sf::FloatRect wall_bounds = getTileBounds();
	obj_next_pos = player_bounds;
	obj_next_pos.top += p.getPlayerSpd();
	obj_next_pos.left += p.getPlayerSpd();

	if(wall_bounds.intersects(obj_next_pos)) {
		//Right collision
		if (player_bounds.left < wall_bounds.left
			&& player_bounds.left + player_bounds.width < wall_bounds.left + wall_bounds.width
			&& player_bounds.top < wall_bounds.top + wall_bounds.height
			&& player_bounds.top + player_bounds.height > wall_bounds.top
			) {
				// std::cout << "Test" << std::endl;
				p.setPosition(sf::Vector2f(wall_bounds.left - player_bounds.width, player_bounds.top));
			}
		return true;
	}

	return false;
}
