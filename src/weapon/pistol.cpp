#include "pistol.h"

pistol::pistol()
{
    //how fast it shoots
    fireRate = 0;
    //max ammo guy has
    maxAMMO = 0;
    //how much ammo he has
    currentAMMO = 10;
    shotFire = 0;
}

void pistol::push(Bullet b)
{
    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < 16){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= 16){
        if(currentAMMO != 0){
            std::cout<<"Fire"<<std::endl;
            pistols.push_back(b);
            w.play(1);
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

void pistol::movement()
{
	for(unsigned int i = 0; i < pistols.size(); i ++){
		pistols[i].bullet.move(pistols[i].velocity);
		if(pistols[i].bullet.getPosition().x < 0 || pistols[i].bullet.getPosition().y < 0
		|| pistols[i].bullet.getPosition().x > 2480 || pistols[i].bullet.getPosition().y > 2480){
				pistols.erase(pistols.begin() + i);
			}
	}
}

void pistol::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < pistols.size(); i ++){
		window.draw(pistols[i].bullet);
	}
}
