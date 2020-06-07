#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <cmath>
#include <vector>

class Collision
{
public:
//constructor
	Collision() = default;
	Collision(sf::RenderTarget* window);
//mutators
	bool OutOfBounds(float positionx, float positiony);
	bool MapEntityCheck(float positionx, float positiony);
//accessors
	bool legalMovement(float positionx, float positiony);
	bool rectangleToRectangle(sf::Vector2f circle, sf::Vector2f rectangle);
private:
	const float MAP_BORDER_X_LOW = 0;
	const float MAP_BORDER_X_HIGH = 2480;
	const float MAP_BORDER_Y_LOW = 0;
	const float MAP_BORDER_Y_HIGH = 2480;
};

#endif // PLAYER_H