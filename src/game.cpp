#include "game.h"

Game::Game() {
	initWindow();
	initStates();
	initView();
}

void Game::initWindow() {
    // in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(settings.window_width * screenScalingFactor, settings.window_height * screenScalingFactor), "Untitled Zombie Game");
	window.setFramerateLimit(144);
	platform.setIcon(window.getSystemHandle());
}

void Game::initStates() {
	states.push(new GameState(&window));
	// states.push(new MenuState());
}

void Game::initView() {
	view.setSize(window.getSize().x, window.getSize().y);
	view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);
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
	// TODO: REMOVE MAGIC NUMBERS
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		view.move(0.f, -10.f);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		view.move(-10.f, 0.f);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		view.move(0.f, 10);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		view.move(10, 0.f);
	}

	if (!states.empty())
		states.top()->Update();
}

void Game::Render() {
	window.clear();
	window.setView(view);
	if (!states.empty())
		states.top()->Render();
	window.setView(window.getDefaultView());
	window.display();
}


