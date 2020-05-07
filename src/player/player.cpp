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
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A))){
		if (collisionCheck.legalMovement(positionx - UNITS, positiony - UNITS)){
			character.setPosition(positionx - UNITS, positiony - UNITS);
			positionx -= UNITS;
			positiony -= UNITS;
			std::cout<<"XXXXX: "<<positionx<<" NEW Y: "<<positiony<<std::endl;
		}
	}
}

void Player::look(sf::RenderWindow& window){
	characterCenter = sf::Vector2f(positionx + RADIUS,positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	directionalView = mousePosition - characterCenter;
	directionalViewNormalized = directionalView / (float)(sqrt(pow(directionalView.x, 2) + pow(directionalView.y, 2)));
}

float& Player::getPositionX(){
	return positionx;
}

float& Player::getPositionY(){
	return positiony;
}

sf::Vector2f Player::getdirectionalViewNormalized(){
	return directionalViewNormalized;
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(character);
}