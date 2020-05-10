#ifndef SMG_H
#define SMG_H
#include <iostream>
#include "weapon/weapon.h"
#include "player/player.h"

// template<class T>
// struct node{
//     sf::CircleShape shape;
//     node<T>* next;
//     node<T>* prev;
//     int key;
//     sf::Vector2f currentVelocity;
// };

class smg
{
public:
	smg();
	node<sf::CircleShape>* smgs;
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

#endif // SMG_H