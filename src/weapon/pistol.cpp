#include "pistol.h"

pistol::pistol()
{
    //how fast it shoots
    fireRate = 0;
    //max ammo guy has
    maxAMMO = 10;
    //how much ammo he has
    currentAMMO = 20;
    flag = false;
}

void pistol::push(Bullet b)
{
    if(flag_check() == true){
        maxAMMO += 25;
        flag = false;
    }
    fire(1, b, pistols, fireRate, 16, currentAMMO, maxAMMO);

}

void pistol::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
    movements(pistols, pool);

}


void pistol::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < pistols.size(); i ++){
		window.draw(pistols[i].bullet);
	}
}


void pistol::add_ammo()
{
    flag = true;
}

