#include "rifle.h"

rifle::rifle()
{
    fireRate = 21;
    maxAMMO = 0;
    currentAMMO = 15;
    flag = false;
}

void rifle::push(Bullet b)
{
    if(flag_check() == true){
        maxAMMO += 5;
        flag = false;
    }
    fire(3, b, rifles, fireRate, 21, currentAMMO, maxAMMO);


}

void rifle::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
    //movements(rifles, pool);
}


void rifle::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < rifles.size(); i ++){
		window.draw(rifles[i].bullet);
	}
}

void rifle::add_ammo()
{
    flag = true;
}

