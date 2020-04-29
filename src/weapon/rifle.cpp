#include "rifle.h"

rifle::rifle()
{
	rifles = nullptr;
	currentIndex = 0;
}

void rifle::push(sf::CircleShape bullet,
                    sf::Vector2f velocity)
{
    node<sf::CircleShape>* temp = new node<sf::CircleShape>;
    temp->key = 3;
    temp->shape = bullet;
    temp->prev = nullptr;
    temp->next = nullptr;
    temp->currentVelocity = velocity;
    if (rifles == nullptr){
        rifles = temp;
    } else {
        temp->next = rifles;
        rifles->prev = temp;
        rifles = temp;
    }
}

void rifle::remove()
{
    node<sf::CircleShape>* temp = rifles;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        rifles = temp;
    }
}

bool rifle::is_item(){
    int count = 0;
    node<sf::CircleShape>* temp = rifles;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp == nullptr) {
                return false;
            } else {
                return true;
            }
        }
        count ++;
        temp = temp->next;
    }
    return false;
}

void rifle::start() {
    currentIndex = 0;
}

void rifle::advance(){
    currentIndex ++;
}

void rifle::current()
{
    int count = 0;
    node<sf::CircleShape>* temp = rifles;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape.move(temp->currentVelocity);
        }
        count += 1;
        temp = temp->next;
    }

}

void rifle::currentDraw(sf::RenderWindow& window)
{
    node<sf::CircleShape>* temp = rifles;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape);
        }
        count += 1;
        temp = temp->next;
    }
}

void rifle::reload(sf::CircleShape bullet, sf::Vector2f velocity)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity);
	}
}