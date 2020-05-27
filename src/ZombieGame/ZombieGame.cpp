#include "ZombieGame.h"

ZombieGame::ZombieGame(sf::RenderWindow* window) {
	this->window = window;
	image_path = "../zombie-game/content/game_thumbnail.png";
	title = "InfestionZ";
	// initWindow();
	// initStates();
}

// void ZombieGame::initWindow() {
//     // in Windows at least, this must be called before creating the window
// 	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
// 	// Use the screenScalingFactor
// 	window.create(sf::VideoMode(settings.window_width * screenScalingFactor, settings.window_height * screenScalingFactor), "Untitled Zombie Game");
// 	window.setFramerateLimit(144);
// 	platform.setIcon(window.getSystemHandle());
// }

void ZombieGame::initStates() {
	states.push(new GameState(window));
	states.push(new MenuState(window));
	//states.push(new menu_state(window));
	// states.push(new MenuState());
}

ZombieGame::~ZombieGame() {
	while(!states.empty()) {
		delete states.top();
		states.pop();
	}
}

void ZombieGame::Run() {
	// while(window.isOpen()) {
	// 	UpdateEvents();
	// 	Update();
	// 	Render();
	// }
}

void ZombieGame::UpdateEvents(sf::Event& event) {
	// while(window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed:
				window->close();
				break;
		case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && MenuActive == true){
					sf::Vector2i MousePosition = sf::Mouse::getPosition(*window);
					if ((MousePosition.x > 600 && MousePosition.x < 1250) && (MousePosition.y > 450 && MousePosition.y < 700)){
						delete states.top();
						states.pop();
						MenuActive = false;
					}
					else if ((MousePosition.x > 600 && MousePosition.x < 1250) && (MousePosition.y > 760 && MousePosition.y < 960))
						window->close();
				}
                // std::cout << "Mouse Button Pressed" << std::endl;
                // if (typeid(states.top()) == typeid(MenuState()) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				// 	std::cout<<"now\n";
                //     //if u run into any problems try !states.empty() or != nullptr
                //     if (static_cast<MenuState()>(states.top())->Update()){
                //         delete states.top();
                //         states.pop();
                //     }
                // }
                break;
			case sf::Event::KeyPressed:
				break;
			default:
				break;
		}
	// }
}

void ZombieGame::Update() {
	if (!states.empty())
		states.top()->Update();
}

void ZombieGame::Render() const {
	// window.clear();
	if (!states.empty()) {
		states.top()->Render();
		// states.top()->ChangeView();
	}
	// window.display();
}

void ZombieGame::start(sf::RenderWindow& window) {
	initStates();
}

void ZombieGame::addEvents(sf::RenderWindow &window) {

}

void ZombieGame::addEvents(const sf::RenderWindow &window, sf::Event& event) {
	UpdateEvents(event);
}

void ZombieGame::draw(sf::RenderTarget &window, sf::RenderStates states) const {
	Render();
}

void ZombieGame::exit() {

}
