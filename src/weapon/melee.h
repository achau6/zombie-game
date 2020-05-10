#ifndef MELEE_H
#define MELEE_H
#include <iostream>
#include "weapon/weapon.h"
#include "player/player.h"

template<class T>
struct Node{
    sf::CircleShape shape1;
	sf::CircleShape shape2;
    sf::CircleShape shape3;
    sf::CircleShape shape4;
    sf::CircleShape shape5;


    Node<T>* next;
    Node<T>* prev;
    int key;
    sf::Vector2f currentVelocity1;
    sf::Vector2f currentVelocity2;
    sf::Vector2f currentVelocity3;
    sf::Vector2f currentVelocity4;
	sf::Vector2f currentVelocity5;


};

class Melee
{
public:
	Melee();
	Node<sf::CircleShape>* melees;
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
#endif // MELEE_H