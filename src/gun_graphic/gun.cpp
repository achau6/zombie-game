#include "gun.h"

Gun::Gun(){
	positionx = 305;
	positiony = 305;
	gun.setScale(sf::Vector2f(.5, .5));
	//gun.setColor(sf::Color::White);
	gun.setPosition(positionx, positiony);
	gunCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);

}

void Gun::movement(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		gun.setPosition(positionx, positiony - UNITS);
		positiony -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		gun.setPosition(positionx - UNITS, positiony);
		positionx -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		gun.setPosition(positionx, positiony + UNITS);
		positiony += UNITS;
		// std::cout << "S works" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		gun.setPosition(positionx + UNITS, positiony);
		positionx += UNITS;
	}

}

void Gun::look(sf::RenderWindow& window){
	gunCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	directionalView = mousePosition - gunCenter;
	directionalViewNormalized.x = directionalView.x / sqrt(pow(directionalView.x, 2));
	directionalViewNormalized.y = directionalView.y / sqrt(pow(directionalView.y, 2));

}

void Gun::Draw(sf::RenderWindow& window){
	sf::Texture shotgunTexture;

	shotgunTexture.loadFromFile("C:/Users/SICK/Documents/CS/test4/zombie-game/content/zombieGameGunShotgun.PNG");
	if (!shotgunTexture.loadFromFile("C:/Users/SICK/Documents/CS/test4/zombie-game/content/zombieGameGunShotgun.PNG"))
	{
		std::cout<<"Error Loading shotgun sprite"<<std::endl;
	}

	gun.setTexture(shotgunTexture);
	//gun.setScale(sf::Vector2f(5, 5));
	window.draw(gun);
}

float Gun::gunPositionx(){
	return positionx;
}

float Gun::gunPositiony(){
	return positiony;
}

float Gun::gunCenterx(){
	return gunCenter.x;
}

float Gun::gunCentery(){
	return gunCenter.y;
}