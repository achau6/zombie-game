#pragma once

#include "Platform/Platform.hpp"
#include "SFML/Audio.hpp"

class Entity {
public:
	Entity() = default;

	virtual void Update();
	virtual void Render(sf::RenderTarget& target);

	const sf::Sprite getSprite() const {return entity_sprite;}
	sf::Sprite& getSprite() {return entity_sprite;}

	const sf::RectangleShape getHitbox() const {return hitbox;}
	sf::RectangleShape& getHitbox() {return hitbox;}

	const sf::Vector2f getVelocity() const {return velocity;}
	sf::Vector2f& getVelocity() {return velocity;}

	sf::Vector2u getGridPosition(const sf::Vector2u& grid_size) {
		// didnt catch this till now but the grid pos calculation wasnt giving 50,50
		// now it do :D majik nums
		if(position.x > 0)
			grid_pos.x = (position.x/1.4 / grid_size.x);
		if(position.y > 0)
			grid_pos.y = (position.y/1.4 / grid_size.y);
		return grid_pos;
	}

	float getHP() const {return hp;}
	void addHp() {hp += 25.00;}

protected:
	float hp;
	sf::Vector2f velocity;
	sf::Sprite entity_sprite;
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2u grid_pos;
private:

};