#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "math.h"
#include <vector>
#include "player/constant.h"
#include "weapon/smg.h"
#include "weapon/pistol.h"
#include "weapon/rifle.h"
#include "player/player.h"

class Bullet
{
public:
	Bullet();
	smg s;
	rifle r;
	pistol p;
	Player p1;
    //typedef Sequence_Iterator<sf::CircleShape> iter;
	void fire(int identifier, sf::RenderWindow& window, float Xpos, float Ypos);
	void Draw(sf::RenderWindow& window, int identifier);
	void update(int identifier, sf::RenderWindow& window);
	void pick_up_ammo(int identifier);


	//temp counter for reload/give ammo
	//for now just intiliaze ammo
	int countSMG = 15;
	//for now give it extra ammo
	int maxSMG = 900;
	int shotsSMG = 0;

	int countRifle = 15;
	int maxRifle = 15;
	int shotsRifle = 0;

	int countPistol = 15;
	int maxPistol = 15;
	int shotsPistol = 0;


private:
	float positionx = 0;
	float positiony = 0;
	sf::Vector2f positioned;
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