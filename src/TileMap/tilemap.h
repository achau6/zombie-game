#include <memory>
#include "../player/player.h"
#include "wall.h"

// TODO: first test if tilemap works then try to add another layer
// Tilemap only does first layer right now

class TileMap {
public:
	TileMap();
	void Update(Player& player);
	void Render(sf::RenderWindow* window);

	sf::Vector2u getGridSize() {return grid_size;}

private:
	size_t layers = 2;
	sf::Vector2u grid_size = {50,50};
	sf::Vector2f tile_size = {50,50};

	std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> game_map;
};