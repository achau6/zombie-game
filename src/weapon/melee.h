#ifndef MELEE_H
#define MELEE_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "math.h"
#include "Entities/entity_pool.h"

class Melee : public weapons
{
public:
//constructor
	Melee();
//typedef
	KnifeBullet b;
	weapons w;
	//mutators
	bool push(KnifeBullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool, float x, float y);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
	int getCurrentAmmo() {return currentAMMO;}
	int getMaxAmmo() {return maxAMMO;}
private:
	int fireRate = 0;
	int maxAMMO = 0;
	int currentAMMO = 0;
	int shotFire = 0;
	std::vector<KnifeBullet> melees;

};
#endif // MELEE_H