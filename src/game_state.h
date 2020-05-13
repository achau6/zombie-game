#include "state.h"
#include "TileMap/tilemap.h"
#include "player/player.h"
#include "camera.h"
#include "gun_graphic/gun.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* wdw);
	virtual ~GameState();
	virtual void Update();
	virtual void Render();
private:
	void initMousePositions();

	TileMap map;
	Player p1;
	Gun g;
	Camera camera;

	sf::Vector2i mouse_pos_screen;
	sf::Vector2i mouse_pos_window;
	sf::Vector2f mouse_pos_view;
	sf::Vector2u mouse_pos_grid;
	sf::Font font;
	sf::Text cord_pos;
	std::stringstream ss;
};