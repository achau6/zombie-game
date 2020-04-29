#ifndef PISTOL_H
#define PISTOL_H
#include <iostream>
#include "weapon/weapon.h"


// template<class T>
// struct node{
//     sf::CircleShape shape;
//     node<T>* next;
//     node<T>* prev;
//     int key;
//     sf::Vector2f currentVelocity;
// };

class pistol
{
public:
	pistol();
	node<sf::CircleShape>* pistols;
	void reload(sf::CircleShape bullet,
                sf::Vector2f velocity);
	void push(sf::CircleShape bullet,
            	sf::Vector2f velocity);
	void current();
    void currentDraw(sf::RenderWindow& window);
	bool is_item();
	void start();
	void advance();
	void remove();
	int currentIndex;
private:

};

#endif // PISTOL_H