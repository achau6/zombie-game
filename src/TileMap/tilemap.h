#include "tile.h"

// TODO: first test if tilemap works then try to add another layer
// Tilemap only does first layer right now

class TileMap {
public:
	TileMap();
	void Update();
	void Render(sf::RenderWindow* window);

private:
	std::vector<std::vector<Tile>> game_map;
	size_t grid_size = 25;
	float grid_sizef = 25;
};