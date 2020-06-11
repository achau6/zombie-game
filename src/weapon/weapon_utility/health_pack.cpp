#include "health_pack.h"

Health::Health()
{

}

void Health::Draw(sf::RenderWindow& window){

	for(unsigned int i = 0; i < health_pack.size(); i ++){
		window.draw(health_pack[i].first);
	}

}

void Health::delete_health_pack(Player& player)
{
	for(unsigned int i = 0; i < health_pack.size(); i ++){
		if(collisionCheck(player.getHitbox(), health_pack[i].second) == true){
			health_pack.erase(health_pack.begin() + i);
			player.addHp();
		}
	}
}




void Health::spawn_pack(sf::Vector2f position){
	if (!texture.loadFromFile("../zombie-game/content/Health_pack.PNG")){
		std::cout<<"Shit dont work\n";
	}
	//initalization of sprite values
	entity_sprite.setTexture(texture);
	entity_sprite.setScale(.12,.12);
	entity_sprite.setOrigin({texture.getSize().x/2, texture.getSize().y/2});
	entity_sprite.setPosition(position);

	//initalization of hitbox values
	hitbox.setSize({entity_sprite.getGlobalBounds().width+150, entity_sprite.getGlobalBounds().height+150});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(10);
	hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setPosition(position);
	hitbox.setScale(.12, .12);


	health_pack.push_back(std::make_pair(entity_sprite, hitbox));
}

bool Health::collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool)
{

/*
Checks the all corners of the rectangle (init x pos, init y pos, width, and length)
it checks a rectangle touches another rectange 'area' then return true
*/
	sf::FloatRect new_rect = rect.getGlobalBounds();
	sf::FloatRect new_pool = pool.getGlobalBounds();

	if(new_rect.intersects(new_pool)){
		return true;
	}

    return false;

    return false;
}