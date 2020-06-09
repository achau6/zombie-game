#include "gun_entity.h"

void Gun_Entity::fire(Bullet b, std::vector<Bullet> &gun_type, int& fireRate, int maxFireRate, int& currentAmmo, int& maxAmmo)
{
    //std::cout<<
/*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < maxFireRate){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= maxFireRate){
        if(currentAmmo != 0){
            std::cout<<"Fire"<<std::endl;
            gun_type.push_back(b);
            //w.play(1);
            currentAmmo --;
            fireRate = 0;
        } else {
            /*
            Fire stops when no bullet is found either in current ammo or his
            max ammo (stash)
            */
            if(maxAmmo == 0)
            {
                std::cout<<"Rip You got no Ammo"<<std::endl;
            }
            /*
            Adds ammo to his clip if he still has reserve up to the clip
            capacity
            */
            while(maxAmmo > 0 && currentAmmo < 11)
            {
                currentAmmo ++;
                maxAmmo --;
            }
        }
    }


}

void Gun_Entity::movements(std::vector<Bullet> &gun_type, std::vector<std::shared_ptr<Zombie>> pool)
{
/*
checks if bullet exceed map grid
if so remove
*/
	for(unsigned int i = 0; i < gun_type.size(); i ++){
		gun_type[i].bullet.move(gun_type[i].velocity);
		if(gun_type[i].bullet.getPosition().x < 0 || gun_type[i].bullet.getPosition().y < 0
		|| gun_type[i].bullet.getPosition().x > 3500 || gun_type[i].bullet.getPosition().y > 3500){
            gun_type.erase(gun_type.begin() + i);
		} else {

            for(unsigned int j = 0; j < pool.size(); j ++)
            {
                /*
                   checks if bullet touches another entity
                */
                if(collisionCheck(gun_type[i].bullet, pool, j) == true){
                    gun_type.erase(gun_type.begin() + i);
                }

            }
        }
	}
}

bool Gun_Entity::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
{
/*
Get the bounds of the rectangle shape
*/
    sf::FloatRect zombie_entity = pool[count]->getHitbox().getGlobalBounds();
    sf::FloatRect bullet = rect.getGlobalBounds();

/*
Checks the all corners of the rectangle (init x pos, init y pos, width, and length)
it checks a rectangle touches another rectange 'area' then return true
*/
    if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
                return true;
            }

    return false;
}