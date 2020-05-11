#include "tilemap.h"

// TODO: turn into 3d array with Z being the number of layers

TileMap::TileMap() {
	const int GROUND_LAYER = 0;
	const int OBJECT_LAYER = 1;
	game_map.reserve(grid_size.x);
	for(size_t x = 0; x < grid_size.x; x++) {
		game_map.push_back(std::vector<std::vector<std::shared_ptr<Tile>>>());
		for(size_t y = 0; y < grid_size.y; y++) {
			game_map[x].reserve(grid_size.y);
			game_map[x].push_back(std::vector<std::shared_ptr<Tile>>());
			for(size_t z = 0; z < layers; z++) {
				game_map[x][y].reserve(layers);
				if(z == GROUND_LAYER) {
					sf::Color brown(139,69,19);
					game_map[x][y].push_back(std::make_shared<Tile>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), brown));
				}
				// Puttings walls on the edges of the map
				else if(y == 0 && z == OBJECT_LAYER) {
					game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue));
				}
				else if(x == 0 && z == OBJECT_LAYER) {
					game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue));
				}
				else if(y == grid_size.y-1 && z == OBJECT_LAYER) {
					game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue));
				}
				else if(x == grid_size.x-1 && z == OBJECT_LAYER) {
					game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue));
				}
				// adding this so elements that are empty will not be rendered
				// makes rendering code shorter
				else {
					game_map[x][y].push_back(nullptr);
				}
			}
		}
	}
}

void TileMap::Update(Player& player) {
	for(size_t x = 0; x < grid_size.x; x++) {
		for(size_t y = 0; y < grid_size.y; y++) {
			for(size_t z = 0; z < layers; z++) {
				if(game_map[x][y][z] != nullptr) {
					if(game_map[x][y][z]->isType() == "wall")
						std::static_pointer_cast<Wall>(game_map[x][y][z])->isCollision(player);
				}
			}
		}
	}
}

void TileMap::Render(sf::RenderWindow* window) {
	for(size_t x = 0; x < grid_size.x; x++) {
		for(size_t y = 0; y < grid_size.y; y++) {
			for(size_t z = 0; z < layers; z++) {
				if(game_map[x][y][z] != nullptr) {
					game_map[x][y][z]->Render(window);
				}
			}
		}
	}
}
