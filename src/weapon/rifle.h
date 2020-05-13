#ifndef RIFLE_H
#define RIFLE_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"

class rifle
{
public:
	rifle();
	Bullet b;
	weapons w;
	std::vector<Bullet> rifles;
	void push(Bullet b);
	void movement();
	void Draw(sf::RenderWindow& window);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
};

#endif // RIFLE_H