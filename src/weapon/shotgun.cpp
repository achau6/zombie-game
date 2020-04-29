#include "shotgun.h"
#include <vector>
//#include "constant.h"

shotgun::shotgun()
{
	positionx = 305;
	positiony = 305;
	bulletCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);

}

void shotgun::add_ammo()
{

}

void shotgun::looks(sf::RenderWindow& window)
{
	bulletCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	aimView = mousePosition - bulletCenter;
	aimViewNormalized.x = aimView.x / sqrt(pow(aimView.x, 2));
	aimViewNormalized.y = aimView.y / sqrt(pow(aimView.y, 2));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		//b.setPosition(positionx, positiony - UNITS);
		positiony -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		//b.setPosition(positionx - UNITS, positiony);
		positionx -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		//b.setPosition(positionx, positiony + UNITS);
		positiony += UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		//b.setPosition(positionx + UNITS, positiony);
		positionx += UNITS;
	}

}

void shotgun::fire()
{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		std::cout<<"Left Mouse of bullet"<<std::endl;
		b.shape.setPosition(bulletCenter);
		b.velocity = aimViewNormalized * b.maxSpeed;
		bullets.push_back(bullet(b));

		}
		for(size_t i = 0; i < bullets.size(); i ++){
			bullets[i].shape.move(bullets[i].velocity);
		}
}

void shotgun::draw(sf::RenderWindow& window)
{
	for(size_t i = 0; i < bullets.size(); i ++){
		window.draw(bullets[i].shape);
	}
}
//shotgun does 4 dmg
int shotgun::damage(int& type)
{
	//type is the zombie while 5 equals the health
	//dont need this check but I want to know its
	//if its the right zombie
	if(type == 5)
	{
		type -= 5;
	}

	//return the health of the zombie
	return type;
}