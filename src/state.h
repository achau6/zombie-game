#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include "Platform/Platform.hpp"

class State {
public:
	State(sf::RenderWindow* wdw) : window(wdw) {}
	virtual ~State();

	// function must be defined in derived class
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	// using ptr to window so its easier draw objs without constantly passing window
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures; // TODO: add textures here!
	bool IsPaused;
};


