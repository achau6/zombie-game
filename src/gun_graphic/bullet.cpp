#include "bullet.h"
#include "math.h"
#include <vector>
#include <assert.h>

Bullet::Bullet()
{

	bullet.setRadius(5);
	//bullet.setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.f, 0.f);
	maxSpeed = 3.f;
	pistolFireRate = 10;
	smgFireRate = 14;
	shotgunFireRate = 39;
	rifleFireRate = 20;
	meleeFireRate = 5;
	identifier = 0;

}

void Bullet::fire(sf::RenderWindow& window, float Xpos, float Ypos)
{
	//select type of guns
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		identifier = 0;
		GLOBALDRAW = 0;
		std::cout<<"Melee"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		identifier = 1;
		GLOBALDRAW = 1;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		identifier = 2;
		GLOBALDRAW = 2;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
		identifier = 3;
		GLOBALDRAW = 3;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
		identifier = 4;
		GLOBALDRAW = 4;
	}
	bulletCenter = sf::Vector2f(Xpos + RADIUS, Ypos + RADIUS);

	mousePosition.x = sf::Mouse::getPosition(window).x;
    mousePosition.y = sf::Mouse::getPosition(window).y;
	mousePosition.x -= 640;
    mousePosition.y -= 360;
    mousePosition.x += Xpos;
    mousePosition.y += Ypos;

	aimView = mousePosition - bulletCenter;
	float num = sqrt(pow(aimView.x, 2) + pow(aimView.y, 2));
	aimViewNormalized = aimView / num;


	velocity = aimViewNormalized * maxSpeed;
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		std::cout<<"Left Mouse of bullet"<<std::endl;
		if(identifier == 0){
			//bulletCenter = sf::Vector2f(Xpos + 230, mousePosition.y);
			bullet.setPosition(bulletCenter);
			if(meleeFireRate < 5)
			{
				meleeFireRate ++;
			}
			if(meleeFireRate >= 5)
			{

				m.push(bullet, velocity, bulletCenter);

				meleeFireRate = 0;

			}

		} else if(identifier == 2){
			//^ find you which Type of gun
			//bottom pushes the bullet object into the gun
			bullet.setPosition(bulletCenter);
			std::cout<<"smg"<<std::endl;
			//this is a counter set to control how fast the is fired
			//out of the gun
			if(smgFireRate < 14)
			{
				smgFireRate ++;
			}
			//shotsSMG is a counter for how many bullets were fired from
			//the gun.
			if(shotsSMG < countSMG)
			{
				std::cout<<"Fire Rate"<<std::endl;
				if(smgFireRate >= 13)
				{
					std::cout<<"Add Ammo"<<std::endl;
					s.push(bullet, velocity, bulletCenter);
					//resets the counter for fireRate
					smgFireRate = 0;
					//increments everytime a bullet is fired
					//to keep track how many shots were shot
					shotsSMG ++;

				}


			} else {
				std::cout<<"No Ammo"<<std::endl;
				//Resets the count for magazine
				shotsSMG = 0;
				//mag 15 shot counter
				countSMG = 0;
				//max is reserve ammo counter
				if(maxSMG == 0)
				{
					std::cout<<"Rip You got no Ammo"<<std::endl;
				}
				//Checks the total amount of bullet for the gun and
				//if there is anyleft, add it to the clip until it reaches it max
				while(maxSMG > 0 && countPistol < 16)
				{
					countSMG ++;
					maxSMG --;
				}
				std::cout<<"New Ammo Count: "<<countSMG<<std::endl;

			}


		} else if(identifier == 1){
			bullet.setPosition(bulletCenter);
			std::cout<<"pistol"<<std::endl;
			if(pistolFireRate < 10)
			{
				pistolFireRate ++;
			}
			if(shotsPistol < countPistol)
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(pistolFireRate >= 9)
				{

					p.push(bullet, velocity, bulletCenter);

					pistolFireRate = 0;
					shotsPistol ++;

				}

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
				while(maxPistol > 0 && countPistol < 11)
				{
					countPistol ++;
					maxPistol --;
				}
				std::cout<<"New Ammo Count: "<<countPistol<<std::endl;

			}



		}else if(identifier == 3){
			bullet.setPosition(bulletCenter);
			std::cout<<"rifle"<<std::endl;
			if(rifleFireRate < 21)
			{
				rifleFireRate ++;
			}
			if(shotsRifle < countRifle)
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(rifleFireRate >= 20)
				{
					r.push(bullet, velocity, bulletCenter);

					rifleFireRate = 0;
					shotsRifle ++;

				}
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
				while(maxRifle > 0 && 16)
				{
					countRifle ++;
					maxRifle --;
				}
				std::cout<<"New Ammo Count: "<<countRifle<<std::endl;

			}


		} else if(identifier == 4){
			bullet.setPosition(bulletCenter);
			std::cout<<"Shotgun"<<std::endl;
			if(shotgunFireRate < 40)
			{
				shotgunFireRate ++;
			}
			if(shotsShotgun < countShotgun)
			{
				std::cout<<"Add Ammo"<<std::endl;
				if(shotgunFireRate >= 39)
				{
					sh.push(bullet, velocity, bulletCenter);

					shotgunFireRate = 0;
					shotsShotgun ++;

				}
			} else {
				std::cout<<"No Ammo"<<std::endl;
				//bullet counter
				shotsShotgun = 0;
				//mag/15 shot counter
				countShotgun = 0;
				//max is reserve ammo counter
				if(maxShotgun == 0)
				{
					std::cout<<"Rip You got no Ammo"<<std::endl;
				}
				while(maxShotgun > 0 && 16)
				{
					countShotgun ++;
					maxShotgun --;
				}
				std::cout<<"New Ammo Count: "<<countShotgun<<std::endl;

			}


		}

	}

	update(identifier, Xpos, Ypos);
}

