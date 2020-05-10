#include "tile.h"
#include "../player/player.h"
// add this
#include "../Entities/entity.h"

// create an vector of wall pointers then pass them into the tile map
// loop through vector and check if collision

class Wall : public Tile {
public:
	Wall() = default;
	// TODO: add texture
	Wall(sf::Vector2f size, sf::Vector2f pos) : Tile(size, pos) {}
	// Checks if collision is present and prevents entity from entering
	bool isCollision(Player& p);

private:

};