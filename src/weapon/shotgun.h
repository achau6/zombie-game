#ifndef SHOTGUN_H
#define SHOTGUN_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"

class Shotgun
{
public:
	Shotgun();
	Bullet b;
	weapons w;
	std::vector<Bullet> shotguns;
	void push(Bullet b);
	void movement();
	void Draw(sf::RenderWindow& window);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
};

#endif // SHOTGUN_H