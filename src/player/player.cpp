#include "player.h"

player::player(sf::RenderTarget* target){
	positionx = target->getSize().x/2.f;
	positiony = target->getSize().y/2.f;
	this->target = target;
	character.setRadius(RADIUS);
	character.setFillColor(sf::Color::Red);
	character.setPosition(positionx, positiony);
	characterCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
}

void player::movement(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		character.setPosition(positionx, positiony - UNITS);
		positiony -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		character.setPosition(positionx - UNITS, positiony);
		positionx -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		character.setPosition(positionx, positiony + UNITS);
		positiony += UNITS;
		// std::cout << "S works" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		character.setPosition(positionx + UNITS, positiony);
		positionx += UNITS;
	}
}

void player::look(sf::RenderWindow& window){
	characterCenter = sf::Vector2f(positionx + RADIUS,positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	directionalView = mousePosition - characterCenter;
	directionalViewNormalized.x = directionalView.x / sqrt(pow(directionalView.x, 2));
	directionalViewNormalized.y = directionalView.y / sqrt(pow(directionalView.y, 2));
}

void player::Draw(sf::RenderWindow& window){
	window.draw(character);
}