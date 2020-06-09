#ifndef WEAPON_H
#define WEAPON_H
#include "map"
class weapons
{
public:
//constructors
    weapons();
    sf::Sound sound, drawSound;
    sf::SoundBuffer Buffer[5], drawBuffer[5];

    //mutators
    void play(int identifier);
    void playDraw(int identifier);
private:


};

#endif // WEAPON_H