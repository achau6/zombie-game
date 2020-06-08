#ifndef SMG_H
#define SMG_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "math.h"
#include "Entities/entity_pool.h"

class smg
{
public:
//constructors
	smg();
//typdef
	Bullet b;
	weapons w;
	//mutators
	void push(Bullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
	int getCurrentAmmo() {return currentAMMO;}
	int getMaxAmmo() {return maxAMMO;}
private:
	int fireRate;
	int maxAMMO;
	int currentAMMO;
	int shotFire;
	std::vector<Bullet> smgs;

};

#endif // SMG_H