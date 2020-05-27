#include "menu_state.h"
#include "game_state.h"
#include "weapon/smg.h"
#include "gun_graphic/bullet.h"
#include "GameSettings.h"
#include <typeinfo>

// TODO: add delta time so high fps will not mess up the game

class Game {
public:
	Game();
	~Game();
	void Run();
	void UpdateEvents();
	void Update();
	void Render();

private:
	void initWindow();
	void initStates();

	util::Platform platform;
	sf::RenderWindow window;
	sf::Event event;
	std::stack<State*> states;
	GameSettings settings;
};