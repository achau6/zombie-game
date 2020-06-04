#ifndef MELEE_H
#define MELEE_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "math.h"
#include "Entities/entity_pool.h"

class Melee
{
public:
	Melee();
	KnifeBullet b;
	weapons w;
	std::vector<KnifeBullet> melees;
	void push(KnifeBullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool, float x, float y);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
};
#endif // MELEE_H