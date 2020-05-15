#include "player.h"

Player::Player(sf::RenderTarget* target) {
	this->target = target;
	position.x = target->getSize().x/2.f;
	position.y = target->getSize().y/2.f;
	if (!texture.loadFromFile("../zombie-game/content/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_0.png"))
		std::cout<<"Shit dont work\n";
	//initalization of sprite values
	player.first.setTexture(texture);
	player.first.setOrigin(100.0, 100.0);
	player.first.setScale(0.5, 0.5);
	player.first.setPosition(position.x, position.y);
	//initalization of hitbox values
	player.second.setFillColor(sf::Color(0,0,0,0));
	player.second.setOutlineColor(sf::Color::White);
	player.second.setOutlineThickness(1);
	player.second.setOrigin(30.0, 28.0);
	player.second.setSize(sf::Vector2f(85, 75));
	player.second.setPosition(position.x, position.y);
	//characterCenter = sf::Vector2f(position.x + 125, position.y + 150);
	area.setRadius(75);
    area.setFillColor(sf::Color::Green);
    area.setOrigin(75.0, 75.0);
    area.setPosition(position.x, position.y);

	velocity = sf::Vector2f(0.f,0.f);
}

void Player::movement(){
	//Move Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (collisionCheck.legalMovement(position.x, position.y - movement_speed)){
			velocity.y += -movement_speed;
		}
	}
	//Move Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (collisionCheck.legalMovement(position.x - movement_speed, position.y)){
			velocity.x += -movement_speed;
		}
	}
	//Move Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (collisionCheck.legalMovement(position.x, position.y + movement_speed)){
			velocity.y += movement_speed;
		}
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (collisionCheck.legalMovement(position.x + movement_speed, position.y)){
			velocity.x += movement_speed;
		}
	}

	player.first.move(velocity);
	player.second.move(velocity);
	position = player.first.getPosition();

	// resetting velocity
	velocity = {0.f,0.f};
}

sf::Vector2u Player::getGridPosition(const sf::Vector2u& grid_size) {
	if(position.x > 0)
		grid_pos.x = position.x / grid_size.x;
	if(position.y > 0)
		grid_pos.y = position.y / grid_size.y;

	return grid_pos;
}

void Player::look(sf::RenderWindow& window){
	//float x, y;
	const float PI = 3.141592653589;
	float degree;
	double slope;
	int quadrant;
	mousePosition.x = sf::Mouse::getPosition(window).x;
    mousePosition.y = sf::Mouse::getPosition(window).y;
	//determines the quadrant your mouse is looking at
	if (mousePosition.x < 640)
		quadrant = 1;
	//figures out the actual mouse position relative to the application, not the window
	mousePosition.x -= 640;
    mousePosition.y -= 360;
    mousePosition.x += position.x;
    mousePosition.y += position.y;
	slope = ((mousePosition.y - position.y) / (mousePosition.x - position.x));
	//finds the degree where the character is supposed to be looking at
	switch(quadrant){
		case 1:
			degree = (atan(slope) * (180 / PI)) - 180;
			break;
		default:
			degree = atan(slope) * (180 / PI);
	}
	//changes where the player is looking at according to where the mouse is pointing
	player.first.setRotation(degree);
	player.second.setRotation(degree);
	//Look portion to determine where the gun is shooting
	// characterCenter = sf::Vector2f(position.x + RADIUS,position.y + RADIUS);
	// mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	// directionalView = mousePosition - characterCenter;
	// float num = sqrt(pow(directionalView.x, 2) + pow(directionalView.y, 2));
	// directionalViewNormalized = directionalView / num;
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(player.second);
	// window.draw(area);
	window.draw(player.first);
}
