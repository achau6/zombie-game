#include "player.h"

Player::Player(sf::RenderTarget* target){
	positionx = target->getSize().x/2.f;
	positiony = target->getSize().y/2.f;
	this->target = target;
	if (!texture.loadFromFile("../zombie-game/content/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_0.png"))
		std::cout<<"Shit dont work\n";
	//initalization of sprite values
	player.first.setTexture(texture);
	player.first.setOrigin(100.0, 100.0);
	player.first.setScale(0.5, 0.5);
	player.first.setPosition(positionx, positiony);
	//initalization of hitbox values
	player.second.setFillColor(sf::Color::White);
	player.second.setOrigin(30.0, 28.0);
	player.second.setSize(sf::Vector2f(85, 75));
	player.second.setPosition(positionx, positiony);
	//characterCenter = sf::Vector2f(positionx + 125, positiony + 150);
	area.setRadius(75);
    area.setFillColor(sf::Color::Green);
    area.setOrigin(75.0, 75.0);
    area.setPosition(positionx, positiony);
}

void Player::movement(){
	//Move Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (collisionCheck.legalMovement(positionx, positiony - UNITS)){
			player.first.setPosition(positionx, positiony - UNITS);
			player.second.setPosition(positionx, positiony - UNITS);
			positiony -= UNITS;
			//Diagonally move up and right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				if (collisionCheck.legalMovement(positionx + UNITS, positiony)){
					player.first.setPosition(positionx + UNITS, positiony);
					player.second.setPosition(positionx + UNITS, positiony);
					positionx += UNITS;
				}
			}
			//Diagonally move up and left
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				if (collisionCheck.legalMovement(positionx - UNITS, positiony)){
					player.first.setPosition(positionx - UNITS, positiony);
					player.second.setPosition(positionx - UNITS, positiony);
					positionx -= UNITS;
				}
			}
		}
	}
	//Move Left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (collisionCheck.legalMovement(positionx - UNITS, positiony)){
			player.first.setPosition(positionx - UNITS, positiony);
			player.second.setPosition(positionx - UNITS, positiony);
			positionx -= UNITS;
			//Diagonally move left and up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				if (collisionCheck.legalMovement(positionx, positiony - UNITS)){
					player.first.setPosition(positionx, positiony - UNITS);
					player.second.setPosition(positionx, positiony - UNITS);
					positiony -= UNITS;
				}
			}
			//Diagonally move left and down
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
				if (collisionCheck.legalMovement(positionx, positiony + UNITS)){
					player.first.setPosition(positionx, positiony + UNITS);
					player.second.setPosition(positionx, positiony + UNITS);
					positiony += UNITS;
				}
			}
		}
	}
	//Move Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (collisionCheck.legalMovement(positionx, positiony + UNITS)){
			player.first.setPosition(positionx, positiony + UNITS);
			player.second.setPosition(positionx, positiony + UNITS);
			positiony += UNITS;
			//Diagonally move down and right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				if (collisionCheck.legalMovement(positionx + UNITS, positiony)){
					player.first.setPosition(positionx + UNITS, positiony);
					player.second.setPosition(positionx + UNITS, positiony);
					positionx += UNITS;
				}
			}
			//Diagonally move down and left
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				if (collisionCheck.legalMovement(positionx - UNITS, positiony)){
					player.first.setPosition(positionx - UNITS, positiony);
					player.second.setPosition(positionx - UNITS, positiony);
					positionx -= UNITS;
				}
			}
		}
	}
	//Move Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (collisionCheck.legalMovement(positionx + UNITS, positiony)){
			player.first.setPosition(positionx + UNITS, positiony);
			player.second.setPosition(positionx + UNITS, positiony);
			positionx += UNITS;
			//Diagonally move right and up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				if (collisionCheck.legalMovement(positionx, positiony - UNITS)){
					player.first.setPosition(positionx, positiony - UNITS);
					player.second.setPosition(positionx, positiony - UNITS);
					positiony -= UNITS;
				}
			}
			//Diagonally move right and down
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
				if (collisionCheck.legalMovement(positionx, positiony + UNITS)){
					player.first.setPosition(positionx, positiony + UNITS);
					player.second.setPosition(positionx, positiony + UNITS);
					positiony += UNITS;
				}
			}
		}
	}
}

sf::Vector2u Player::getGridPosition(const sf::Vector2u& grid_size) {
	if(positionx > 0)
		grid_pos.x = positionx / grid_size.x;
	if(positiony > 0)
		grid_pos.y = positiony / grid_size.y;

	return grid_pos;
}

void Player::look(sf::RenderWindow& window){
	//float x, y;
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
    mousePosition.x += positionx;
    mousePosition.y += positiony;
	slope = ((mousePosition.y - positiony) / (mousePosition.x - positionx));
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
	// characterCenter = sf::Vector2f(positionx + RADIUS,positiony + RADIUS);
	// mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	// directionalView = mousePosition - characterCenter;
	// float num = sqrt(pow(directionalView.x, 2) + pow(directionalView.y, 2));
	// directionalViewNormalized = directionalView / num;
}

void Player::Draw(sf::RenderWindow& window){
	//window.draw(player.second);
	//window.draw(area);
	window.draw(player.first);
}
