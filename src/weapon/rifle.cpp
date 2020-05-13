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

void rifle::movement()
{
	for(unsigned int i = 0; i < rifles.size(); i ++){
		rifles[i].bullet.move(rifles[i].velocity);
		if(rifles[i].bullet.getPosition().x < 0 || rifles[i].bullet.getPosition().y < 0
		|| rifles[i].bullet.getPosition().x > 2480 || rifles[i].bullet.getPosition().y > 2480){
				rifles.erase(rifles.begin() + i);
			}
	}
}

void rifle::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < rifles.size(); i ++){
		window.draw(rifles[i].bullet);
	}
}
