#include "menu_state.h"
MenuState::MenuState(sf::RenderWindow* wdw) : State(wdw){
	initalizeButtons();
}

void MenuState::Render(){
	window->draw(PlayButton);
	//window->draw(QuitButton);
}

void MenuState::initalizeButtons(){
	PlayImage.loadFromFile("../zombie-game/content/title.png");
	PlayButton.setTexture(PlayImage);
	//PlayButton.setPosition(50, 30);

	// QuitImage.loadFromFile("../zombie-game/content/Top_Down_Survivor/MainMenu/quit.png");
	// QuitButton.setTexture(QuitImage);
	// QuitButton.setPosition(50, 130);
}

void MenuState::Update(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::Vector2i MousePosition = sf::Mouse::getPosition(*window);
		std::cout<<"x: "<<MousePosition.x<<std::endl;
		std::cout<<"y: "<<MousePosition.y<<std::endl;
		// if (MousePosition.x >=)
	}
}