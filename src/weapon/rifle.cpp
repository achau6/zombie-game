#include "rifle.h"

rifle::rifle()
{
	rifles = nullptr;
	currentIndex = 0;
}

void rifle::push(sf::CircleShape bullet,
                    sf::Vector2f velocity, sf::Vector2f position)
{
    node<sf::CircleShape>* temp = new node<sf::CircleShape>;
    temp->key = 3;
    temp->shape = bullet;
    temp->prev = nullptr;
    temp->next = nullptr;
    temp->shape.setPosition(position);
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
int rifle::size()
{
    int count = 0;
    node<sf::CircleShape>* temp = rifles;
    while(temp != nullptr){
        count += 1;
        temp = temp->next;
    }
    return count;
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

void rifle::erase(float X, float Y)
{
    node<sf::CircleShape>* temp = rifles;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp->shape.getPosition().x < (X - 500) || temp->shape.getPosition().x > (X + 500)
            ||temp->shape.getPosition().y < (Y - 500) || temp->shape.getPosition().y > (X + 500)
            ||temp->shape.getPosition().x < 0 || temp->shape.getPosition().y < 0
            ||temp->shape.getPosition().y > 2480 || temp->shape.getPosition().x > 2480)
            {
                std::cout<<"erase"<<std::endl;
                remove();
            }
        }
        count += 1;
        temp = temp->next;
    }
}


void rifle::reload(sf::CircleShape bullet, sf::Vector2f velocity, sf::Vector2f position)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity, position);
	}
}