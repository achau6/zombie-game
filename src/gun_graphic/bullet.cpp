#include "bullet.h"
#include "math.h"
#include <vector>
#include <assert.h>
Bullet::Bullet()
{
	positioned.x = 305;
	positioned.y = 305;
	bullet.setRadius(1);
	bullet.setFillColor(sf::Color::White);
	bullet.setPosition(bulletCenter);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 15.f;
	pistolFireRate = 0;
	smgFireRate = 0;
	shotgunFireRate = 0;
	rifleFireRate = 0;
}

// FIXME: MAGIC NUMBERS HERE BIG NO NO
void Bullet::fire(int identifier, sf::RenderWindow& window)
{
	velocity = aimViewNormalized * maxSpeed;
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		std::cout<<"Left Mouse of bullet"<<std::endl;
		if(identifier == 2){
			std::cout<<"smg"<<std::endl;
			if(smgFireRate < 6)
			{
				smgFireRate ++;
			}
			if(shotsSMG < (countSMG*5))
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(smgFireRate >= 5)
				{
					for(int i = 0; i < 15; i ++){
						s.push(bullet, velocity, bulletCenter);
					}
					smgFireRate = 0;

				}
				shotsSMG ++;
			} else {
				std::cout<<"No Ammo"<<std::endl;
				//bullet counter
				shotsSMG = 0;
				//mag/15 shot counter
				countSMG = 0;
				//max is reserve ammo counter
				if(maxSMG == 0)
				{
					std::cout<<"Rip You got no Ammo"<<std::endl;
				}
				while(maxSMG > 0)
				{
					countSMG ++;
					maxSMG --;
				}
				std::cout<<"New Ammo Count: "<<countSMG<<std::endl;

			}
			for (s.start(); s.is_item(); s.advance()) {
				s.current();
				s.erase(window);
			}

		} else if(identifier == 1){
			std::cout<<"pistol"<<std::endl;
			if(pistolFireRate < 3)
			{
				pistolFireRate ++;
			}
			if(shotsPistol < (countPistol*2))
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(pistolFireRate >= 2)
				{
					for(int i = 0; i < 15; i ++){
						p.push(bullet, velocity, bulletCenter);
					}
					pistolFireRate = 0;

				}
				shotsPistol ++;
			} else {
				std::cout<<"No Ammo"<<std::endl;
				//bullet counter
				shotsPistol = 0;
				//mag/15 shot counter
				countPistol = 0;
				//max is reserve ammo counter
				if(maxPistol == 0)
				{
					std::cout<<"Rip You got no Ammo"<<std::endl;
				}
				while(maxPistol > 0)
				{
					countPistol ++;
					maxPistol --;
				}
				std::cout<<"New Ammo Count: "<<countPistol<<std::endl;

			}
			for (p.start(); p.is_item(); p.advance()) {
				p.current();
				p.erase(window);
			}


		}else if(identifier == 3){
			std::cout<<"rifle"<<std::endl;
			if(rifleFireRate < 5)
			{
				rifleFireRate ++;
			}
			if(shotsRifle < (countRifle*5))
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(rifleFireRate >= 4)
				{
					for(int i = 0; i < 15; i ++){
						s.push(bullet, velocity, bulletCenter);
					}
					rifleFireRate = 0;

				}
				shotsRifle ++;
			} else {
				std::cout<<"No Ammo"<<std::endl;
				//bullet counter
				shotsRifle = 0;
				//mag/15 shot counter
				countRifle = 0;
				//max is reserve ammo counter
				if(maxRifle == 0)
				{
					std::cout<<"Rip You got no Ammo"<<std::endl;
				}
				while(maxSMG > 0)
				{
					countRifle ++;
					maxRifle --;
				}
				std::cout<<"New Ammo Count: "<<countRifle<<std::endl;

			}
			for (r.start(); r.is_item(); r.advance()) {
				r.current();
				r.erase(window);
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
	//std::cout<<"x: "<<aimView.x<<std::endl;
	//std::cout<<"y: "<<aimView.y<<std::endl;


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

void Bullet::pick_up_ammo(int identifier)
{
	if(identifier == 1)
	{
		maxPistol += 15;
	}else if(identifier == 2)
	{
		maxSMG += 15;
	}else if(identifier == 3)
	{
		maxRifle += 15;
	}
}


void Bullet::Draw(sf::RenderWindow& window, int identifier){
	int count = 0;
	if(identifier == 2){
		for (s.start(); s.is_item(); s.advance()) {
			s.currentDraw(window);
			count ++;
		}
	}
}


