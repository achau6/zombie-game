#include "tilemap.h"

// TODO: turn into 3d array with Z being the number of layers

TileMap::TileMap() {
	game_map.reserve(grid_size.x);
	for(size_t x = 0; x < grid_size.x; x++) {
		game_map.push_back(std::vector<std::vector<Tile>>());
		for(size_t y = 0; y < grid_size.y; y++) {
			game_map[x].reserve(grid_size.y);
			game_map[x].push_back(std::vector<Tile>());
			for(size_t z = 0; z < layers; z++) {
				game_map[x][y].reserve(layers);
				game_map[x][y].push_back(Tile(tile_size, {x*tile_size.x, y*tile_size.y}));
			}
		}
	}
}

void TileMap::Update() {

}

void TileMap::Render(sf::RenderWindow* window) {
	for(size_t x = 0; x < grid_size.x; x++) {
		for(size_t y = 0; y < grid_size.y; y++) {
			for(size_t z = 0; z < layers; z++) {
				game_map[x][y][z].Render(window);
			}
		}
	}
}
