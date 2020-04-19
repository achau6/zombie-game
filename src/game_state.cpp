#include "game_state.h"

GameState::~GameState() {

}

void GameState::Update() {

}

void GameState::Render() {
	map.Render(window);
}

