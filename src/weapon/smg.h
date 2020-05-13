#ifndef SMG_H
#define SMG_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"

class smg
{
public:
	smg();
	Bullet b;
	weapons w;
	std::vector<Bullet> smgs;
	void push(Bullet b);
	void movement();
	void Draw(sf::RenderWindow& window);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;

};

#endif // SMG_H