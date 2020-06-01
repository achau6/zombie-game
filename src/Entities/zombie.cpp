#include "zombie.h"

Zombie::Zombie(sf::Vector2f spawn_pos, sf::Texture* texture) {
	position = spawn_pos;
	initSprite(texture);
	initHitbox();
}

void Zombie::initSprite(sf::Texture* texture) {
	entity_sprite.setTexture(*texture);
	entity_sprite.setPosition(position);
	entity_sprite.scale(1.1,1.1);
}

void Zombie::initHitbox() {
	hitbox.setSize({entity_sprite.getGlobalBounds().width, entity_sprite.getGlobalBounds().height});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(2);
	// hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	// hitbox.setScale(0.5,0.5);
	hitbox.setPosition(position);
}

void Zombie::Movement() {
	velocity.x += -movement_speed;
}

void Zombie::Attack() {

}

void Zombie::Update() {
	entity_sprite.move(velocity);
	hitbox.move(velocity);
	velocity = sf::Vector2f(0,0);
}

void Zombie::FindPlayer(Player& player) {
	// Node start_node;
	// start_node.pos = grid_pos;
	// Node end_node;
	// end_node.pos = player.getGridPosition(tile_map.getGridSize());
	// std::vector<Node> path = AStar(start_node, end_node, TileToNodeGrid(tile_map.GetTileMapVector(), tile_map.getObjectLayerNum()));
	// // for(auto i : path) {
	// // 	std::cout << "X:" << i.pos.x << " " << "Y:" << i.pos.y << std::endl;
	// // }
}

void Zombie::Render(sf::RenderTarget& target) {
	target.draw(hitbox);
	target.draw(entity_sprite);
}
