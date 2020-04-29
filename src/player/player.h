#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cmath>
#include <vector>
#include "constant.h"

class Player
{
public:
	Player() = default;
	Player(sf::RenderTarget* window);
	void movement();
	void Draw(sf::RenderWindow& window);
	void look(sf::RenderWindow& window);
private:
	float positionx = 0;
	float positiony = 0;
	float HP = 100;

	sf::Vector2f characterCenter;
	sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	sf::Vector2f directionalViewNormalized;
	sf::CircleShape character;
	sf::RenderTarget* target;
};

#endif // PLAYER_H