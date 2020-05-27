#include "../State/game_state.h"
#include "weapon/smg.h"
#include "gun_graphic/bullet.h"
#include "../DaveStation/Game/Game.h"
#include "GameSettings.h"

// TODO: add delta time so high fps will not mess up the game

class ZombieGame : public Game{
public:
	ZombieGame(sf::RenderWindow* window);
	~ZombieGame();
	void Run();
	void UpdateEvents(sf::Event& event);
	void Update();
	void Render() const;

	void start(sf::RenderWindow& window);
    void addEvents(sf::RenderWindow &window);
    void addEvents(const sf::RenderWindow &window, sf::Event& event);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void exit();

private:
	// void initWindow();
	void initStates();
	bool MenuActive = true;
	util::Platform platform;
	sf::RenderWindow* window;
	// sf::Event* event;
	std::stack<State*> states;
	GameSettings settings;
};