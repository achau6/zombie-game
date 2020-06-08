#ifndef WEAPON_H
#define WEAPON_H

class weapons
{
public:
//constructors
    weapons();
    sf::Sound sound;
    sf::SoundBuffer smgSound;
    sf::SoundBuffer rifleSound;
    sf::SoundBuffer shotgunSound;
    sf::SoundBuffer pistolSound;
    sf::SoundBuffer meleeSound;
    //mutators
    void play(int identifier);

private:


};

#endif // WEAPON_H