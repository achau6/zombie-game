#include "state.h"
#include "TileMap/tilemap.h"
#include "player/player.h"
#include "gun_graphic/bullet.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* wdw);
	virtual ~GameState();
	virtual void Update();
	virtual void Render();
private:
	TileMap map;
	Player p1;
	Bullet b;
};