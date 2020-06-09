#include "player.h"

Player::Player(sf::RenderTarget* target) {
	this->target = target;
	// TODO: REMOVE THIS
	// PLAYER SPAWN LOCATION
	const int grid_size = 50;
	const int grid_pos = 3;
	HP = 100;
	const int grid_pos_to_screen_pos = grid_size * grid_pos;
	position = sf::Vector2f(grid_pos_to_screen_pos, grid_pos_to_screen_pos);
	initSpriteTextures();
	initHitBox();
	initSound();
	velocity = sf::Vector2f(0.f,0.f);
}

void Player::Update() {
	entity_sprite.move(velocity);
	hitbox.move(velocity);
	position = entity_sprite.getPosition();
	// resetting velocity
	velocity = {0.f,0.f};
}

void Player::movement(){
	//Move Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		velocity.y += -movement_speed;
		WalkingSound();
	}
	//Move Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		velocity.x += -movement_speed;
		WalkingSound();
	}
	//Move Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		velocity.y += movement_speed;
		WalkingSound();
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		velocity.x += movement_speed;
		WalkingSound();
	}
}

void Player::WalkingSound(){
	if (Footsteps.getStatus() == sf::SoundSource::Stopped){
		Footsteps.setBuffer(walk);
		Footsteps.play();
	}
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
	if (mousePosition.x < window.getSize().x/2)
		quadrant = 1;
	//figures out the actual mouse position relative to the application, not the window
	mousePosition.x -= window.getSize().x/2;
    mousePosition.y -= window.getSize().y/2;
    mousePosition.x += position.x;
    mousePosition.y += position.y;
	slope = ((mousePosition.y - position.y) / (mousePosition.x - position.x));
	//finds the degree where the character is supposed to be looking at
	if (quadrant == 1)
		degree = (atan(slope) * (180 / PI)) - 180;
	else
		degree = atan(slope) * (180 / PI);
	//changes where the player is looking at according to where the mouse is pointing
	entity_sprite.setRotation(degree);
}

void Player::changeGun(int GLOBALIDENTIFIER){
	//0 = knife, 1 = pistol, 2 = smg, 3 = rifle, 4 = shotgun
	int x = sprites[GLOBALIDENTIFIER].getSize().x;
	int y = sprites[GLOBALIDENTIFIER].getSize().y;
	entity_sprite.setTextureRect(sf::IntRect(0, 0, x, y));
	if (!knifeAnimation)
		entity_sprite.setTexture(sprites[GLOBALIDENTIFIER]);
	else
		knifeSwings();
}

void Player::shootGun(int GLOBALIDENTIFIER){
	int x = shootingSprites[GLOBALIDENTIFIER].getSize().x;
	int y = shootingSprites[GLOBALIDENTIFIER].getSize().y;
	entity_sprite.setTextureRect(sf::IntRect(0, 0, x, y));
	if (GLOBALIDENTIFIER > 0 && !knifeAnimation)
		entity_sprite.setTexture(shootingSprites[GLOBALIDENTIFIER]);
	else{
		knifeAnimation = true;
		knifeSwings();
	}
}

void Player::knifeSwings(){
	std::cout<<"melee\n";
	if (knifeCount == count){
		entity_sprite.setTexture(knifeShooting[knifeCount]);
		knifeCount++;
	}
	else{
		entity_sprite.setTexture(knifeShooting[count]);
		count++;
	}
	if (knifeCount == 15 && count == 15){
		knifeAnimation = false;
		knifeCount = 0;
		count = 0;
	}
}

void Player::Draw(sf::RenderWindow& window){
	//window.draw(area);
	window.draw(entity_sprite);
	window.draw(hitbox);
}

void Player::initSpriteTextures(){
	sf::Texture rifle, rifleShooting, pistol, pistolShooting, knife, shotgun, shotgunShooting;
	std::string knifeInput;
	knifeAnimation = false;
	knifeCount = 0;
	count = 0;
	knife.loadFromFile("content/Top_Down_Survivor/knife/idle/survivor-idle_knife_0.png");
	pistol.loadFromFile("content/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_0.png");
	rifle.loadFromFile("content/Top_Down_Survivor/rifle/idle/survivor-idle_rifle_0.png");
	shotgun.loadFromFile("content/Top_Down_Survivor/shotgun/idle/survivor-idle_shotgun_0.png");
	sprites[0] = knife;
	sprites[1] = pistol;
	sprites[2] = pistol;
	sprites[3] = rifle;
	sprites[4] = shotgun;
	entity_sprite.setTexture(sprites[0]);
	entity_sprite.setScale(0.5, 0.5);
	entity_sprite.setOrigin(sprites[1].getSize().x/2, sprites[1].getSize().y/2);
	entity_sprite.setPosition(position.x, position.y);

	pistolShooting.loadFromFile("content/Top_Down_Survivor/handgun/shoot/weiner.png");
	rifleShooting.loadFromFile("content/Top_Down_Survivor/rifle/shoot/weiner1.png");
	shotgunShooting.loadFromFile("content/Top_Down_Survivor/shotgun/shoot/weiner2.png");
	shootingSprites[0] = knife;
	shootingSprites[1] = pistolShooting;
	shootingSprites[2] = pistolShooting;
	shootingSprites[3] = rifleShooting;
	shootingSprites[4] = shotgunShooting;
	for (int i = 0; i < 15; i++){
		knifeInput = "content/Top_Down_Survivor/knife/meleeattack/survivor-meleeattack_knife_" + std::to_string(i);
		knifeInput += ".png";
		knifeShooting[i].loadFromFile(knifeInput);
		knifeInput = "";
	}

}

void Player::initHitBox(){
	//initalization of hitbox values
	hitbox.setSize({entity_sprite.getGlobalBounds().width, entity_sprite.getGlobalBounds().height});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(5);
	hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setPosition(position.x, position.y);
	hitbox.setScale(0.5,0.5);

	//characterCenter = sf::Vector2f(position.x + 125, position.y + 150);
	area.setRadius(70);
    area.setFillColor(sf::Color::Green);
    area.setOrigin(75.0, 75.0);
    area.setPosition(position.x, position.y);
}

void Player::initSound(){
	sf::SoundBuffer rifleBuffer, handgunBuffer, shotgunBuffer, knifeBuffer;
	walk.loadFromFile("content/Audio/gravel.wav");
	Footsteps.setVolume(7);
}