#include "bullet.h"

Bullet::Bullet()
{
	bullet.setRadius(2);
	bullet.setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 10.f;
}
