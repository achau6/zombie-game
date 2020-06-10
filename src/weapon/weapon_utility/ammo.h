#ifndef AMMO_H_H
#define AMMO_H
#include "Entities/entity.h"
#include "weapon/weapon.h"
#include <iostream>

/*
Why I didn't make a class that Ammo and Health can inherit from. Double inheritance is probably not a good idea.
*/
class Ammo_Box : public Entity
{
public:
	//constructors
	Ammo_Box() = default;

	void Draw(sf::RenderWindow& window);
	void spawn_pack(sf::Vector2f position);
	void delete_box(sf::RectangleShape player, int identifier, weapons& p, weapons& r, weapons& sh);
	int GetSize(){return ammo_pack.size();}
	bool collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool);


private:
	std::vector<std::pair<sf::Sprite, sf::RectangleShape>> ammo_pack;
	sf::Texture texture;

};
#endif // AMMO_H_H