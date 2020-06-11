//#include "gun_entity.h"

// Gun_Entity::Gun_Entity(){
//     DupeMap();
// }
// void Gun_Entity::fire(int identifier, Bullet b, std::vector<Bullet> &gun_type, int& fireRate, int maxFireRate, int& currentAmmo, int& maxAmmo)
// {
//     int reloadTime = 0;
// /*
//     controls how fast the gun is shooting.
//     it takes every 10 counts for the next shot to fire
//     */
//     if(fireRate < maxFireRate){
//         fireRate ++;
//     }
//     /*
//         Decrease the amount of current bullet in the 'clip' (which is 10)
//     */
//     else if(fireRate >= maxFireRate){
//         if(currentAmmo != 0){
//             gun_type.push_back(b);
//             w.play(identifier);
//             currentAmmo --;
//             fireRate = 0;
//         } else {
//             /*
//             Fire stops when no bullet is found either in current ammo or his
//             max ammo (stash)
//             */
//             if(maxAmmo == 0)
//             {
//                 //std::cout<<"Rip You got no Ammo"<<std::endl;
//             }
//             /*
//             Adds ammo to his clip if he still has reserve up to the clip
//             capacity
//             */


//             while(maxAmmo > 0 && currentAmmo < 11)
//             {
//                 // time_t start = time(0);
//                 // clock_t end = clock() + 5 * CLOCKS_PER_SEC;
//                 // double seconds_pass = difftime(time(0), start);

//                 //if(seconds_pass > end){
//                     currentAmmo ++;
//                     maxAmmo --;
//                 //}
//             }
//         reloadTime = 0;

//         }
//     }


// }

// void Gun_Entity::DupeMap()
// {
//     std::pair<sf::Vector2f, std::string> hold;
// 	for(size_t x = 0; x < grid_size.x; x++) {
// 		for(size_t y = 0; y < grid_size.y; y++) {
//             if(level[x][y] == 1){
//                 hold = std::make_pair(sf::Vector2f(x*tile_size.x, y*tile_size.y), "WALL");
//             } else {
//                 hold = std::make_pair(sf::Vector2f(x*tile_size.x, y*tile_size.y), "DIRT");
//             }
//             second_map_dupe.push_back(hold);

// 		}
//         game_map.push_back(second_map_dupe);
//     }
// }
// void Gun_Entity::movements(std::vector<Bullet> &gun_type, std::vector<std::shared_ptr<Zombie>> pool)
// {

//                 //std::cout<<"FUck: "<<getTileSize().x<<std::endl;

// /*
// checks if bullet exceed map grid
// if so remove
// */
// 	for(unsigned int i = 0; i < gun_type.size(); i ++){
//        // std::cout<<"FUCKKKKKKKKK"<<game_map[1][1].second<<std::endl;
// 		gun_type[i].bullet.move(gun_type[i].velocity);

//         for(size_t x = 0; x < getGridSize().x; x++) {
//             for(size_t y = 0; y < getGridSize().y; y++) {
//                 if(game_map[x][y].second == "wall") {
//                         std::cout<<"WHY AM I USELESS: "<<std::endl;
//                     if(gun_type[i].bullet.getPosition().x < game_map[x][y].first.x || gun_type[i].bullet.getPosition().y < game_map[x][y].first.y
//                     ||gun_type[i].bullet.getPosition().x > game_map[x][y].first.x || gun_type[i].bullet.getPosition().y > game_map[x][y].first.y) {
//                         gun_type.erase(gun_type.begin() + i);
//                         std::cout<<"working: "<<std::endl;
//                     }
//                 }

//              }
//        }


//         if(gun_type[i].bullet.getPosition().x < 0 || gun_type[i].bullet.getPosition().y < 0
// 		|| gun_type[i].bullet.getPosition().x > 3500 || gun_type[i].bullet.getPosition().y > 3500){
//             gun_type.erase(gun_type.begin() + i);
// 		} else {

//             for(unsigned int j = 0; j < pool.size(); j ++)
//             {
//                 /*
//                    checks if bullet touches another entity
//                 */
//                 if(collisionCheck(gun_type[i].bullet, pool, j) == true){
//                     gun_type.erase(gun_type.begin() + i);
//                 }

//             }
//         }
// 	}
// }

// bool Gun_Entity::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
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
// }


// bool Gun_Entity::collisionChecks(sf::RectangleShape rect)
// {

//     //return t.tileToBulletCollision(rect.getGlobalBounds());
// // /*
// // Get the bounds of the rectangle shape
// // */
// //     sf::FloatRect tile = pool;
// //     sf::FloatRect bullet = rect.getGlobalBounds();

// // /*
// // Checks the all corners of the rectangle (init x pos, init y pos, width, and length)
// // it checks a rectangle touches another rectange 'area' then return true
// // */
// //  std::cout<<"NIGGGGGGGGG:::::G "<<getTileSize().x<<std::endl;

// //     if(tile.intersects(bullet)){
// //                  std::cout<<"NIGGGGGGGGGG"<<std::endl;
// //                 return true;
// //             }

// //     return false;
// }