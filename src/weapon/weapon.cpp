#include "weapon.h"
#include <iostream>
weapons::weapons(){
    Buffer[0].loadFromFile("content/Audio/knife/knife_slash1.wav");
    Buffer[1].loadFromFile("content/Audio/handgun/glock_01.wav");
    Buffer[2].loadFromFile("../zombie-game/content/Audio/MP5_SMG-GunGuru-703432894.wav");
    Buffer[3].loadFromFile("content/Audio/ak/ak47_01.wav");
    Buffer[4].loadFromFile("content/Audio/shotgun/nova-1.wav");

    drawBuffer[0].loadFromFile("content/Audio/knife/knife_deploy.wav");
	drawBuffer[1].loadFromFile("content/Audio/handgun/glock_draw.wav");
	drawBuffer[2].loadFromFile("content/Audio/handgun/glock_draw.wav");
	drawBuffer[3].loadFromFile("content/Audio/ak/ak47_draw.wav");
	drawBuffer[4].loadFromFile("content/Audio/shotgun/nova_draw.wav");

    sound.setVolume(30);
    drawSound.setVolume(25);
}

void weapons::play(int identifier)
{
    sound.setBuffer(Buffer[identifier]);
    sound.play();
}

void weapons::playDraw(int identifier){
    drawSound.setBuffer(drawBuffer[identifier]);
    drawSound.play();
}
