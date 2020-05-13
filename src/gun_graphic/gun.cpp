#include "gun.h"
Gun::Gun(){
	GLOBALIDENTIFIER = 0;

}

void Gun::fire(sf::RenderWindow& window, float Xpos, float Ypos)
{
	/*
	This helps us switch weapon
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		//identifier = 0;
		GLOBALIDENTIFIER = 0;
		std::cout<<"Melee"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		//identifier = 1;
		GLOBALIDENTIFIER = 1;
		std::cout<<"Pistol"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		//identifier = 2;
		GLOBALIDENTIFIER = 2;
		std::cout<<"SMG"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
		//identifier = 3;
		GLOBALIDENTIFIER = 3;
		std::cout<<"Rifle"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
		//identifier = 4;
		GLOBALIDENTIFIER = 4;
		std::cout<<"Shotgun"<<std::endl;
	}
	/*
	Complicated calculation to find mouse position
	Edit: will edit this later if i have time
	*/
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

	//pass the speed to bullet object
	b.velocity = aimViewNormalized * b.maxSpeed;
	b.bullet.setPosition(bulletCenter);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		/*
		adds the bullet in and play the shooting sound
		although may move it to individual class (ex. pistol.h)
		*/
		if(GLOBALIDENTIFIER == 0){

		} else if(GLOBALIDENTIFIER == 1){
			p.push(Bullet(b));
		} else if(GLOBALIDENTIFIER == 2){
			s.push(Bullet(b));
		} else if(GLOBALIDENTIFIER == 3){
			r.push(Bullet(b));
		} else if(GLOBALIDENTIFIER == 4){
			sh.push(Bullet(b));
		}
	}
	movement(GLOBALIDENTIFIER);
}

/*
Gives the movement of the gun path
*/
void Gun::movement(int identifier)
{
	if(identifier == 0){

	} else if(identifier == 1){
		p.movement();
		std::cout<<"GLOBAL"<<std::endl;
	} else if(identifier == 2){
		s.movement();
	} else if(identifier == 3){
		r.movement();
	} else if(identifier == 4){
		sh.movement();
	}
}

/*
Draws the bullet and bullet movement path
*/
void Gun::Draw(sf::RenderWindow& window, int identifier)
{
	if(identifier == 0){

	} else if(identifier == 1){
		p.Draw(window);
		std::cout<<"Draw"<<std::endl;
	} else if(identifier == 2){
		s.Draw(window);
	} else if(identifier == 3){
		r.Draw(window);
	} else if(identifier == 4){
		sh.Draw(window);
	}
}

