#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cmath>
#include <vector>
#include "constant.h"
#include "Collision\collision.h"
#include <stdio.h>

class Player
{
public:
//constructor
	Player() = default;
	Player(sf::RenderTarget* window);
//mutators
	void movement();
	void Draw(sf::RenderWindow& window);
	void look(sf::RenderWindow& window);
	void setPosition(sf::Vector2f pos) {player.first.setPosition(pos);}
//accessors
	sf::Vector2f getPosition() {return sf::Vector2f(positionx, positiony);}
	sf::Vector2u getGridPosition(const sf::Vector2u& grid_size);
	sf::Vector2f getdirectionalViewNormalized();
	float& getPositionX() {return positionx;}
	float& getPositionY() {return positiony;}
	sf::Sprite getPlayerSprite() {return player.first;}
	float getPlayerSpd() {return UNITS;}

private:
	float positionx = 0;
	float positiony = 0;
	std::pair<sf::Sprite, sf::RectangleShape> player;
	sf::CircleShape area;
	sf::Vector2u grid_pos;
	//sf::Sprite playerSprite;
	sf::Texture texture;
	//sf::RectangleShape Hitbox;
	float HP = 100;
	int count = 1;
	// sf::Vector2f characterCenter;
	// sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	// sf::Vector2f directionalViewNormalized;
	sf::RenderTarget* target;
	Collision collisionCheck;
};

#endif // PLAYER_H