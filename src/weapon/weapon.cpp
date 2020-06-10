#include "weapon.h"
#include <iostream>
weapons::weapons(){
    initSounds();
    flag = false;
}

weapons::weapons(int rate, int maxRate, int max, int current, int fire, int id) : fireRate(rate), maxFireRate(maxRate), maxAMMO(max),
currentAMMO(current), shotFire(fire),  identifier(id){
    initSounds();
    flag = false;

};

void weapons::initSounds(){
    Buffer[0].loadFromFile("content/Audio/knife/knife_slash1.wav");
    Buffer[1].loadFromFile("content/Audio/handgun/glock_01.wav");
    Buffer[2].loadFromFile("content/Audio/ak/ak47_01.wav");
    Buffer[3].loadFromFile("content/Audio/shotgun/nova-1.wav");

    drawBuffer[0].loadFromFile("content/Audio/knife/knife_deploy.wav");
	drawBuffer[1].loadFromFile("content/Audio/handgun/glock_draw.wav");
	drawBuffer[2].loadFromFile("content/Audio/ak/ak47_draw.wav");
	drawBuffer[3].loadFromFile("content/Audio/shotgun/nova_draw.wav");

    sound.setVolume(10);
    drawSound.setVolume(25);
}

void weapons::play()
{
    sound.setBuffer(Buffer[identifier]);
    sound.play();
}

void weapons::playDraw(){
    drawSound.setBuffer(drawBuffer[identifier]);
    drawSound.play();
}

void weapons::fire(Bullet b)
{
    if(getFlag() == true){
        add_ammo();
        flag = false;
        std::cout<<"adding ammo"<<std::endl;
    }
    /*
    controls how fast the gun is shooting.
    it takes every 10 counts for the next shot to fire
    */
    if(fireRate < maxFireRate){
        fireRate ++;
    }
    /*
        Decrease the amount of current bullet in the 'clip' (which is 10)
    */
    else if(fireRate >= maxFireRate){
        if(currentAMMO != 0){
            std::cout<<"Fire"<<std::endl;
            gun.push_back(b);
            play();
            currentAMMO --;
            fireRate = 0;
        } else {
            /*
            Fire stops when no bullet is found either in current ammo or his
            max ammo (stash)
            */
            if(maxAMMO == 0)
            {
                std::cout<<"Rip You got no Ammo"<<std::endl;
            }
            /*
            Adds ammo to his clip if he still has reserve up to the clip
            capacity
            */
           
           //using time pauses the game or crashes
                //double startTime = GetTickCount();

            while(maxAMMO > 0 && currentAMMO < 11)
            {
                // double currentTime = GetTickCount() - startTime;
                // // sf::Clock start;
                // // //start = clock();
                // int counter = 0;
		        // if(currentTime > 5000) {
                //     currentAMMO ++;
                //     maxAMMO --;
                // }

                currentAMMO ++;
                 maxAMMO --;
            }
        }
    }


}

void weapons::movements(std::vector<std::shared_ptr<Zombie>> pool)
{
/*
checks if bullet exceed map grid
if so remove
*/
	for(unsigned int i = 0; i < gun.size(); i ++){
		gun[i].bullet.move(gun[i].velocity);
		if(gun[i].bullet.getPosition().x < 0 || gun[i].bullet.getPosition().y < 0
		|| gun[i].bullet.getPosition().x > 3500 || gun[i].bullet.getPosition().y > 3500){
            gun.erase(gun.begin() + i);
		} else {

            for(unsigned int j = 0; j < pool.size(); j ++)
            {
                /*
                   checks if bullet touches another entity
                */
                if(collisionCheck(gun[i].bullet, pool, j) == true){
                    gun.erase(gun.begin() + i);
                }

            }
        }
	}
}

bool weapons::collisionCheck(sf::RectangleShape rect, std::vector<std::shared_ptr<Zombie>> pool, unsigned int count)
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
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; j++){
            if (level[i][j] == 1){
                if (rect.getPosition().y < ((i * 70) + 70) && rect.getPosition().y + bullet.height > (i * 70) && rect.getPosition().x < ((j * 70) + 70)
                    && bullet.width + rect.getPosition().x > (j * 70)){
                        return true;
                }
            }
        }
    }
    if(rect.getPosition().x < pool[count]->getHitbox().getPosition().x + zombie_entity.width &&
			rect.getPosition().x + bullet.width > pool[count]->getHitbox().getPosition().x &&
			rect.getPosition().y < pool[count]->getHitbox().getPosition().y + zombie_entity.height &&
			bullet.height + rect.getPosition().y > pool[count]->getHitbox().getPosition().y){
                return true;
            }

    return false;
}

void weapons::Draw(sf::RenderWindow& window){
    for (unsigned int i = 0; i < gun.size(); i++)
        window.draw(gun[i].bullet);
}

void weapons::add_ammo(){
    if (identifier == 1)
        maxAMMO += 15;
    else if (identifier == 2)
        maxAMMO += 15;
    else if (identifier == 3)
        maxAMMO += 15;
    else if (identifier == 4)
        maxAMMO += 5;
}