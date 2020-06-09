#include "zombie.h"
#include "TileMap/tilemap.h"

Zombie::Zombie(sf::Vector2f spawn_pos, sf::Texture* texture, const TileMap& tilemap)
 : grid_size(tilemap.GetSize()) {
	position = spawn_pos;
	grid_pos = getGridPosition(tilemap.GetSize());
	initSprite(texture);
	initHitbox();
	node_grid = Astar::TileToNodeGrid(tilemap.GetGameMap(), tilemap.getObjectLayerNum());
	// next_pos = {grid_pos.x, grid_pos.y};
}

void Zombie::initSprite(sf::Texture* texture) {
	entity_sprite.setTexture(*texture);
	entity_sprite.setPosition(position);
	entity_sprite.scale(1.1,1.1);
	entity_sprite.setOrigin(texture->getSize().x/2, texture->getSize().y/2);
}

void Zombie::initHitbox() {
	hitbox.setSize({entity_sprite.getGlobalBounds().width, entity_sprite.getGlobalBounds().height});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(2);
	hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setScale(0.7,0.7);
	hitbox.setPosition(position);
}

sf::Vector2u Zombie::getGridPosition(const sf::Vector2u& grid_size) {
	if(position.x > 0)
		grid_pos.x = position.x / grid_size.x;
	if(position.y > 0)
		grid_pos.y = position.y / grid_size.y;

	return grid_pos;
}

void Zombie::Look(Player& player){
	sf::Vector2f playerPos = player.getPlayerSprite().getPosition();
	sf::Vector2f zombiePos = entity_sprite.getPosition();

	float angle = atan2(playerPos.y - zombiePos.y, playerPos.x - zombiePos.x) * 180 / 3.141;

	entity_sprite.setRotation(angle);
}

void Zombie::Movement() {
	// std::cout << position.x << position.y << std::endl;

	MoveOneTile(path_to_player.begin()->get()->pos);
	// std::cout << "TO HERE: " << path_to_player.begin()->get()->pos.x << " " << path_to_player.begin()->get()->pos.y << std::endl;
	if(!path_to_player.empty() && grid_pos == path_to_player.begin()->get()->pos)
		path_to_player.erase(path_to_player.begin());

	// std::cout << "GRID POS: " << grid_pos.x << " " << grid_pos.y << std::endl;

}

void Zombie::MoveOneTile(sf::Vector2u tohere) {
	// Move up
	if(grid_pos.y-1 == tohere.y) {
		velocity.y += -movement_speed;
	}
	// Move down
	if(grid_pos.y+1 == tohere.y) {
		velocity.y += movement_speed;
	}
	// Move left
	if(grid_pos.x-1 == tohere.x) {
		velocity.x += -movement_speed;
	}
	// Move right
	if(grid_pos.x+1 == tohere.x) {
		velocity.x += movement_speed;
	}
	// Move up and left
	if(grid_pos.x == tohere.x && grid_pos.y-1 == tohere.y) {
		velocity.y += -movement_speed;
		velocity.x += -movement_speed;
	}
	// Move up and right
	if(grid_pos.x == tohere.x && grid_pos.y-1 == tohere.y) {
		velocity.y += movement_speed;
		velocity.x += movement_speed;
	}
	// Move down and left
	if(grid_pos.x-1 == tohere.x && grid_pos.y+1 == tohere.y) {
		velocity.x += -movement_speed;
		velocity.y += movement_speed;
	}
	// Move down and right
	if(grid_pos.x+1 == tohere.x && grid_pos.y+1 == tohere.y) {
		velocity.x += movement_speed;
		velocity.y += movement_speed;
	}

	// TODO: REMOVE MAGIC NUMS
	// Slows down diagonally movement for zombie
	if (velocity.x != 0.f && velocity.y != 0.f)
    	velocity /= std::sqrt(6.f);

	// Updating positions
	position = entity_sprite.getPosition();
	grid_pos = getGridPosition(grid_size);
}

void Zombie::Attack(Player& player) {
	if(entity_sprite.getGlobalBounds().intersects(player.getHitbox().getGlobalBounds())) {
		player.DamagePlayer(zombie_damage);
	}
}

void Zombie::Update(Player& player) {
	entity_sprite.move(velocity);
	hitbox.move(velocity);
	velocity = sf::Vector2f(0,0);
	// TODO: CHANGE THIS SO PLAYER DOESNT TAKE DAMAGE EVERY FRAME
	Attack(player);
	// std::cout << player.getHP() << std::endl;
}

std::vector<std::shared_ptr<Node>> Zombie::FindPlayer(Player& player, TileMap& tilemap) {
	std::shared_ptr<Node> start_node = std::make_shared<Node>();
	sf::Vector2u zombie_grid_pos = grid_pos;
	start_node->pos = zombie_grid_pos;
	std::shared_ptr<Node> end_node = std::make_shared<Node>();
	end_node->pos = player.getGridPosition(tilemap.getGridSize());
	path_to_player = Astar::AStarSearch(start_node, end_node, node_grid);
	return path_to_player;
}

void Zombie::Render(sf::RenderTarget& target) {
	target.draw(hitbox);
	target.draw(entity_sprite);
}
