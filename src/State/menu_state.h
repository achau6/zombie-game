#pragma once

#include "state.h"
class MenuState : public State{
public:
	MenuState() = default;
	MenuState(sf::RenderWindow* wdw);
	~MenuState() {window->setMouseCursorVisible(false);}
	//mutator
	void Render();
	void Update();
	int checkPress();
private:
	void initalizeButtons();

	sf::Sprite Menu, Logo;
	sf::Texture MenuTexture, LogoTexture;
	sf::Font csFont;
	sf::Text Title;
	Button Play, Quit;
	sf::Music ThemeSong;
};