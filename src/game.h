#include "game_state.h"
#include "GameSettings.h"

// TODO: add delta time so high fps will not mess up the game
// FIXME: bug where rapidly pressing a movement key moves character a small amount.

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
	void initView();

	util::Platform platform;
	sf::RenderWindow window;
	sf::Event event;
	sf::View view;
	std::stack<State*> states;
	GameSettings settings;
};