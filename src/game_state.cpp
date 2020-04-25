#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), p1(window) {

}

GameState::~GameState() {

}

void GameState::Update() {
}

void GameState::Render() {
	map.Render(window);
	p1.movement();
	p1.Draw(*window);
}

