// #include "EntityCollision.h"

// void EntityCollision::Update(Player& player, EntityPool& pool, TileMap& map) {
// 	for(size_t x = 0; x < map.getGridSize().x; x++) {
// 		for(size_t y = 0; y < map.getGridSize().y; y++) {
// 			for(size_t z = 0; z < map.GetLayers(); z++) {
// 				if(map.GetGameMap()[x][y][z] != nullptr) {
// 					if(map.GetGameMap()[x][y][z]->isType() == "wall") {
// 						std::static_pointer_cast<Wall>(map.GetGameMap()[x][y][z])->isCollision(player);
// 						// checking the zombie pool for collision
// 						for(auto zombies : pool.GetPool()) {
// 							std::static_pointer_cast<Wall>(map.GetGameMap()[x][y][z])->isCollision(*zombies);
// 							// std::cout << "zombie col";
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// }