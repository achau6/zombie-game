#pragma once

#include "state.h"
class MenuState : public State{
public:
	MenuState(sf::RenderWindow* wdw);
	~MenuState() {}
	//mutator
	void Render();
	void Update();
private:
	void initalizeButtons();
	sf::Sprite PlayButton;
	sf::Sprite QuitButton;
	sf::Texture PlayImage;
	sf::Texture QuitImage;
};