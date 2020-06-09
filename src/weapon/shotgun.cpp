#include "shotgun.h"

Shotgun::Shotgun()
{
    fireRate = 10;
    maxAMMO = 0;
    currentAMMO = 10;
    shotFire = 0;
}

void Shotgun::push(Bullet b)
{
    fire(b, shotguns, fireRate, 39, currentAMMO, maxAMMO);

    // /*
    // controls how fast the gun is shooting.
    // it takes every 10 counts for the next shot to fire
    // */
    // if(fireRate < 40){
    //     fireRate ++;
    // }
    // /*
    //     Decrease the amount of current bullet in the 'clip' (which is 10)
    // */
    // else if(fireRate >= 39){
    //     if(currentAMMO != 0){
    //             shotguns.push_back(Bullet(b));
    //             w.play(4);
    //             currentAMMO --;
    //             fireRate = 0;

    //     } else {
    //         /*
    //         Fire stops when no bullet is found either in current ammo or his
    //         max ammo (stash)
    //         */
    //         if(maxAMMO == 0)
    //         {
    //             std::cout<<"Rip You got no Ammo"<<std::endl;
    //         }
    //         /*
    //         Adds ammo to his clip if he still has reserve up to the clip
    //         capacity
    //         */
    //         while(maxAMMO > 0 && currentAMMO < 11)
    //         {
    //             currentAMMO ++;
    //             maxAMMO --;
    //         }
    //     }
    // }

}

void Shotgun::movement(std::vector<std::shared_ptr<Zombie>> pool)
{
    movements(shotguns, pool);

	// for(unsigned int i = 0; i < shotguns.size(); i ++){
	// 	shotguns[i].bullet.move(shotguns[i].velocity);
	// 	if(shotguns[i].bullet.getPosition().x < 0 || shotguns[i].bullet.getPosition().y < 0
	// 	|| shotguns[i].bullet.getPosition().x > 2480 || shotguns[i].bullet.getPosition().y > 2480){
    //         shotguns.erase(shotguns.begin() + i);
	// 	} else {

    //         for(unsigned int j = 0; j < pool.size(); j ++)
    //         {
    //             if(collisionCheck(shotguns[i].bullet, pool, j) == true){
    //                 shotguns.erase(shotguns.begin() + i);
    //                 std::cout<<"WORK DAMMIT!!!!!!"<<std::endl;
    //             }

    //         }
    //     }
	// }
}

// bool Shotgun::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
// {
//     sf::FloatRect zombie_entity = pool[count]->getHitbox().getGlobalBounds();
//     sf::FloatRect bullet = rect.getGlobalBounds();


//     if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
// 			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
// 			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
// 			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
//                 return true;
//             }

//     return false;
// }
void Shotgun::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < shotguns.size(); i ++){
		window.draw(shotguns[i].bullet);
	}
}

void Shotgun::add_ammo()
{
    maxAMMO += 5;
}