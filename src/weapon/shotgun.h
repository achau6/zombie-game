#ifndef SHOTGUN_H
#define SHOTGUN_H
#include <iostream>
#include "weapon/weapon.h"
#include "player/player.h"

template<class T>
struct Nodes{
    sf::CircleShape shape1;
    sf::CircleShape shape2;
    sf::CircleShape shape3;

    Nodes<T>* next;
    Nodes<T>* prev;
    int key;
    sf::Vector2f currentVelocity1;
	sf::Vector2f currentVelocity2;
    sf::Vector2f currentVelocity3;

};

class Shotgun
{
public:
	Shotgun();
	Nodes<sf::CircleShape>* shotguns;
	Player p1;
	void reload(sf::CircleShape bullet,
                sf::Vector2f velocity, sf::Vector2f position);
	void push(sf::CircleShape bullet,
            	sf::Vector2f velocity, sf::Vector2f position);
	void erase(float X, float Y);
	void current();
    void currentDraw(sf::RenderWindow& window);
	bool is_item();
	void start();
	void advance();
	void remove();
	int size();
	int currentIndex;
private:

};

#endif // SHOTGUN_H