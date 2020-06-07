#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Collision/collision.h"
#include "../Entities/entity.h"

class Player : public Entity
{
public:
//constructor
	Player() = default;
	Player(sf::RenderTarget* window);
//mutators
	void Update();
	void movement();
	void Draw(sf::RenderWindow& window);
	void look(sf::RenderWindow& window);
	void setPosition(sf::Vector2f pos) {entity_sprite.setPosition(pos);}
	void changeGun(int GLOBALIDENTIFIER);
//accessors
	const sf::Vector2f getPosition() const {return position;}
	sf::Vector2f& getPosition() {return position;}
	sf::Vector2u getGridPosition(const sf::Vector2u& grid_size);
	sf::Vector2f getdirectionalViewNormalized();
	sf::Sprite getPlayerSprite() {return entity_sprite;}
	float getPlayerSpd() {return movement_speed;}
	sf::Vector2f returnVelocity(){return velocity;}

private:
	const float movement_speed = 3.f;
	int count = 1;

	// sf::RectangleShape hitbox;
	sf::CircleShape area;
	//sf::Sprite playerSprite;
	sf::Texture texture;
	//sf::RectangleShape Hitbox;
	// sf::Vector2f characterCenter;
	// sf::Vector2f directionalView;
	sf::Vector2f mousePosition;
	// sf::Vector2f directionalViewNormalized;
	sf::RenderTarget* target;
	Collision collisionCheck;
};

#endif // PLAYER_H