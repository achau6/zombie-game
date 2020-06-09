#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <map>
#include <sstream>
#include <vector>
#include <string>
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
	void knifeSwings();
	void shootGun(int GLOBALIDENTIFIER);
	void WalkingSound();
//accessors
	const sf::Vector2f getPosition() const {return position;}
	sf::Vector2f& getPosition() {return position;}
	sf::Vector2u getGridPosition(const sf::Vector2u& grid_size);
	sf::Vector2f getdirectionalViewNormalized();
	sf::Sprite getPlayerSprite() {return entity_sprite;}
	float getPlayerSpd() {return movement_speed;}
	sf::Vector2f returnVelocity(){return velocity;}

private:
	void initSpriteTextures();
	void initHitBox();
	void initSound();

	const float movement_speed = 3.f;
	bool knifeAnimation;
	int knifeCount, count;
	sf::CircleShape area;
	sf::Vector2f mousePosition;
	sf::RenderTarget* target;
	Collision collisionCheck;
	std::map<int, sf::Texture> sprites;
	std::map<int, sf::Texture> shootingSprites;
	sf::SoundBuffer walk;
	sf::Sound Footsteps;
	sf::Texture knifeShooting[15];
};

#endif // PLAYER_H