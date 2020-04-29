#ifndef GUN_H
#define GUN_H
#include <iostream>
#include "math.h"
#include <vector>
#include "player/constant.h"
class Gun
{
public:
	Gun();
	void movement();
	void look(sf::RenderWindow& event);
	void Draw(sf::RenderWindow& window);
	float gunPositionx();
	float gunPositiony();
	float gunCenterx();
	float gunCentery();

private:
	float positionx;
	float positiony;
	float directionalview;
	sf::Vector2f gunCenter;
	sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	sf::Vector2f directionalViewNormalized;
	//sf::CircleShape character;
	sf::Sprite gun;
	int popo;
};

#endif // GUN_H