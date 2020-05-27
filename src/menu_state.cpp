#include "menu_state.h"
menu_state::menu_state(sf::RenderWindow* wdw) : State(wdw){
	initalizeButtons();
}

void menu_state::Render(){
	wdw.draw(PlayButton);
	wdw.draw(QuitButton);
}

void menu_state::initalizeButtons(){
	PlayImage.loadFromFile("../zombie-game/content/Top_Down_Survivor/MainMenu/play.png");
	PlayButton.setTexture(PlayImage);
	PlayButton.setPosition(50, 30);

	QuitImage.loadFromFile("../zombie-game/content/Top_Down_Survivor/MainMenu/quit.png");
	QuitButton.setTexture(QuitImage);
	QuitButton.setPosition(50, 130);
}

bool menu_state::CheckPressed(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::Vector2i MousePosition = sf::Mouse::getPosition();
		if (MousePosition.x >=)
	}
}