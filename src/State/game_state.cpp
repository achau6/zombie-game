#include "game_state.h"

GameState::GameState(sf::RenderWindow* wdw)
	: State(wdw), map(game_textures), p1(wdw), camera(wdw) {
		initMousePositions();
		font.loadFromFile("content/arial.ttf");
		cord_pos.setFont(font);
		cord_pos.setFillColor(sf::Color::White);
		size_t char_size = 15;
		cord_pos.setCharacterSize(char_size);
		SpawnZombies();
		initUISprites();
		SpawnHealth_Pack();
		SpawnAmmo_Pack();
		zombie_pool.FindPlayer(p1, map);
}

GameState::~GameState() {

}

void GameState::SpawnZombies() {
	//TODO: WAVE SYSTEM
	// Gridsize * grid position = pixelcoords
	zombie_pool.Spawn(sf::Vector2f(map.getGridSize().x * 2, map.getGridSize().y * 2), game_textures, map);
}

void GameState::SpawnHealth_Pack() {
	health.spawn_pack(sf::Vector2f(300, 300));
}

void GameState::SpawnAmmo_Pack() {
	ammo.spawn_pack(sf::Vector2f(500, 500));
}

void GameState::Update() {
	// Moves the player
	p1.movement();
	zombie_pool.Movement();
	health.movement(p1.getHitbox());
	ammo.movement(p1.getHitbox());

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
	if (g.fire(*window, p1.getPosition().x, p1.getPosition().y, zombie_pool.GetPool()) == true)
		p1.shootGun(g.getGlobalIdentifier());

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
	//Sets HP, ammo counter, zombies left, and Wave number, UI stuff
	ss << "HP: " << p1.getHP() << std::setw(150) << g.getAmmo().first << "/" << g.getAmmo().second;
	UI[0].setString(ss.str());
	ss.str("");
	//change the numbers when the wave and zombie functions are added
	ss << "Wave Number: " << 5 << "\n";
	ss << "Zombies Left: " << 30;
	UI[1].setString(ss.str());
	ss.str("");
	sf::Vector2f mousePosition;
	crosshair.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
	changeWeaponIcons();
	// this will always be at the end
	window->setView(camera.getCamView());
}

void GameState::Render() {
	// GAME VIEW
	map.Render(window);
	health.Draw(*window);
	ammo.Draw(*window);
	p1.Draw(*window);
	/*
	This is complete overhaul of my code
	I switch to using vectors as I had trouble to individually remove the bullets
	when it goes off screen because it deleted entire bullet list.
	Will continue working on getting the list to work and switch it back
	*/
	g.Draw(*window);

	zombie_pool.Render(*window);

	// UI/WINDOW VIEW (SO TEXT DOESNT MOVE WITH CAM)
	window->setView(window->getDefaultView());
	// Draws stats onto window view
	window->draw(cord_pos);
	window->draw(UI[0]);
	window->draw(UI[1]);
	window->draw(crosshair);
	window->draw(healthIcon);
	window->draw(BulletIcon);
	window->draw(GunIcon);
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

void GameState::initUISprites(){
	csfont.loadFromFile("content/cs_regular.ttf");
	UI[0].setFont(csfont);
	UI[1].setFont(csfont);
	UI[0].setFillColor(sf::Color::White);
	UI[1].setFillColor(sf::Color::White);
	UI[0].setCharacterSize(45);
	UI[0].setPosition(window->getSize().x * .05, window->getSize().y * .94);
	UI[1].setCharacterSize(35);
	UI[1].setPosition(window->getSize().x * .85, 0);

	CrosshairTexture.loadFromFile("../zombie-game/content/crosshair.png");
	//window->setMouseCursor(CrosshairTexture);
	crosshair.setTexture(CrosshairTexture);
	crosshair.setScale(.08, .08);
	crosshair.setOrigin(75, 75);

	HealthTexture.loadFromFile("../zombie-game/content/hpicon.png");
	healthIcon.setTexture(HealthTexture);
	healthIcon.setScale(.1, .1);
	healthIcon.setPosition(0, window->getSize().y * .93);

	BulletTexture.loadFromFile("../zombie-game/content/bulletIcon.png");
	BulletIcon.setTexture(BulletTexture);
	BulletIcon.setPosition(window->getSize().x * .85, window->getSize().y * .93);
	BulletIcon.setScale(.15, .15);

	std::shared_ptr<sf::Texture> akicon = std::make_shared<sf::Texture>();
	std::shared_ptr<sf::Texture> pistolicon = std::make_shared<sf::Texture>();
	std::shared_ptr<sf::Texture> knifeicon = std::make_shared<sf::Texture>();
	std::shared_ptr<sf::Texture> shotgunicon = std::make_shared<sf::Texture>();
	game_textures.insert(std::make_pair("rifle", akicon));
	game_textures.insert(std::make_pair("pistol", pistolicon));
	game_textures.insert(std::make_pair("knife", knifeicon));
	game_textures.insert(std::make_pair("shotgun", shotgunicon));
	game_textures["rifle"]->loadFromFile("content/AkIcon.png");
	game_textures["pistol"]->loadFromFile("content/PistolIcon.png");
	game_textures["knife"]->loadFromFile("content/KnifeIcon.png");
	game_textures["shotgun"]->loadFromFile("content/shotgunIcon.png");
	GunIcon.setTexture(*game_textures["knife"].get());
	GunIcon.setPosition(window->getSize().x * .95, window->getSize().y * .88);
	GunIcon.setScale(.1, .1);
}

void GameState::changeWeaponIcons(){
	switch (g.getGlobalIdentifier()){
		case 0:
			GunIcon.setTexture(*game_textures["knife"]);
			GunIcon.setPosition(window->getSize().x * .88, window->getSize().y * .85);
			GunIcon.setScale(.2, .2);
			break;
		case 1:
			GunIcon.setTexture(*game_textures["pistol"]);
			GunIcon.setPosition(window->getSize().x * .85, window->getSize().y * .88);
			GunIcon.setScale(.25, .25);
			break;
		case 3:
			GunIcon.setTexture(*game_textures["rifle"]);
			GunIcon.setPosition(window->getSize().x * .85, window->getSize().y * .88);
			GunIcon.setScale(.3, .3);
			break;
		case 4:
			GunIcon.setTexture(*game_textures["shotgun"]);
			GunIcon.setPosition(window->getSize().x * .85, window->getSize().y * .88);
			GunIcon.setScale(.8, .8);
			break;
	}
}
