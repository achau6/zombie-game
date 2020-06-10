#ifndef Gun_Entity_H
#define Gun_Entity_H
#include "Entities/entity_pool.h"
#include "gun_graphic/bullet.h"
#include "weapon.h"
#include "TileMap/tilemap.h"

class Gun_Entity{
public:
	void fire(Bullet b, std::vector<Bullet> &gun_type, int& fireRate, int maxFireRate, int& currentAmmo, int& maxAmmo);
	void movements(std::vector<Bullet> &gun_type, std::vector<std::shared_ptr<Zombie>> pool);
	bool collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count);


protected:
private:
};
#endif // Gun_Entity_H