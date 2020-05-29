#ifndef BULLET_H
#define BULLET_H
#include <iostream>


class Bullet
{
public:
	Bullet();
	sf::Vector2f velocity;
	sf::RectangleShape bullet;
	float maxSpeed;

};

#endif // Bullet_H