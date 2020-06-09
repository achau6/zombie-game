#ifndef SHOTGUN_H
#define SHOTGUN_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "math.h"
#include "Entities/entity_pool.h"
#include "gun_entity.h"

class Shotgun : public Gun_Entity
{
public:
//constructors
	Shotgun();
//typdef
	Bullet b;
	weapons w;
//mutators
	void push(Bullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
	void add_ammo();
	int getCurrentAmmo() {return currentAMMO;}
	int getMaxAmmo() {return maxAMMO;}
	bool flag_check(){return flag;}


private:
	bool flag;
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	std::vector<Bullet> shotguns;
};

#endif // SHOTGUN_H