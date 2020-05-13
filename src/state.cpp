#include "state.h"

State::State(sf::RenderWindow* wdw) : window(wdw) {
	std::shared_ptr<sf::Texture> dirt = std::make_shared<sf::Texture>();
	game_textures.insert(std::make_pair("dirt", dirt));
	if(!game_textures["dirt"]->loadFromFile("../zombie-game/content/dirt.png")){
		std::cout<<"failed to load tile texture\n";
	}
}

State::~State() {

}
