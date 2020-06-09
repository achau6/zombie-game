#include "gun.h"

Gun::Gun(){
	GLOBALIDENTIFIER = 0;
}

void Gun::fire(sf::RenderWindow& window, float Xpos, float Ypos, std::vector<std::shared_ptr<Zombie>> pool, Player& player)
{
	float slope, degree, x, y, copyX, copyY;
	int quadrant;

	/*
	This helps us switch weapon
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		//identifier = 0;
		GLOBALIDENTIFIER = 0;
		player.changeGun(0);
		std::cout<<"Melee"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		//identifier = 1;
		GLOBALIDENTIFIER = 1;
		player.changeGun(1);
		std::cout<<"Pistol"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		//identifier = 2;
		GLOBALIDENTIFIER = 2;
		player.changeGun(2);
		std::cout<<"SMG"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
		//identifier = 3;
		GLOBALIDENTIFIER = 3;
		player.changeGun(3);
		std::cout<<"Rifle"<<std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
		//identifier = 4;
		GLOBALIDENTIFIER = 4;
		player.changeGun(4);
		std::cout<<"Shotgun"<<std::endl;
	}
	/*
	Complicated calculation to find mouse position
	Edit: will edit this later if i have time
	*/
	mousePosition.x = sf::Mouse::getPosition(window).x;
    mousePosition.y = sf::Mouse::getPosition(window).y;
	//Finds the quadrant
	if (mousePosition.x <= window.getSize().x/2)
		quadrant = 1;
	mousePosition.x -= window.getSize().x/2;
    mousePosition.y -= window.getSize().y/2;
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

	/*
	Values for Dupe Bullet Class in case of changes needed for melee class
	*/
	degree -= 50;
	copyX = Xpos + 1*cos(degree * (PI/180));
	copyY = Ypos + 4*sin(degree * (PI/180));
	knifeCenter = sf::Vector2f(copyX, copyY);
	degree += 50;

	//back to radian
	degree -= 22;
	degree = degree * (PI/180);

	//get x and y values for linear displacement
	x = cos(degree);
	y = sin(degree);

	//adding speed to displacement
	b.velocity.x = x * b.maxSpeed;
	b.velocity.y = y * b.maxSpeed;
	b.bullet.setPosition(bulletCenter);

	k.velocity.x = x * k.maxSpeed;
	k.velocity.y = y * k.maxSpeed;
	k.bullet.setPosition(knifeCenter);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		/*
		adds the bullet in and play the shooting sound
		although may move it to individual class (ex. pistol.h)
		*/

		if(GLOBALIDENTIFIER == 0){
			m.push(KnifeBullet(k));
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
	movement(GLOBALIDENTIFIER, pool, Xpos, Ypos);
}

/*
Gives the movement of the gun path
*/
void Gun::movement(int identifier, std::vector<std::shared_ptr<Zombie>> pool, float x, float y)
{
		m.movement(pool, x, y);
		p.movement(pool);
		s.movement(pool);
		r.movement(pool);
		sh.movement(pool);

}

/*
Draws the bullet and bullet movement path
*/
void Gun::Draw(sf::RenderWindow& window, int identifier)
{
	m.Draw(window);
	p.Draw(window);
	s.Draw(window);
	r.Draw(window);
	sh.Draw(window);

}

