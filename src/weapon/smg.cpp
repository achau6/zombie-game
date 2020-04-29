#include "smg.h"

smg::smg()
{
	smgs = nullptr;
	currentIndex = 0;
}

void smg::push(sf::CircleShape bullet,
                    sf::Vector2f velocity)
{
    node<sf::CircleShape>* temp = new node<sf::CircleShape>;
    temp->key = 2;
    temp->shape = bullet;
    temp->prev = nullptr;
    temp->next = nullptr;
    temp->currentVelocity = velocity;
    if (smgs == nullptr){
        smgs = temp;
    } else {
        temp->next = smgs;
        smgs->prev = temp;
        smgs = temp;
    }
}

void smg::remove()
{
    node<sf::CircleShape>* temp = smgs;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        smgs = temp;
    }
}

bool smg::is_item(){
    int count = 0;
    node<sf::CircleShape>* temp = smgs;
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

void smg::start() {
    currentIndex = 0;
}

void smg::advance(){
    currentIndex ++;
}

void smg::current()
{
    int count = 0;
    node<sf::CircleShape>* temp = smgs;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape.move(temp->currentVelocity);
        }
        count += 1;
        temp = temp->next;
    }

}

void smg::currentDraw(sf::RenderWindow& window)
{
    node<sf::CircleShape>* temp = smgs;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape);
        }
        count += 1;
        temp = temp->next;
    }
}

void smg::erase()
{
    node<sf::CircleShape>* temp = smgs;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp->shape.getPosition().x < 5 || temp->shape.getPosition().x > 20
            ||temp->shape.getPosition().y < 5 || temp->shape.getPosition().y > 20)
            {
                std::cout<<"erase"<<std::endl;
                remove();
            }
        }
        count += 1;
        temp = temp->next;
    }
}

void smg::reload(sf::CircleShape bullet, sf::Vector2f velocity)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity);
	}
}