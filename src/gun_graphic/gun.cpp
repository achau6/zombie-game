#include "gun.h"

Gun::Gun(){
	GLOBALIDENTIFIER = 0;
	p = weapons(0, 35, 24, 12, 12, 0, 1, 20.f);
	r = weapons(0, 18, 30, 30, 30, 0, 2, 30.f);
	sh = weapons(60, 80, 8, 8, 8, 0 , 3, 50.f);
	degreeAngle = 22;
}

bool Gun::fire(sf::RenderWindow& window, float Xpos, float Ypos, std::vector<std::shared_ptr<Zombie>> pool,
Player& player)
{
	float slope, degree, x, y, copyX, copyY;
	int quadrant;
	bool fired = false;
	/*
	find mouse position relative to game window
	*/
	mousePosition.x = sf::Mouse::getPosition(window).x;
    mousePosition.y = sf::Mouse::getPosition(window).y;
	//Finds the quadrant
	if (mousePosition.x <= window.getSize().x/2)
		quadrant = 1;
	else
		quadrant = 0;
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
		/*
	This helps us switch weapon
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && GLOBALIDENTIFIER != 0){
		//identifier = 0;
		GLOBALIDENTIFIER = 0;
		m.playDraw();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && GLOBALIDENTIFIER != 1){
		//identifier = 1;
		GLOBALIDENTIFIER = 1;
		degreeAngle = 22;
		p.playDraw();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && GLOBALIDENTIFIER != 2){
		//identifier = 2;
		GLOBALIDENTIFIER = 2;
		degreeAngle = 18;
		r.playDraw();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && GLOBALIDENTIFIER != 3){
		//identifier = 3;
		GLOBALIDENTIFIER = 3;
		degreeAngle = 18;
		sh.playDraw();
	}
	//Small increase in degrees to move from the center of the sprite to where the gun is pointing at
	degree += degreeAngle;
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
	degree -= degreeAngle;
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

		if(GLOBALIDENTIFIER == 0)
			fired = m.push(KnifeBullet(k));
		else if(GLOBALIDENTIFIER == 1)
			fired = p.fire(Bullet(b));
		else if(GLOBALIDENTIFIER == 2)
			fired = r.fire(Bullet(b));
		else if(GLOBALIDENTIFIER == 3)
			fired = sh.fire(Bullet(b));
	}
	movement(pool, Xpos, Ypos, player);
	return fired;
}

void Gun::SpawnHealth_Pack(sf::Vector2f position) {
	health.spawn_pack(position);
}

void Gun::spawnAmmo_Box(sf::Vector2f position){
	ammo.spawn_pack(position);
}
/*
Gives the movement of the gun path
*/
void Gun::movement(std::vector<std::shared_ptr<Zombie>> pool, float x, float y,
Player& player)
{
		m.movement(pool, x, y);
		p.movements(pool);
		r.movements(pool);
		sh.movements(pool);
		ammo.delete_box(player.getHitbox(), getGlobalIdentifier(), p, r, sh);
		health.delete_health_pack(player);

}

/*
Draws the bullet and bullet movement path
*/
void Gun::Draw(sf::RenderWindow& window)
{
	//m.Draw(window);
	p.Draw(window);
	r.Draw(window);
	sh.Draw(window);
	health.Draw(window);
	ammo.Draw(window);

}

bool Gun::Update(std::vector<std::shared_ptr<Zombie>> pool){
	if (p.getReload()){
		p.playReload();
		p.movements(pool);
		return true;
	}
	else if (r.getReload()){
		r.playReload();
		r.movements(pool);
		return true;
	}
	else if (sh.getReload()){
		sh.playReload();
		sh.movements(pool);
		return true;
	}
	return false;
}

//returns ammo for current gun, 1st is current, 2nd is reserve
std::pair<int, int> Gun::getAmmo(){
	std::pair<int, int> ammo;
	switch (getGlobalIdentifier()){
		case 0:
			ammo.first = m.getCurrentAmmo();
			ammo.second = m.getMaxAmmo();
			break;
		case 1:
			ammo.first = p.getCurrentAmmo();
			ammo.second = p.getMaxAmmo();
			break;
		case 2:
			ammo.first = r.getCurrentAmmo();
			ammo.second = r.getMaxAmmo();
			break;
		case 3:
			ammo.first = sh.getCurrentAmmo();
			ammo.second = sh.getMaxAmmo();
			break;
	}
	return ammo;
}


