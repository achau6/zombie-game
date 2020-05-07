#include "pistol.h"

pistol::pistol()
{
	pistols = nullptr;
	currentIndex = 0;
}

void pistol::push(sf::CircleShape bullet,
                    sf::Vector2f velocity, sf::Vector2f position)
{
    node<sf::CircleShape>* temp = new node<sf::CircleShape>;
    temp->key = 1;
    temp->shape = bullet;
    temp->prev = nullptr;
    temp->next = nullptr;
    temp->shape.setPosition(position);
    temp->currentVelocity = velocity;
    if (pistols == nullptr){
        pistols = temp;
    } else {
        temp->next = pistols;
        pistols->prev = temp;
        pistols = temp;
    }
}

void pistol::remove()
{
    node<sf::CircleShape>* temp = pistols;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        pistols = temp;
    }
}

bool pistol::is_item(){
    int count = 0;
    node<sf::CircleShape>* temp = pistols;
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

void pistol::start() {
    currentIndex = 0;
}

void pistol::advance(){
    currentIndex ++;
}

void pistol::current()
{
    int count = 0;
    node<sf::CircleShape>* temp = pistols;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape.move(temp->currentVelocity);
        }
        count += 1;
        temp = temp->next;
    }

}

int pistol::size()
{
    int count = 0;
    node<sf::CircleShape>* temp = pistols;
    while(temp != nullptr){
        count += 1;
        temp = temp->next;
    }
    return count;
}

void pistol::currentDraw(sf::RenderWindow& window)
{
    node<sf::CircleShape>* temp = pistols;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape);
        }
        count += 1;
        temp = temp->next;
    }
}

void pistol::erase(sf::RenderWindow& window)
{
    node<sf::CircleShape>* temp = pistols;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp->shape.getPosition().x < -1100 || temp->shape.getPosition().x > window.getSize().x
            ||temp->shape.getPosition().y < -1640 || temp->shape.getPosition().y > window.getSize().y)
            {
                std::cout<<"erase"<<std::endl;
                remove();
            }
        }
        count += 1;
        temp = temp->next;
    }
}

void pistol::reload(sf::CircleShape bullet, sf::Vector2f velocity, sf::Vector2f position)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity, position);
	}
}