#include "smg.h"


smg::smg()
{
    fireRate = 10;
    maxAMMO = 0;
    currentAMMO = 10;
    shotFire = 0;
}

void smg::push(Bullet b)
{
    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < 14){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= 14){
        if(currentAMMO != 0){
            smgs.push_back(Bullet(b));
            w.play(2);
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

void smg::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
	for(unsigned int i = 0; i < smgs.size(); i ++){
		smgs[i].bullet.move(smgs[i].velocity);
		if(smgs[i].bullet.getPosition().x < 0 || smgs[i].bullet.getPosition().y < 0
		|| smgs[i].bullet.getPosition().x > 3500 || smgs[i].bullet.getPosition().y > 3500){
            smgs.erase(smgs.begin() + i);
		} else {

            for(unsigned int j = 0; j < pool.size(); j ++)
            {
                if(collisionCheck(smgs[i].bullet, pool, j) == true){
                    smgs.erase(smgs.begin() + i);
                    std::cout<<"WORK DAMMIT!!!!!!"<<std::endl;
                }

            }
        }
	}
}

bool smg::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
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
void smg::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < smgs.size(); i ++){
		window.draw(smgs[i].bullet);
	}
}