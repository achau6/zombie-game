#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), p1(wdw){

}

GameState::~GameState() {

}

void GameState::Update() {
	p1.movement();
}

void GameState::Render() {
	map.Render(window);
	p1.Draw(*window);
}

