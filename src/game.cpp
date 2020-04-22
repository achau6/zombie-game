#include "game.h"

Game::Game() {
	initWindow();
	initStates();
}

Game::~Game() {
	while(!states.empty()) {
		delete states.top();
		states.pop();
	}
}

void Game::Run() {
	while(window.isOpen()) {
		UpdateEvents();
		Update();
		Render();
	}
}

void Game::UpdateEvents() {
	while(window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				std::cout << "Mouse Button Pressed" << std::endl;
				break;
			case sf::Event::KeyPressed:
				break;
			default:
				break;
		}
	}
}

void Game::Update() {

}

void Game::Render() {
	window.clear();
	window.setView(view);
	if (!states.empty())
		states.top()->Render();
	window.display();
}

void Game::initWindow() {
    // in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1280 * screenScalingFactor, 720 * screenScalingFactor), "Untitled Zombie Game");
	window.setFramerateLimit(60);
	platform.setIcon(window.getSystemHandle());
}

void Game::initStates() {
	states.push(new GameState(&window));
	// states.push(new MenuState());
}

