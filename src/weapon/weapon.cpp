#include "weapon.h"
#include <iostream>
#include <assert.h>
weapons::weapons()
{
    smgs = nullptr;
    shotguns = nullptr;
    pistols = nullptr;
    rifles = nullptr;
    currentIndex = 0;
    shotgunsHead = nullptr;
    shotgunsTail = nullptr;


}


void weapons::printCheck(node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    while(temp != nullptr){
        std::cout<<temp->key<<", ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
void weapons::remove(node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        head = temp;
    }
}

bool weapons::is_item(node<sf::CircleShape>* &head){
    int count = 0;
    node<sf::CircleShape>* temp = head;
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
void weapons::start() {
    currentIndex = 0;
}

void weapons::advance(){
    currentIndex ++;
}
void weapons::current(node<sf::CircleShape>* &head)
{
    int count = 0;
    node<sf::CircleShape>* temp = head;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape.move(temp->currentVelocity);
            break;
        }
        count += 1;
        temp = temp->next;
    }

}

void weapons::currentDraw(sf::RenderWindow& window,
                         node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape);
            break;
        }
        count += 1;
        temp = temp->next;
    }
}
