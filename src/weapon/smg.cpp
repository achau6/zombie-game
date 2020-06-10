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
    fire(2, b, smgs, fireRate, 14, currentAMMO, maxAMMO);

}

void smg::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
    //movements(smgs, pool);

}

void smg::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < smgs.size(); i ++){
		window.draw(smgs[i].bullet);
	}
}

void smg::add_ammo()
{
    maxAMMO += 15;
}