#ifndef RIFLE_H
#define RIFLE_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "Entities/entity_pool.h"
#include "gun_entity.h"

class rifle : public Gun_Entity
{
public:
//constructors
	rifle();
//typedef
	Bullet b;
	weapons w;
	//mutators
	void push(Bullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
	void add_ammo();
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
	std::vector<Bullet> rifles;

};

#endif // RIFLE_H