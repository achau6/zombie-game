#include "ammo.h"


void Ammo_Box::Draw(sf::RenderWindow& window){
	for(unsigned int i = 0; i < ammo_pack.size(); i ++){
		window.draw(ammo_pack[i].first);
	}

}

void Ammo_Box::delete_box(sf::RectangleShape player, int identifier, pistol& p,
rifle& r, Shotgun& sh)
{
	for(unsigned int i = 0; i < ammo_pack.size(); i ++){
		if(collisionCheck(player, ammo_pack[i].second) == true){
			ammo_pack.erase(ammo_pack.begin() + i);
			if(identifier == 1){
				//p.add_ammo();
				p.add_ammo();
				//p.push(, false);
			} else if(identifier == 2){
				//s.push(Bullet(b));
			} else if(identifier == 3){
				r.add_ammo();
			} else if(identifier == 4){
				sh.add_ammo();
			}

		}
	}

}




void Ammo_Box::spawn_pack(sf::Vector2f position){
	if (!texture.loadFromFile("../zombie-game/content/ammo_crate.PNG")){
		std::cout<<"Shit dont work\n";
	}
	//initalization of sprite values
	entity_sprite.setTexture(texture);
	entity_sprite.setScale(.25,.25);
	//entity_sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
	entity_sprite.setPosition(position);
	//initalization of hitbox values
	hitbox.setSize({entity_sprite.getGlobalBounds().width, entity_sprite.getGlobalBounds().height});
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::White);
	hitbox.setOutlineThickness(10);
	//hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
	hitbox.setPosition(position);
	hitbox.setScale(.25, .25);


	ammo_pack.push_back(std::make_pair(entity_sprite, hitbox));
}

bool Ammo_Box::collisionCheck(sf::RectangleShape rect, sf::RectangleShape pool)
{
    sf::FloatRect zombie_entity = pool.getGlobalBounds();
    sf::FloatRect bullet = rect.getGlobalBounds();

    if(rect.getPosition().x < pool.getPosition().x + zombie_entity.width &&
			rect.getPosition().x + bullet.width > pool.getPosition().x &&
			rect.getPosition().y < pool.getPosition().y + zombie_entity.height &&
			bullet.height + rect.getPosition().y > pool.getPosition().y){
                return true;
            }

    return false;
}