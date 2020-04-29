#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), p1(wdw){

}

GameState::~GameState() {

}

void GameState::Update() {
	p1.movement();
	//g.movement();
	b.looks(*window);
	b.fire(2);
}

void GameState::Render() {
	//g.Draw(*window);
	b.Draw(*window, 2);
	map.Render(window);
	p1.Draw(*window);
}

