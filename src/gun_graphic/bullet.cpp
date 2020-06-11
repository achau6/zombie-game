#include "bullet.h"

Bullet::Bullet()
{
	//bullet.setRadius(40);
	bullet.setSize(sf::Vector2f(4, 4));
	bullet.setFillColor(sf::Color::Yellow);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 15.f;
}

KnifeBullet::KnifeBullet()
{
	bullet.setSize(sf::Vector2f(15, 15));
	bullet.setFillColor(sf::Color::Yellow);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 15.f;
}