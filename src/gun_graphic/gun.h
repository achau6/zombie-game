#ifndef GUN_H
#define GUN_H

#include <iostream>
#include "math.h"
#include <vector>
#include "bullet.h"
#include "constants.h"

#include "weapon/pistol.h"
#include "weapon/smg.h"
#include "weapon/shotgun.h"
#include "weapon/rifle.h"
#include "player/player.h"
#include "weapon/melee.h"


#include "weapon/weapon_utility/ammo.h"
#include "weapon/weapon_utility/health_pack.h"

class Gun
{
public:
//contructors
	Gun();
//typedef
	Bullet b;
	KnifeBullet k;
	pistol p;
	rifle r;
	Shotgun sh;
	smg s;
	weapons w;
	// Player p1;
	Melee m;
	Ammo_Box ammo;
	Health health;
	int GLOBALIDENTIFIER;
//mutators
	void Draw(sf::RenderWindow& window);
	void fire(sf::RenderWindow& window, float Xpos, float Ypos, std::vector<std::shared_ptr<Zombie>> pool,
	sf::RectangleShape player);
	void movement(int identifier, std::vector<std::shared_ptr<Zombie>> pool, float x, float y,
	sf::RectangleShape player);
	void erase();
	void spawnAmmo_Box(sf::Vector2f position);
	std::pair<int, int> getAmmo();


//accessors
	int getGlobalIdentifier() {return GLOBALIDENTIFIER;}


private:
	sf::Vector2f aimView;
	sf::Vector2f aimViewNormalized;
	sf::Vector2f mousePosition;
	sf::Vector2f bulletPosition;
	sf::Vector2f bulletCenter;
	sf::Vector2f knifeCenter;

};

#endif // GUN_H