#ifndef GUN_H
#define GUN_H
#include <iostream>
#include "math.h"
#include <vector>
#include "bullet.h"
#include "player/constant.h"
#include "weapon/pistol.h"
#include "weapon/smg.h"
#include "weapon/shotgun.h"
#include "weapon/rifle.h"
#include "weapon/weapon.h"
class Gun
{
public:
	Gun();
	Bullet b;
	pistol p;
	rifle r;
	Shotgun sh;
	smg s;
	weapons w;
	int GLOBALIDENTIFIER;
	void Draw(sf::RenderWindow& window, int identifier);
	void fire(sf::RenderWindow& window, float Xpos, float Ypos);
	void movement(int identifier);
	void erase();
private:
	sf::Vector2f aimView;
	sf::Vector2f aimViewNormalized;
	sf::Vector2f mousePosition;
	sf::Vector2f bulletPosition;
	sf::Vector2f bulletCenter;
};

#endif // GUN_H