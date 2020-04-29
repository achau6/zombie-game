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
<<<<<<< HEAD
	player p1;
	Bullet b;

=======
	Player p1;
>>>>>>> map
};