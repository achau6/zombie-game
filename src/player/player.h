#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class player
{
public:
	player();
	void movement(sf::Event event);
	void look(sf::Event event);
	void Draw(sf::RenderWindow& window);
private:
	float positionx;
	float positiony;
	float directionalview;
	sf::CircleShape character;
};

#endif // PLAYER_H