#include "Platform/Platform.hpp"

class Entity {
public:
	Entity() = default;

	virtual void Update();
	virtual void Render(sf::RenderTarget& target);
	sf::Sprite getSprite() {return entity_sprite;}
	sf::Vector2f getVelocity() {return velocity;}
protected:
	float HP;
	sf::Vector2f velocity;
	sf::Sprite entity_sprite;
	sf::Vector2f position;
	sf::Vector2u grid_pos;
private:
};