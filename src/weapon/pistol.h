#ifndef PISTOL_H
#define PISTOL_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "math.h"
#include "Entities/entity_pool.h"

class pistol
{
public:
	pistol();
	Bullet b;
	weapons w;
	std::vector<Bullet> pistols;
	void push(Bullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
};

#endif // PISTOL_H