 #include "bullet.h"
#include "math.h"
#include <vector>
#include <assert.h>
Bullet::Bullet()
{
	positionx = 305;
	positiony = 305;
	bullet.setRadius(10);
	bullet.setFillColor(sf::Color::White);
	//bulletCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
	bullet.setPosition(bulletCenter);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 15.f;
	pistolFireRate = 0;
	smgFireRate = 0;
	shotgunFireRate = 0;
	rifleFireRate = 0;
}

void Bullet::fire(int identifier)
{
	int count = 0;
	velocity = aimViewNormalized * maxSpeed;
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		std::cout<<"Left Mouse of bullet"<<std::endl;
		if(identifier == 2){
			std::cout<<"smg"<<std::endl;
			if(smgFireRate < 6)
			{
				smgFireRate ++;
			}
			if(count < 1)
			{

				if(smgFireRate >= 5)
				{
					for(int i = 0; i < 15; i ++){
						s.push(bullet, velocity);
					}
					smgFireRate = 0;

				}


				count ++;
			}
			for (s.start(); s.is_item(); s.advance()) {
				s.current();
			}


		}

	}
}

void Bullet::looks(sf::RenderWindow& window)
{
	bulletCenter = sf::Vector2f(positionx + RADIUS, positiony + RADIUS);
	mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	aimView = mousePosition - bulletCenter;
	aimViewNormalized = aimView / (float)(sqrt(pow(aimView.x, 2) + pow(aimView.y, 2)));
	//aimViewNormalized.y = aimView.y / sqrt(pow(aimView.y, 2));
	std::cout<<"x: "<<aimView.x<<std::endl;
	std::cout<<"y: "<<aimView.y<<std::endl;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		bullet.setPosition(positionx, positiony - UNITS);
		positiony -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		bullet.setPosition(positionx - UNITS, positiony);
		positionx -= UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		bullet.setPosition(positionx, positiony + UNITS);
		positiony += UNITS;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		bullet.setPosition(positionx + UNITS, positiony);
		positionx += UNITS;
	}

}


void Bullet::Draw(sf::RenderWindow& window, int identifier){
	int count = 0;
	if(identifier == 2){
		for (s.start(); s.is_item(); s.advance()) {
			s.currentDraw(window);
			count ++;
		}
		// for (s.start(); s.is_item(); s.advance()) {
		// 	s.remove();
		// }
	}
	// for(int i = 0; i < count; i++){
	// 	w.remove(head);
	// }

}


