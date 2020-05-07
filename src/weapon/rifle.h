#ifndef RIFLE_H
#define RIFLE_H
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

class rifle
{
public:
	rifle();
	node<sf::CircleShape>* rifles;
	void reload(sf::CircleShape bullet,
                sf::Vector2f velocity, sf::Vector2f position);
	void push(sf::CircleShape bullet,
            	sf::Vector2f velocity, sf::Vector2f position);
	void current();
    void currentDraw(sf::RenderWindow& window);
	bool is_item();
	void start();
	void advance();
	void remove();
	int size();
	void erase(sf::RenderWindow& window);
	int currentIndex;
private:

};

#endif // RIFLE_H