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
    // void decrease_Bullets(sf::CircleShape array[]);
    // void fire(sf::CircleShape array[]);
    void reload(node<sf::CircleShape>* &head, sf::CircleShape bullet,
                 sf::Vector2f velocity);
    // void push(sf::CircleShape array[], sf::CircleShape bullet);
    // //--------------------------


    void pick_Up_Gun(node<sf::CircleShape>* &head);
    // void pop(sf::CircleShape array[]);
    // void top();
    // int size(sf::CircleShape array[]);
    // int mag_Size(sf::CircleShape array[]);
    // int check_Mag(sf::CircleShape array[]);
    // int bullet_Count(sf::CircleShape array[]);
	//void reSize(sf::CircleShape array[], sf::CircleShape ammo);


    //nodes
    // void push(node<sf::CircleShape>* &head, sf::CircleShape bullet,
    //         sf::Vector2f velocity);
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