#include "state.h"

State::State(sf::RenderWindow* wdw) : window(wdw) {
	std::shared_ptr<sf::Texture> dirt = std::make_shared<sf::Texture>();
	std::shared_ptr<sf::Texture> concrete = std::make_shared<sf::Texture>();
	game_textures.insert(std::make_pair("dirt", dirt));
	game_textures.insert(std::make_pair("concrete", concrete));
	if(!game_textures["dirt"]->loadFromFile("../zombie-game/content/dirt.png")){
		std::cout<<"failed to load tile texture\n";
	}
	if(!game_textures["concrete"]->loadFromFile("content/wallTexture.jpg")){
		std::cout<<"failed to load tile texture\n";
	}
	std::shared_ptr<sf::Texture> zombie = std::make_shared<sf::Texture>();
	game_textures.insert(std::make_pair("zombie", zombie));
	if(!game_textures["zombie"]->loadFromFile("../zombie-game/content/zombie.png")){
		std::cout<<"failed to load zombie texture\n";
	}
}

State::~State() {

}
