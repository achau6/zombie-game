#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cmath>
#include <vector>
#include "constant.h"

class Player
{
public:
//constructor
	Player() = default;
	Player(sf::RenderTarget* window);
//mutators
	void movement();
	void Draw(sf::RenderWindow& window);
	void look(sf::RenderWindow& window);
//accessors
	sf::Vector2f getPosition() {return sf::Vector2f(positionx, positiony);}
	sf::Vector2u getGridPosition(const sf::Vector2u& grid_size);
	sf::Vector2f getdirectionalViewNormalized();
private:
	float positionx = 0;
	float positiony = 0;
	sf::Vector2u grid_pos;
	float HP = 100;

	sf::Vector2f characterCenter;
	sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	sf::Vector2f directionalViewNormalized;
	sf::CircleShape character;
	sf::RenderTarget* target;
};

#endif // PLAYER_H