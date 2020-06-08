#include "zombie.h"
#include "TileMap/tilemap.h"

Zombie::Zombie(sf::Vector2f spawn_pos, sf::Texture* texture, const TileMap& tilemap) {
	position = spawn_pos;
	initSprite(texture);
	initHitbox();
	node_grid = Astar::TileToNodeGrid(tilemap.GetGameMap(), tilemap.getObjectLayerNum());
	// for(auto x : node_grid) {
	// 	for(auto y : x) {
	// 		if(y->isWall)
	// 			std::cout << "W";
	// 		else {
	// 			std::cout << " ";
	// 		}
	// 	}
	// 	std::cout << std::endl;
	// }
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

void Zombie::FindPlayer(Player& player, TileMap& tilemap) {
	std::shared_ptr<Node> start_node = std::make_shared<Node>();
	sf::Vector2u zombie_grid_pos = grid_pos;
	start_node->pos = zombie_grid_pos;
	std::shared_ptr<Node> end_node = std::make_shared<Node>();
	end_node->pos = player.getGridPosition(tilemap.getGridSize());
	std::vector<std::shared_ptr<Node>> path = Astar::AStarSearch(start_node, end_node, node_grid);
	if(!path.empty()) {
		for(auto i : path) {
			std::cout << "X:" << i->pos.x << " " << "Y:" << i->pos.y << std::endl;
		}
	}
}

void Zombie::Render(sf::RenderTarget& target) {
	target.draw(hitbox);
	target.draw(entity_sprite);
}
