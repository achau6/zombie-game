#include "tilemap.h"

TileMap::TileMap() {
	game_map.resize(grid_size);
	for (size_t i = 0; i < grid_size; i++) {
		game_map.push_back(std::vector<Tile>());
		game_map[i].resize(grid_size);
		for(size_t j = 0; j < grid_size; j++) {
			// TODO: remove the magic nums from testing
			sf::Vector2f pos = sf::Vector2f(i*grid_sizef, j*grid_sizef);
			game_map[i].push_back(Tile(pos));
		}
	}
}

void TileMap::Update() {

}

void TileMap::Render(sf::RenderWindow* window) {
	for (size_t i = 0; i < game_map.size(); i++) {
		for(size_t j = 0; j < game_map[i].size(); j++) {
			game_map[i][j].Render(window);
		}
	}
}
