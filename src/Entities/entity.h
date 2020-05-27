#include "Platform/Platform.hpp"

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

protected:
	float HP;
	sf::Vector2f velocity;
	sf::Sprite entity_sprite;
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2u grid_pos;
private:
};