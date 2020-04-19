#include "game_state.h"

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
	sf::View view;
	std::stack<State*> states;
};