#include "bullet.h"

Bullet::Bullet()
{

	//bullet.setRadius(40);
	bullet.setSize(sf::Vector2f(5, 5));
	bullet.setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 3.f;

}
