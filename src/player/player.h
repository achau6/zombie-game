#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "constant.h"
#include "math.h"
#include <vector>
class player
{
public:
	player();
	void movement();
	void Draw(sf::RenderWindow& window);
	void look(sf::RenderWindow& window);
private:
	float positionx;
	float positiony;
	sf::Vector2f characterCenter;
	sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	sf::Vector2f directionalViewNormalized;
	sf::CircleShape character;
	float HP;
};

#endif // PLAYER_H