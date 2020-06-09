#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), map(game_textures), p1(wdw), camera(wdw) {
		initMousePositions();
		font.loadFromFile("content/arial.ttf");
		cord_pos.setFont(font);
		cord_pos.setFillColor(sf::Color::White);
		// TODO: REMOVE MAGIC NUMS 15
		size_t char_size = 15;
		cord_pos.setCharacterSize(char_size);
		SpawnZombies();
		SpawnHealth_Pack();
		zombie_pool.FindPlayer(p1, map);
}

GameState::~GameState() {

}

void GameState::SpawnZombies() {
	//TODO: WAVE SYSTEM
	// Gridsize * grid position = pixelcoords
	zombie_pool.Spawn(sf::Vector2f(map.getGridSize().x * 10, map.getGridSize().y * 10), game_textures, map);
}

void GameState::SpawnHealth_Pack() {
	health.spawn_pack(sf::Vector2f(300, 300));
}

void GameState::Update() {
	// Moves the player
	p1.movement();
	zombie_pool.Movement();
	health.movement(p1.getHitbox());

	// map update checks for collision and sets velocity to 0 if collision occurs
	map.Update(p1, zombie_pool);
	// EntityCollision::Update(p1, zombie_pool, map);

	p1.changeGun(g.getGlobalIdentifier());
	p1.look(*window);

	// Updates player position (can do other stuff if needed)
	p1.Update();
	zombie_pool.Update(p1);
	// zombie_pool.Update(p1, map);

	camera.UpdateCam(p1.getPosition());

	/*
	This is complete overhaul of my code
	I switch to using vectors as I had trouble to individually remove the bullets
	when it goes off screen because it deleted entire bullet list.
	Will continue working on getting the list to work and switch it back
	*/
	g.fire(*window, p1.getPosition().x, p1.getPosition().y, zombie_pool.GetPool(), p1);

	// also updates the current mouse positions for the grid
	initMousePositions();

	ss << "Screen: " << mouse_pos_screen.x << " " << mouse_pos_screen.y << "\n";
	ss << "Window: " << mouse_pos_window.x << " " << mouse_pos_window.y << "\n";
	ss << "Character: " << p1.getPosition().x <<" " << p1.getPosition().y << std::endl;
	ss << "View: " << mouse_pos_view.x << " " << mouse_pos_view.y << "\n";
	ss << "Grid: " << p1.getGridPosition(map.getGridSize()).x << " " << p1.getGridPosition(map.getGridSize()).y << "\n";
	cord_pos.setString(ss.str());
	// clearing string stream
	ss.str("");

	// this will always be at the end
	window->setView(camera.getCamView());
}

void GameState::Render() {
	// GAME VIEW
	map.Render(window);
	p1.Draw(*window);
	/*
	This is complete overhaul of my code
	I switch to using vectors as I had trouble to individually remove the bullets
	when it goes off screen because it deleted entire bullet list.
	Will continue working on getting the list to work and switch it back
	*/
	g.Draw(*window, g.GLOBALIDENTIFIER);
	health.Draw(*window);

	zombie_pool.Render(*window);

	// UI/WINDOW VIEW (SO TEXT DOESNT MOVE WITH CAM)
	window->setView(window->getDefaultView());
	// Draws stats onto window view
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
