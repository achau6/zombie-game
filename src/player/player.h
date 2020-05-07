#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cmath>
#include <vector>
#include "constant.h"
#include "Collision\collision.h"

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
	float& getPositionX();
	float& getPositionY();
	sf::Vector2f& getPosition();
	sf::Vector2f getdirectionalViewNormalized();
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
	Collision collisionCheck;
};

#endif // PLAYER_H