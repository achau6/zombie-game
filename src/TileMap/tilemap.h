#include <memory>
#include "../player/player.h"
#include "wall.h"

// TODO: first test if tilemap works then try to add another layer
// Tilemap only does first layer right now

class TileMap {
public:
	TileMap(std::map<std::string, std::shared_ptr<sf::Texture>>& game_textures);
	void Update(Player& player);
	void Render(sf::RenderWindow* window);

	sf::Vector2u getGridSize() {return grid_size;}

private:
	size_t layers = 2;
	sf::Vector2u grid_size = {50,50};
	sf::Vector2f tile_size = {70,70};

	std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> game_map;
};