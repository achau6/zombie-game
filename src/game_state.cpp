#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), p1(wdw), camera(wdw) {
		initMousePositions();
		font.loadFromFile("content/arial.ttf");
		cord_pos.setFont(font);
		cord_pos.setFillColor(sf::Color::White);
		// TODO: REMOVE MAGIC NUMS 15
		cord_pos.setCharacterSize(15);
}

GameState::~GameState() {

}

void GameState::Update() {
	p1.movement();
	camera.UpdateCam(p1.getPosition());

	// p1.getGridPosition(map.getGridSize()).x;

	//g.movement();
	p1.look(*window);
	//sf::Vector2f temp = sf::Vector2f(floatcamera.getCamView());
	b.fire(2, *window, p1.getPositionX(), p1.getPositionY());

	// also updates the current mouse positions for the grid
	initMousePositions();

	ss << "Screen: " << mouse_pos_screen.x << " " << mouse_pos_screen.y << "\n";
	ss << "Window: " << mouse_pos_window.x << " " << mouse_pos_window.y << "\n";
	ss << "Character: " << p1.getPositionX() <<" " << p1.getPositionY() << std::endl;
	ss << "View: " << mouse_pos_view.x << " " << mouse_pos_view.y << "\n";
	ss << "Grid: " << p1.getGridPosition(map.getGridSize()).x << " " << p1.getGridPosition(map.getGridSize()).y << "\n";
	cord_pos.setString(ss.str());
	// clearing string stream
	ss.str("");

	window->setView(camera.getCamView());
}

void GameState::Render() {
	// GAME VIEW
	map.Render(window);
	p1.Draw(*window);
	b.Draw(*window, 2);

	// UI VIEW (SO TEXT DOESNT MOVE WITH CAM)
	window->setView(window->getDefaultView());
	window->draw(cord_pos);
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
