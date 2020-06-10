#include "pistol.h"

pistol::pistol() : weapons(21, 16, 0, 10000, 0, 1)//fireRate(21), maxAMMO(0), currentAMMO(10000), shotFire(0)
{}

// void pistol::push(Bullet b)
// {
//     fire(b, pistols, fireRate, 16, currentAMMO, maxAMMO);

    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    // if(fireRate < 16){
    //     fireRate ++;
    // }
    // /*
    //     Decrease the amount of current bullet in the 'clip' (which is 10)
    // */
    // else if(fireRate >= 16){
    //     if(currentAMMO != 0){
    //         std::cout<<"Fire"<<std::endl;
    //         pistols.push_back(b);
    //         w.play(1);
    //         currentAMMO --;
    //         fireRate = 0;
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

//}

// void pistol::movement(std::vector<std::shared_ptr<Zombie>> pool)
// {
//     movements(pistols, pool);
// /*
// checks if bullet exceed map grid
// if so remove
// */
// 	for(unsigned int i = 0; i < pistols.size(); i ++){
// 		pistols[i].bullet.move(pistols[i].velocity);
// 		if(pistols[i].bullet.getPosition().x < 0 || pistols[i].bullet.getPosition().y < 0
// 		|| pistols[i].bullet.getPosition().x > 3500 || pistols[i].bullet.getPosition().y > 3500){
//             pistols.erase(pistols.begin() + i);
// 		} else {

//             for(unsigned int j = 0; j < pool.size(); j ++)
//             {
//                 /*
//                    checks if bullet touches another entity
//                 */
//                 if(collisionCheck(pistols[i].bullet, pool, j) == true){
//                     pistols.erase(pistols.begin() + i);
//                 }

//             }
//         }
// 	}
//}

// bool pistol::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
// {
// /*
// Get the bounds of the rectangle shape
// */
//     sf::FloatRect zombie_entity = pool[count]->getHitbox().getGlobalBounds();
//     sf::FloatRect bullet = rect.getGlobalBounds();

// /*
// Checks the all corners of the rectangle (init x pos, init y pos, width, and length)
// it checks a rectangle touches another rectange 'area' then return true
// */
//     if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
// 			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
// 			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
// 			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
//                 return true;
//             }

//     return false;
//}
// void pistol::Draw(sf::RenderWindow& window)
// {
// 	for(unsigned int i = 0; i < pistols.size(); i ++){
// 		window.draw(pistols[i].bullet);
// 	}
// }

// void pistol::add_ammo()
// {
//     maxAMMO += 15;
// }