#ifndef PISTOL_H
#define PISTOL_H
#include <iostream>
#include <vector>
#include "gun_graphic/bullet.h"
#include "Entities/entity_pool.h"
#include "gun_entity.h"
#include "TileMap/tilemap.h"

class pistol : public Gun_Entity
{
public:
//contructors
	pistol();
//typedef
	Bullet b;
	weapons w;
	//Gun_Entity gun;
//mutators
	void push(Bullet b);
	void movement(std::vector<std::shared_ptr<Zombie>> pool);
	void Draw(sf::RenderWindow& window);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);
	void add_ammo();

//accessors
	int get_Current_Ammo() { return currentAMMO;}
	int getCurrentAmmo() {return currentAMMO;}
	int getMaxAmmo() {return maxAMMO;}
	bool flag_check(){return flag;}


private:
	bool flag;
	int maxAMMO;
	int fireRate;
	int currentAMMO;
	std::vector<Bullet> pistols;
};

#endif // PISTOL_H