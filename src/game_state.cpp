#include "game_state.h"

GameState::~GameState() {

}

void GameState::Update() {
}

void GameState::Render() {
	window->setFramerateLimit(60);
	// while(window->isOpen())
	// {
		//map.Render(window);
		p1.movement();
		//g.movement();
		p1.Draw(*window);
		//g.Draw(*window);
		b.looks(*window);
		b.fire(2);
		b.Draw(*window, 2);
	//}

}

