#include "tilemap.h"

TileMap::TileMap(std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures) {
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
					game_map[x][y].push_back(std::make_shared<Tile>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), game_textures["dirt"]));
				}
				// Puttings walls on the edges of the map
				// else if(y == 0 && z == OBJECT_LAYER) {
				// 	game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue, game_textures["dirt"]));
				// }
				// else if(x == 0 && z == OBJECT_LAYER) {
				// 	game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue, game_textures["dirt"]));
				// }
				// else if(y == grid_size.y-1 && z == OBJECT_LAYER) {
				// 	game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue, game_textures["dirt"]));
				// }
				// else if(x == grid_size.x-1 && z == OBJECT_LAYER) {
				// 	game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), sf::Color::Blue, game_textures["dirt"]));
				// }
				else if(z == OBJECT_LAYER && level[y][x] == 1) {
					game_map[x][y].push_back(std::make_shared<Wall>(tile_size, sf::Vector2f(x*tile_size.x, y*tile_size.y), game_textures["concrete"]));
					// std::cout << "PUSHED WALL\n";
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

void TileMap::Update(Player& player, EntityPool& pool) {
	for(size_t x = 0; x < grid_size.x; x++) {
		for(size_t y = 0; y < grid_size.y; y++) {
			for(size_t z = 0; z < layers; z++) {
				if(game_map[x][y][z] != nullptr) {
					if(game_map[x][y][z]->isType() == "wall") {
						std::static_pointer_cast<Wall>(game_map[x][y][z])->isCollision(player);
						// checking the zombie pool for collision
						for(auto zombies : pool.GetPool()) {
							std::static_pointer_cast<Wall>(game_map[x][y][z])->isCollision(*zombies);
							// std::cout << "zombie col";
						}
					}
				}
			}
		}
	}
	// EntityCollision::Update(player, pool, *this);
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

