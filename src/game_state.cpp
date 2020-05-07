#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), p1(wdw), camera(wdw) {
		initMousePositions();
		font.loadFromFile("content/arial.ttf");
		cord_pos.setFont(font);
		cord_pos.setFillColor(sf::Color::White);
		cord_pos.setCharacterSize(30);
}

GameState::~GameState() {

}

void GameState::Update() {
	p1.movement();
	camera.UpdateCam(p1.getPosition());

	// p1.getGridPosition(map.getGridSize()).x;

	//g.movement();
	b.looks(*window);
	b.fire(2, *window);

	// also updates the current mouse positions for the grid
	initMousePositions();

	ss << "Screen: " << mouse_pos_screen.x << " " << mouse_pos_screen.y << "\n";
	ss << "Window: " << mouse_pos_window.x << " " << mouse_pos_window.y << "\n";
	ss << "View: " << mouse_pos_view.x << " " << mouse_pos_view.y << "\n";
	ss << "Grid: " << p1.getGridPosition(map.getGridSize()).x << " " << p1.getGridPosition(map.getGridSize()).y << "\n";

	cord_pos.setString(ss.str());
	// clearing string stream
	ss.str("");

	window->setView(camera.getCamView());
}

void GameState::Render() {
	// g.Draw(*window);
	map.Render(window);
	p1.Draw(*window);
	b.Draw(*window, 2);
	window->draw(cord_pos);
	// window->setView(window->getDefaultView());
}

void GameState::initMousePositions() {
	mouse_pos_screen = sf::Mouse::getPosition();
	mouse_pos_window = sf::Mouse::getPosition(*window);
	mouse_pos_view = window->mapPixelToCoords(mouse_pos_window);
	if(mouse_pos_view.x > 0)
		mouse_pos_grid.x = mouse_pos_view.x / map.getGridSize().x;
	if(mouse_pos_view.y > 0)
		mouse_pos_grid.y = mouse_pos_view.y / map.getGridSize().y;
}

