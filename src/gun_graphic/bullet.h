#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "math.h"
#include <vector>
#include "player/constant.h"
#include "weapon/smg.h"
#include "weapon/pistol.h"
#include "weapon/rifle.h"

class Bullet
{
public:
	Bullet();
	smg s;
    //typedef Sequence_Iterator<sf::CircleShape> iter;
	void fire(int identifier);
	void Draw(sf::RenderWindow& window, int identifier);
	void looks(sf::RenderWindow& window);
	void update();

private:
	float positionx;
	float positiony;
	float maxSpeed;
	float dupePosx;
	float dupePosy;
	sf::Vector2f velocity;
	sf::Vector2f aimView;
	sf::Vector2f mousePosition;
	sf::Vector2f aimViewNormalized;
	sf::CircleShape bullet;
	sf::Vector2f bulletCenter;

	//fire rate
	int smgFireRate;
	int rifleFireRate;
	int shotgunFireRate;
	int pistolFireRate;


};

#endif // Bullet_H