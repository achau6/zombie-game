#include "gun.h"
Gun::Gun(){
	GLOBALIDENTIFIER = 0;

}

void Gun::fire(sf::RenderWindow& window, float Xpos, float Ypos)
{
	float slope, degree, x, y;
	int quadrant;
	/*
	This helps us switch weapon
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		//identifier = 0;
		GLOBALIDENTIFIER = 0;
		p1.changeGun(0);
		std::cout<<"Melee"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		//identifier = 1;
		GLOBALIDENTIFIER = 1;
		p1.changeGun(1);
		std::cout<<"Pistol"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		//identifier = 2;
		GLOBALIDENTIFIER = 2;
		p1.changeGun(2);
		std::cout<<"SMG"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
		//identifier = 3;
		GLOBALIDENTIFIER = 3;
		p1.changeGun(3);
		std::cout<<"Rifle"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
		//identifier = 4;
		GLOBALIDENTIFIER = 4;
		p1.changeGun(4);
		std::cout<<"Shotgun"<<std::endl;
	}
	/*
	Complicated calculation to find mouse position
	Edit: will edit this later if i have time
	*/
	mousePosition.x = sf::Mouse::getPosition(window).x;
    mousePosition.y = sf::Mouse::getPosition(window).y;
	//Finds the quadrant
	if (mousePosition.x <= 640)
		quadrant = 1;
	mousePosition.x -= 640;
    mousePosition.y -= 360;
    mousePosition.x += Xpos;
    mousePosition.y += Ypos;
	//determines the slope from where the mouse is pointing at to the player position
	slope = ((mousePosition.y - Ypos) / (mousePosition.x - Xpos));
	//Determine what quadrant the player is pointing at, then figures out the degree depending on that
	switch (quadrant){
		case 1:
			degree = (atan(slope) * (180 / PI)) - 180;
			break;
		default:
			degree = atan(slope) * (180 / PI);
			break;
	}
	//Small increase in degrees to move from the center of the sprite to where the gun is pointing at
	degree += 22;
	//Determines the x and y axis to find the position where the comes out from
	x = Xpos + 60*cos(degree * (PI/180));
	y = Ypos + 64*sin(degree * (PI/180));

	bulletCenter = sf::Vector2f(x, y);
	//degree  = atan2(x, y);
	//determines the direction of the bullet


	//back to radian
	degree -= 22;
	degree = degree * (PI/180);

	x = cos(degree);
	y = sin(degree);
	b.velocity.x = x * b.maxSpeed;
	b.velocity.y = y * b.maxSpeed;
	// float newX, newY;
	// newX = mousePosition.x - x;
	// newY = mousePosition.y - y;
	// float magnitude = sqrt((newX*newX) + (newY*newY));
	// b.velocity.x = newX/magnitude * b.maxSpeed;
	// b.velocity.y = newY/magnitude * b.maxSpeed;
	//float calc = -1.00;

	//aimView = mousePosition - bulletCenter;
	//float num = sqrt(pow(aimView.x, 2) + pow(aimView.y, 2));
	//aimViewNormalized = aimView / num;

	//aimViewNormalized = sf::Vector2f(-1.0, -1.0);
	//pass the speed to bullet object
	//b.velocity = aimViewNormalized * b.maxSpeed;
	b.bullet.setPosition(bulletCenter);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		/*
		adds the bullet in and play the shooting sound
		although may move it to individual class (ex. pistol.h)
		*/
	std::cout<<"X: "<<bulletCenter.x<<", Y: "<<bulletCenter.y<<std::endl;
	std::cout<<"x: "<<mousePosition.x<<", y: "<<mousePosition.y<<std::endl;
	//std::cout<<"EX: "<<aimView.x<<", EY: "<<aimView.y<<std::endl;
	//std::cout<<"aim: "<<aimViewNormalized.x<<", "<<aimViewNormalized.y<<std::endl;
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
		//std::cout<<"GLOBAL"<<std::endl;
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
		//std::cout<<"Draw"<<std::endl;
	} else if(identifier == 2){
		s.Draw(window);
	} else if(identifier == 3){
		r.Draw(window);
	} else if(identifier == 4){
		sh.Draw(window);
	}
}

