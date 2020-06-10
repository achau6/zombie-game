#include "ZombieGame.h"

ZombieGame::ZombieGame(sf::RenderWindow* window) {
	this->window = window;
	image_path = "../zombie-game/content/game_thumbnail.png";
	title = "InfestationZ";
	// initWindow();
	// initStates();
}

// void ZombieGame::initWindow() {
//     // in Windows at least, this must be called before creating the window
// 	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
// 	// Use the screenScalingFactor
// 	window.create(sf::VideoMode(settings.window_width * screenScalingFactor, settings.window_height * screenScalingFactor), "Untitled Zombie Game");
// 	window.setFramerateLimit(144);
// 	platform.setIcon(window.getSystemHandle());
// }

void ZombieGame::initStates() {
	states.push(new GameState(window));
	states.push(new MenuState(window));
	//states.push(new menu_state(window));
	// states.push(new MenuState());
}

ZombieGame::~ZombieGame() {
	while(!states.empty()) {
		delete states.top();
		states.pop();
	}
}

void ZombieGame::Run() {
	// while(window.isOpen()) {
	// 	UpdateEvents();
	// 	Update();
	// 	Render();
	// }
}

void ZombieGame::UpdateEvents(sf::Event& event) {
	// while(window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed:
				window->close();
				break;
		case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					if (MenuActive){
						if (static_cast<MenuState*>(states.top())->checkPress() == 1){
							delete states.top();
							states.pop();
							MenuActive = false;
							static_cast<GameState*>(states.top())->playMusic();
						}
						else if (static_cast<MenuState*>(states.top())->checkPress() == 2)
							window->close();
					}
					else{
						if (static_cast<GameState*>(states.top())->isDead()){
							if (static_cast<GameState*>(states.top())->retry()){
								delete states.top();
								states.pop();
								states.push(new GameState(window));
								static_cast<GameState*>(states.top())->playMusic();
							}
							else if (static_cast<GameState*>(states.top())->quit())
								window->close();
						}
					}
				}

                break;
			case sf::Event::KeyPressed:
				break;
			default:
				break;
		}
	// }
}

void ZombieGame::Update() {
	if (!states.empty())
		states.top()->Update();
}

void ZombieGame::Render() const {
	if (!states.empty()) {
		states.top()->Render();
	}
}

void ZombieGame::start(sf::RenderWindow& window) {
	initStates();
}

void ZombieGame::addEvents(sf::RenderWindow &window) {

}

void ZombieGame::addEvents(const sf::RenderWindow &window, sf::Event& event) {
	UpdateEvents(event);
}

void ZombieGame::draw(sf::RenderTarget &window, sf::RenderStates states) const {
	Render();
}

void ZombieGame::exit() {

}
