#include "tile.h"

// TODO: first test if tilemap works then try to add another layer
// Tilemap only does first layer right now

class TileMap {
public:
	TileMap();
	void Update();
	void Render(sf::RenderWindow* window);

	sf::Vector2u getGridSize() {return grid_size;}

private:
	std::vector<std::vector<std::vector<Tile>>> game_map;
	sf::Vector2u grid_size = {50,50};
	size_t layers = 2;
	sf::Vector2f tile_size = {50,50};
	sf::RectangleShape Wall;
};