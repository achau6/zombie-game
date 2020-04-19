#include "state.h"
#include "TileMap/tilemap.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* wdw) : State(wdw){}
	virtual ~GameState();
	virtual void Update();
	virtual void Render();
private:
	TileMap map;
};