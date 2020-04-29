#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "weapon.h"
#include "math.h"
#include <vector>
#include "player/constant.h"

class bullet
{
public:
	sf::Vector2f velocity;
	float maxSpeed;
	sf::CircleShape shape;

	bullet()
	{
		shape.setRadius(10);
		shape.setFillColor(sf::Color::White);
		velocity = sf::Vector2f(0.f, 0.f);
		maxSpeed = 15.f;
	}


};

class shotgun: public weapons
{
public:
	shotgun();
	bullet b;
	sf::Vector2f velocity;
	float maxSpeed;
	sf::Vector2f aimView;
	sf::Vector2f mousePosition;
	sf::Vector2f aimViewNormalized;
	sf::Vector2f bulletCenter;
	std::vector<bullet> bullets;
	float positionx;
	float positiony;

	void looks(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void add_ammo();
	void identify(int type);
	int damage(int& type);
	void fire();
};

#endif // SHOTGUN_H