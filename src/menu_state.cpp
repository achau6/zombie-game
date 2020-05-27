#include "menu_state.h"
menu_state::menu_state(sf::RenderWindow* wdw) : State(wdw){
	initalizeButtons();
}

void menu_state::Render(){
	wdw.draw(PlayButton.first);
	wdw.draw(PlayButton.second);
	wdw.draw(QuitButton.first);
	wdw.draw(QuitButton.second);
}

void menu_state::initalizeButtons(){
	PlayImage.loadFromFile("../zombie-game/content/Top_Down_Survivor/MainMenu/play.png");
	PlayButton.first.setSize(sf::Vector2f(100, 30));
	PlayButton.first.setPosition(50, 30);
	PlayButton.first.setFillColor(sf::Color(0,0,0,0));
	PlayButton.first.setOutlineColor(sf::Color::White);
	PlayButton.first.setOutlineThickness(2);
	PlayButton.second.setTexture(PlayImage);
	PlayButton.second.setPosition(50, 30);

	QuitImage.loadFromFile("../zombie-game/content/Top_Down_Survivor/MainMenu/quit.png");
	QuitButton.first.setSize(sf::Vector2f(100, 30));
	QuitButton.first.setPosition(50, 130);
	QuitButton.first.setFillColor(sf::Color(0,0,0,0));
	QuitButton.first.setOutlineColor(sf::Color::White);
	QuitButton.first.setOutlineThickness(2);
	QuitButton.second.setTexture(QuitImage);
	QuitButton.second.setPosition(50, 130);
}

bool menu_state::CheckPressed(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::Vector2i MousePosition = sf::Mouse::getPosition();
		if (MousePosition.x >=)
	}
}