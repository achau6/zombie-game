#ifndef WEAPON_H
#define WEAPON_H

template<class T>
struct node{
    sf::CircleShape shape;
    node<T>* next;
    node<T>* prev;
    int key;
    sf::Vector2f currentVelocity;
};

class weapons
{
public:
    //typdef
    //constructor
    weapons();
	//accessors


	// //mutators
    // //-------------Main Functions----

    void reload(node<sf::CircleShape>* &head, sf::CircleShape bullet,
                 sf::Vector2f velocity);
    // //--------------------------


    void pick_Up_Gun(node<sf::CircleShape>* &head);



    //nodes
    void remove(node<sf::CircleShape>* &head);
    bool is_item(node<sf::CircleShape>* &head);
    void start();
    void advance();
    void current(node<sf::CircleShape>* &head);
    void currentDraw(sf::RenderWindow& window,
                node<sf::CircleShape>* &head);

    void printCheck(node<sf::CircleShape>* &head);


    //nodes
    node<sf::CircleShape>* smgs;
    node<sf::CircleShape>* shotguns;
    node<sf::CircleShape>* shotgunsHead;
    node<sf::CircleShape>* shotgunsTail;

    node<sf::CircleShape>* pistols;
    node<sf::CircleShape>* rifles;
    int currentIndex;

private:


};

#endif // WEAPON_H