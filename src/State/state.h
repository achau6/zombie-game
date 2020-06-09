#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <sstream>
#include "../src/Utility/button.h"
#include <map>
#include "Platform/Platform.hpp"

class State {
public:
	State(sf::RenderWindow* wdw);
	virtual ~State();

	// forces function to be defined in derived class
	virtual void Update() = 0;
	virtual void Render() = 0;
	// virtual void ChangeView() = 0;

protected:
	// using ptr to window so its easier draw objs without constantly passing window
	sf::RenderWindow* window;
	// TODO: add textures here!
	std::map<std::string, std::shared_ptr<sf::Texture>> game_textures;
	bool IsPaused;
};


#endif // STATE_H


