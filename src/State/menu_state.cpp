#include "menu_state.h"
MenuState::MenuState(sf::RenderWindow* wdw) : State(wdw){
	initalizeButtons();
	ThemeSong.openFromFile("content/Audio/themesong.wav");
	ThemeSong.setLoop(true);
	ThemeSong.setVolume(50);
	ThemeSong.play();
}

void MenuState::Render(){
	window->draw(Menu);
	Play.draw(*window);
	Quit.draw(*window);
	window->draw(Title);
	window->draw(Logo);
}

void MenuState::initalizeButtons(){
	csFont.loadFromFile("content/cs_regular.ttf");
	Play.set_font(csFont);
	Play.set_size(sf::Vector2f(window->getSize().x * .15, window->getSize().y * .08));
	Play.set_text_color(sf::Color::Blue);
	Play.set_font_size(100);
	Play.set_pos(sf::Vector2f(window->getSize().x * .07, window->getSize().y * .45));
	Play.set_str("Play");

	Quit.set_font(csFont);
	Quit.set_size(sf::Vector2f(window->getSize().x * .15, window->getSize().y * .08));
	Quit.set_text_color(sf::Color::Blue);
	Quit.set_font_size(100);
	Quit.set_pos(sf::Vector2f(window->getSize().x * .07, window->getSize().y * .65));
	Quit.set_str("Quit");

	Title.setFont(csFont);
	Title.setCharacterSize(120);
	Title.setFillColor(sf::Color::White);
	Title.setString("Infestation");
	Title.setPosition(sf::Vector2f(window->getSize().x * .08, window->getSize().y * .2));

	LogoTexture.loadFromFile("content/logo.png");
	Logo.setTexture(LogoTexture);
	Logo.setScale(.7, .7);
	Logo.setPosition(sf::Vector2f(window->getSize().x * .42, window->getSize().y * .223));

	MenuTexture.loadFromFile("content/title.jpg");
	Menu.setTexture(MenuTexture);
}

void MenuState::Update(){
	Play.is_over(*window);
	Quit.is_over(*window);
}

int MenuState::checkPress(){
	if(Play.is_over(*window))
		return 1;
	else if (Quit.is_over(*window))
		return 2;
	return 0;
}
