#include "melee.h"


Melee::Melee() : weapons(0, 10, 0, 0, 0, 0, 0, 15)
{
    fireRate = 0;
}

bool Melee::push(KnifeBullet b)
{
    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < 20){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= 9){
            melees.push_back(b);
            w.play();
            fireRate = 0;
            return true;
    }
    return false;

}

void Melee::movement(std::vector<std::shared_ptr<Zombie>> pool, float x, float y)
{
/*
checks if bullet exceed map grid
if so remove
*/
	for(unsigned int i = 0; i < melees.size(); i ++){
		melees[i].bullet.move(melees[i].velocity);
		if(melees[i].bullet.getPosition().x < x - 70 || melees[i].bullet.getPosition().y < y - 70
		|| melees[i].bullet.getPosition().x > x + 70 || melees[i].bullet.getPosition().y > y + 70){
            melees.erase(melees.begin() + i);
		} else {

            for(unsigned int j = 0; j < pool.size(); j ++)
            {
                /*
                   checks if bullet touches another entity
                */
                if(collisionCheck(melees[i].bullet, pool, j) == true){
                    melees.erase(melees.begin() + i);
                }

            }
        }
	}

}

bool Melee::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
{
/*
Get the bounds of the rectangle shape
*/

    sf::FloatRect zombie_entity = pool[count]->getHitbox().getGlobalBounds();
    sf::FloatRect bullet = rect.getGlobalBounds();

/*
Checks the all corners of the rectangle (init x pos, init y pos, width, and length)
it checks a rectangle touches another rectange 'area' then return true
*/
    if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
                return true;
            }

    return false;
}
void Melee::Draw(sf::RenderWindow& window)
{
	for(unsigned int i = 0; i < melees.size(); i ++){
		window.draw(melees[i].bullet);
	}
}
