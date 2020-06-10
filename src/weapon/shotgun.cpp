#include "shotgun.h"

Shotgun::Shotgun()
{
    fireRate = 10;
    maxAMMO = 0;
    currentAMMO = 10;
    flag = false;
}

void Shotgun::push(Bullet b)
{
    if(flag_check() == true){
        maxAMMO += 15;
        flag = false;
    }
    fire(4, b, shotguns, fireRate, 39, currentAMMO, maxAMMO);

}

void Shotgun::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
    //movements(shotguns, pool);

}


void Shotgun::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < shotguns.size(); i ++){
		window.draw(shotguns[i].bullet);
	}
}

void Shotgun::add_ammo()
{
    flag = true;
}