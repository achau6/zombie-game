#ifndef GUN_H
#define GUN_H

#include <iostream>
#include "math.h"
#include <vector>
#include "bullet.h"
#include "constants.h"

#include "weapon/melee.h"

#include"player/player.h"
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
	weapons p, r, sh;
	Melee m;
	Ammo_Box ammo;
	Health health;
	int GLOBALIDENTIFIER;
//mutators
	void Draw(sf::RenderWindow& window);
	bool Update(std::vector<std::shared_ptr<Zombie>> pool);
	bool fire(sf::RenderWindow& window, float Xpos, float Ypos, std::vector<std::shared_ptr<Zombie>> pool,
	Player& player);
	void movement(std::vector<std::shared_ptr<Zombie>> pool, float x, float y,
	Player& player);
	void SpawnHealth_Pack(sf::Vector2f position);
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
	std::map<int, sf::SoundBuffer> gunBuffer;
};

#endif // GUN_H