void Bullet::update(int identifier, float X, float Y)
{
	if(identifier == 0){
		if(count0 == 0){
			std::cout<<"Identifier: Melee"<<std::endl;
			count0 ++;
		}
		for (m.start(); m.is_item(); m.advance()) {
			m.current();
			m.erase(X, Y);
		}

	} else if(identifier == 1)
	{
		if(count1 == 0){
			std::cout<<"Identifier: Pistol"<<std::endl;
			count1 ++;
		}
		for (p.start(); p.is_item(); p.advance()) {
			p.current();
			p.erase(X, Y);
		}
	} else if(identifier == 2)
	{
		//std::cout<<"Identifier: Smg"<<std::endl;
		for (s.start(); s.is_item(); s.advance()) {
			s.current();
			s.erase(X, Y);
		}
	} else if(identifier == 3)
	{
		if(count3 == 0){
			std::cout<<"Identifier: Rifle"<<std::endl;
			count3 ++;
		}
		for (r.start(); r.is_item(); r.advance()) {
			r.current();
			r.erase(X, Y);
		}
	} else if(identifier == 4)
	{
		if(count4 == 0){
			std::cout<<"Identifier: Shotgun"<<std::endl;
			count4 ++;
		}
		for (sh.start(); sh.is_item(); sh.advance()) {
			sh.current();
			sh.erase(X, Y);
		}
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
	}else if(identifier == 4)
	{
		maxRifle += 10;
	}
}


void Bullet::Draw(sf::RenderWindow& window, int identifier){
	if(identifier == 2){
		for (s.start(); s.is_item(); s.advance()) {
			s.currentDraw(window);
		}
	}else if(identifier == 0){
		for (m.start(); m.is_item(); m.advance()) {
			m.currentDraw(window);
		}

	} else if(identifier == 1)
	{
		for (p.start(); p.is_item(); p.advance()) {
			p.currentDraw(window);
		}
	}else if(identifier == 3)
	{
		for (r.start(); r.is_item(); r.advance()) {
			r.currentDraw(window);
		}
	}else if(identifier == 4)
	{
		for (sh.start(); sh.is_item(); sh.advance()) {
			sh.currentDraw(window);
		}
	}
}

void Bullet::resetFireRate()
{
	pistolFireRate = 10;
	smgFireRate = 14;
	shotgunFireRate = 39;
	rifleFireRate = 20;
	meleeFireRate = 5;
}
