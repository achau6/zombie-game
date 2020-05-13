#include "weapon.h"
#include <iostream>
weapons::weapons()
{}

void weapons::play(int identifier)
{
    if(identifier == 0){

	} else if(identifier == 1){
		if(!pistolSound.loadFromFile("../zombie-game/content/Audio/9_mm_gunshot-mike-koenig-123.wav")){
            std::cout<<"Shit Don't Work"<<std::endl;
        } else {
            sound.setBuffer(pistolSound);
        }
	} else if(identifier == 2){
		if(!smgSound.loadFromFile("../zombie-game/content/Audio/MP5_SMG-GunGuru-703432894.wav")){
            std::cout<<"Shit Don't Work"<<std::endl;
        } else {
            sound.setBuffer(smgSound);
        }
	} else if(identifier == 3){
		if(!rifleSound.loadFromFile("../zombie-game/content/Audio/M4A1_Single-Kibblesbob-8540445.wav")){
            std::cout<<"Shit Don't Work"<<std::endl;
        } else {
            sound.setBuffer(rifleSound);
        }
	} else if(identifier == 4){
		if(!shotgunSound.loadFromFile("../zombie-game/content/Audio/shotgun-mossberg590-RA_The_Sun_God-451502290.wav")){
            std::cout<<"Shit Don't Work"<<std::endl;
        } else {
            sound.setBuffer(shotgunSound);
        }
	}
    sound.setVolume(0.5f);
    sound.play();
}
