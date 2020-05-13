#ifndef PISTOL_H
#define PISTOL_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
class pistol
{
public:
	pistol();
	Bullet b;
	weapons w;
	std::vector<Bullet> pistols;
	void push(Bullet b);
	void movement();
	void Draw(sf::RenderWindow& window);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
};

#endif // PISTOL_H