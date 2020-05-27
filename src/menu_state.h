#include "state.h"
class menu_state : public State{
public:
	menu_state(sf::RenderWindow* wdw);
	//mutator
	void ButtonPress();
	void initalizeButtons();
	virtual void Render();
	bool CheckPressed();
private:
	std::pair<sf::RectangleShape, sf::Sprite> PlayButton;
	std::pair<sf::RectangleShape, sf::Sprite> QuitButton;
	sf::Texture PlayImage;
	sf::Texture QuitImage;
};