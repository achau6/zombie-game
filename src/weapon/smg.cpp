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

void smg::movement()
{
	for(unsigned int i = 0; i < smgs.size(); i ++){
		smgs[i].bullet.move(smgs[i].velocity);
		if(smgs[i].bullet.getPosition().x < 0 || smgs[i].bullet.getPosition().y < 0
		|| smgs[i].bullet.getPosition().x > 2480 || smgs[i].bullet.getPosition().y > 2480){
				smgs.erase(smgs.begin() + i);
			}
	}
}

void smg::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < smgs.size(); i ++){
		window.draw(smgs[i].bullet);
	}
}
