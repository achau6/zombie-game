#ifndef HEALTH_PACK_H
#define HEALTH_PACK_H
#include "Entities/entity.h"
#include <iostream>
#include "player/player.h"

/*
Why I didn't make a class that Ammo and Health can inherit from. Double inheritance is probably not a good idea.
*/

class Health : public Entity
{
public:
	//constructors
	Health();

	Entity h;
	//Mutators
	void Draw(sf::RenderWindow& window);
	void spawn_pack(sf::Vector2f position);
	void delete_health_pack(Player& player);
	bool collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool);
	//accessors
	int GetSize(){return health_pack.size();}


private:
/*
Made a pair that hold both a sprite and a shape.
Map was not needed as we don't need a key
*/
	std::vector<std::pair<sf::Sprite, sf::RectangleShape>> health_pack;
	sf::Texture texture;

};
#endif // HEALTH_PACK_H