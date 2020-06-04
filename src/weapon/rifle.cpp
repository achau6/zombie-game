#include "rifle.h"

rifle::rifle()
{
    fireRate = 21;
    maxAMMO = 0;
    currentAMMO = 15;
    shotFire = 0;
}

void rifle::push(Bullet b)
{
    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < 21){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= 20){
        if(currentAMMO != 0){
            rifles.push_back(Bullet(b));
			w.play(3);
            currentAMMO --;
            fireRate = 0;
        } else {
            /*
            Fire stops when no bullet is found either in current ammo or his
            max ammo (stash)
            */
            if(maxAMMO == 0)
            {
                std::cout<<"Rip You got no Ammo"<<std::endl;
            }
            /*
            Adds ammo to his clip if he still has reserve up to the clip
            capacity
            */
            while(maxAMMO > 0 && currentAMMO < 11)
            {
                currentAMMO ++;
                maxAMMO --;
            }
        }
    }

}

void rifle::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
	for(unsigned int i = 0; i < rifles.size(); i ++){
		rifles[i].bullet.move(rifles[i].velocity);
		if(rifles[i].bullet.getPosition().x < 0 || rifles[i].bullet.getPosition().y < 0
		|| rifles[i].bullet.getPosition().x > 2480 || rifles[i].bullet.getPosition().y > 2480){
            rifles.erase(rifles.begin() + i);
		} else {

            for(unsigned int j = 0; j < pool.size(); j ++)
            {
                if(collisionCheck(rifles[i].bullet, pool, j) == true){
                    rifles.erase(rifles.begin() + i);
                    std::cout<<"WORK DAMMIT!!!!!!"<<std::endl;
                }

            }
        }
	}
}

bool rifle::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
{
    sf::FloatRect zombie_entity = pool[count]->getHitbox().getGlobalBounds();
    sf::FloatRect bullet = rect.getGlobalBounds();


    if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
                return true;
            }

    return false;
}
void rifle::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < rifles.size(); i ++){
		window.draw(rifles[i].bullet);
	}
}
