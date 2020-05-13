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
#include "weapon/melee.h"
#include "weapon/shotgun.h"

class Bullet
{
public:
	Bullet();
	smg s;
	rifle r;
	pistol p;
	Shotgun sh;
	Player p1;
	Melee m;

	//global variable for draw
	int GLOBALDRAW;
	//mutators
	void fire(sf::RenderWindow& window, float Xpos, float Ypos);
	void Draw(sf::RenderWindow& window, int identifier);
	void update(int identifier, float X, float Y);
	void pick_up_ammo(int identifier);
	void resetFireRate();


	//temp counter for reload/give ammo
	//for now just intiliaze ammo
	int countSMG = 15;
	//for now give it extra ammo
	int maxSMG = 0;
	int shotsSMG = 0;

	int countRifle = 15;
	int maxRifle = 15;
	int shotsRifle = 0;

	int countPistol = 10;
	int maxPistol = 0;
	int shotsPistol = 0;

	int countMelee;
	int maxMelee = 0 ;
	int shotsMelee = 0;

	int countShotgun = 5;
	int maxShotgun = 0 ;
	int shotsShotgun = 0;

	int count1 = 0;
	int count0 = 0;
	int count3 = 0;
	int count4 = 0;
private:
	float positionx = 0;
	float positiony = 0;
	float maxSpeed;

	int identifier;
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
	int meleeFireRate;


};

#endif // Bullet_H