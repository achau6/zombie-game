#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "TileMap/tilemap.h"
#include "player/player.h"
#include "Camera/camera.h"
#include "gun_graphic/gun.h"
#include "weapon/weapon_utility/health_pack.h"
#include "weapon/weapon_utility/ammo.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* wdw);
	~GameState();
	void Update();
	void Render();
	EntityPool zombie_pool;


private:
	void initMousePositions();
	void SpawnZombies();
	void SpawnHealth_Pack();
	void SpawnAmmo_Pack();


	TileMap map;
	//EntityPool zombie_pool;
	Player p1;
	Gun g;
	Camera camera;
	Health health;
	Ammo_Box ammo;
	sf::Vector2i mouse_pos_screen;
	sf::Vector2i mouse_pos_window;
	sf::Vector2f mouse_pos_view;
	sf::Vector2u mouse_pos_grid;
	sf::Font font;
	sf::Text cord_pos;
	std::stringstream ss;
};
#endif // GAME_STATE_H