#include "player.h"

Player::Player(sf::RenderTarget* target){
	positionx = target->getSize().x/2.f;
	positiony = target->getSize().y/2.f;
	this->target = target;
	character.setRadius(RADIUS);
	character.setFillColor(sf::Color::Blue);
	character.setPosition(positionx, positiony);
	characterCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
}

void Player::movement(){


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (collisionCheck.legalMovement(positionx, positiony - UNITS)){
			character.setPosition(positionx, positiony - UNITS);
			positiony -= UNITS;

			std::cout<<"XXXXX: "<<positionx<<" NEW Y: "<<positiony<<std::endl;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (collisionCheck.legalMovement(positionx - UNITS, positiony)){
			character.setPosition(positionx - UNITS, positiony);
			positionx -= UNITS;

			std::cout<<"XXXXX: "<<positionx<<" NEW Y: "<<positiony<<std::endl;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (collisionCheck.legalMovement(positionx, positiony + UNITS)){
			character.setPosition(positionx, positiony + UNITS);
			positiony += UNITS;

			std::cout<<"XXXXX: "<<positionx<<" NEW Y: "<<positiony<<std::endl;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (collisionCheck.legalMovement(positionx + UNITS, positiony)){
			character.setPosition(positionx + UNITS, positiony);
			positionx += UNITS;

			std::cout<<"XXXXX: "<<positionx<<" NEW Y: "<<positiony<<std::endl;
		}
	}
}

sf::Vector2u Player::getGridPosition(const sf::Vector2u& grid_size) {
	if(positionx > 0)
		grid_pos.x = positionx / grid_size.x;
	if(positiony > 0)
		grid_pos.y = positiony / grid_size.y;

	return grid_pos;
}

void Player::look(sf::RenderWindow& window){
	characterCenter = sf::Vector2f(positionx + RADIUS,positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	directionalView = mousePosition - characterCenter;
	float num = sqrt(pow(directionalView.x, 2) + pow(directionalView.y, 2));
	directionalViewNormalized = directionalView / num;
}

sf::Vector2f Player::getCharacterCenter(){
	return characterCenter;
}

float Player::getPositionX(){
	return positionx;
}
float Player::getPositionY(){
	return positiony;
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(character);
}
