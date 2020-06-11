#include "weapon.h"
#include <iostream>
weapons::weapons(){
    initSounds();
    flag = false;
}

weapons::weapons(int rate, int maxRate, int max, int current, int clipSize, int fire, int id, float dmg) : fireRate(rate), maxFireRate(maxRate), maxAMMO(max),
currentAMMO(current), clipSize(clipSize), shotFire(fire),  identifier(id), damage(dmg){
    initSounds();
    flag = false;

}

void weapons::initSounds(){
    Buffer[0].loadFromFile("content/Audio/knife/knife_slash1.wav");
    Buffer[1].loadFromFile("content/Audio/handgun/glock_01.wav");
    Buffer[2].loadFromFile("content/Audio/ak/ak47_01.wav");
    Buffer[3].loadFromFile("content/Audio/shotgun/nova-1.wav");

    drawBuffer[0].loadFromFile("content/Audio/knife/knife_deploy.wav");
	drawBuffer[1].loadFromFile("content/Audio/handgun/glock_draw.wav");
	drawBuffer[2].loadFromFile("content/Audio/ak/ak47_draw.wav");
	drawBuffer[3].loadFromFile("content/Audio/shotgun/nova_draw.wav");

    akBuffer[0].loadFromFile("content/Audio/ak/ak47_clipout.wav");
    akBuffer[1].loadFromFile("content/Audio/ak/ak47_clipin.wav");
    akBuffer[2].loadFromFile("content/Audio/ak/ak47_boltpull.wav");

    pistolBuffer[0].loadFromFile("content/Audio/handgun/glock_clipout.wav");
    pistolBuffer[1].loadFromFile("content/Audio/handgun/glock_clipin.wav");
    pistolBuffer[2].loadFromFile("content/Audio/handgun/glock_slideback.wav");
    pistolBuffer[3].loadFromFile("content/Audio/handgun/glock_sliderelease.wav");

    shotgunBuffer[0].loadFromFile("content/Audio/shotgun/nova_pump.wav");
    shotgunBuffer[1].loadFromFile("content/Audio/shotgun/nova_insertshell.wav");
    sound.setVolume(10);
    drawSound.setVolume(25);
    reloadSound.setVolume(25);
    reloadSound.setPitch(.8f);
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

void weapons::playReload(){
    int requiredBuffers;
    /*
    check if gun must be reloaded and sounds is playing
    */
    if (reloadSound.getStatus() == sf::Sound::Stopped && reload == true){
        if (identifier == 1){
            requiredBuffers = 3;
            reloadSound.setBuffer(pistolBuffer[reloadCount]);
            if (reloadCount != requiredBuffers)
                reloadCount++;
            else{
                reload = false;
                reloadCount = 0;
            }
        }
        else if (identifier == 2){
            requiredBuffers = 2;
            reloadSound.setBuffer(akBuffer[reloadCount]);
            if (reloadCount != requiredBuffers)
                reloadCount++;
            else{
                reload = false;
                reloadCount = 0;
            }
        }
        else if (identifier == 3){
            requiredBuffers = 8;
            if (reloadCount == 0){
                reloadSound.setBuffer(shotgunBuffer[reloadCount]);
                reloadCount++;
            }
            else{
                reloadSound.setBuffer(shotgunBuffer[1]);
                if (reloadCount != requiredBuffers)
                    reloadCount++;
                else{
                    reload = false;
                    reloadCount = 0;
                }
            }
        }
        reloadSound.play();
    }
    else if (reload == false && identifier == 3){
        reloadSound.setBuffer(shotgunBuffer[0]);
        reloadSound.play();
    }
}

bool weapons::fire(Bullet b)
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
            if (identifier == 3)
                playReload();
            currentAMMO --;
            fireRate = 0;
            return true;
        } else if (maxAMMO > 0){
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

            reload = true;

            playReload();
            if (maxAMMO >= clipSize){
                currentAMMO = clipSize;
                maxAMMO -= clipSize;
            }
            else{
                currentAMMO = maxAMMO;
                maxAMMO = 0;
            }
        }
    }
return false;

}

void weapons::movements(std::vector<std::shared_ptr<Zombie>> pool)
{
/*
checks if bullet exceed map grid
if so remove
*/
	for(unsigned int i = 0; i < gun.size(); i++){
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
                    float bullet_dmg = 40.f;
                    pool[j]->Damage(bullet_dmg);
                    break;
                }

                // if(gun[i].bullet.getGlobalBounds().intersects(pool[i]->getHitbox().getGlobalBounds())){
                //     // gun.erase(gun.begin() + i);
                // }

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
    /*
    checks if the bullet hits the zombie hitbox
    */
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
        maxAMMO += 12;
    else if (identifier == 2)
        maxAMMO += 30;
    else if (identifier == 3)
        maxAMMO += 8;
}