#ifndef AMMO_H_H
#define AMMO_H
#include "Entities/entity.h"
#include <iostream>

/*
Why I didn't make a class that Ammo and Health can inherit from. Double inheritance is probably not a good idea.
*/
class Ammo : public Entity
{
public:
	//constructors
	Ammo();
	//Mutators
	void Draw(sf::RenderWindow& window);
	void spawn_pack(sf::Vector2f position);
	void movement(sf::RectangleShape player);
	void delete_health_pack();
	int GetSize(){return health_pack.size();}
	bool collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool);


private:
	std::vector<std::pair<sf::Sprite, sf::RectangleShape>> health_pack;

};
#endif // AMMO_H_H