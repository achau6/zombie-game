#include "ammo.h"


void Ammo_Box::Draw(sf::RenderWindow& window){
	for(unsigned int i = 0; i < ammo_pack.size(); i ++){
		window.draw(ammo_pack[i].first);
		//window.draw(ammo_pack[i].second);
	}


}

void Ammo_Box::delete_box(sf::RectangleShape player, int identifier, weapons& p,
weapons& r, weapons& sh)
{
	for(unsigned int i = 0; i < ammo_pack.size(); i ++){
		if(collisionCheck(player, ammo_pack[i].second) == true){
			ammo_pack.erase(ammo_pack.begin() + i);
				if(identifier == 1){
					p.flaggin();
				} else if(identifier == 2){
					r.flaggin();
				} else if(identifier == 3){
					sh.flaggin();
				}
		}
	}

}




void Ammo_Box::spawn_pack(sf::Vector2f position){
	if (!texture.loadFromFile("../zombie-game/content/ammo_crate.png")){
		std::cout<<"Shit dont work\n";
	}
	//initalization of sprite values
	entity_sprite.setTexture(texture);
	entity_sprite.setScale(.18,.18);
	entity_sprite.setOrigin({texture.getSize().x/2, texture.getSize().y/2});
	entity_sprite.setPosition(position);


	hitbox.setSize({entity_sprite.getGlobalBounds().width+150, entity_sprite.getGlobalBounds().height+150});
	hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setOutlineColor(sf::Color::Black);
	hitbox.setOutlineThickness(5);
	hitbox.setPosition(position);
	hitbox.setScale(.18, .18);


	ammo_pack.push_back(std::make_pair(entity_sprite, hitbox));
}

bool Ammo_Box::collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool)
{
	sf::FloatRect new_rect = rect.getGlobalBounds();
	sf::FloatRect new_pool = pool.getGlobalBounds();

	if(new_rect.intersects(new_pool)){
		return true;
	}

    return false;
}