#include "player.h"

player::player(){
	positionx = 300;
	positiony = 300;
	character.setRadius(25);
	character.setFillColor(sf::Color::Red);
	character.setPosition(positionx, positiony);
}

void player::movement(sf::Event event){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		character.setPosition(positionx, positiony - 10);
		positiony -= 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		character.setPosition(positionx - 10, positiony);
		positionx -= 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		character.setPosition(positionx, positiony + 10);
		positiony += 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		character.setPosition(positionx + 10, positiony);
		positionx += 10;
	}
}

void player::Draw(sf::RenderWindow& window){
	window.draw(character);
}