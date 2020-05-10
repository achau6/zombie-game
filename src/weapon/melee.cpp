#include "melee.h"

Melee::Melee()
{
	melees = nullptr;
	currentIndex = 0;
}

void Melee::push(sf::CircleShape bullet,
                    sf::Vector2f velocity, sf::Vector2f position)
{
    Node<sf::CircleShape>* temp = new Node<sf::CircleShape>;
    temp->key = 0;
    temp->shape1 = bullet;
    temp->shape2 = bullet;
    temp->shape3 = bullet;
    temp->shape4 = bullet;
    temp->shape5 = bullet;

    temp->prev = nullptr;
    temp->next = nullptr;
    temp->shape1.setPosition(position);
	temp->shape2.setPosition(position);
    temp->shape3.setPosition(position);
    temp->shape4.setPosition(position);
    temp->shape5.setPosition(position);

    temp->currentVelocity1 = velocity;
	temp->currentVelocity2 = sf::Vector2f(velocity.x+1.00, velocity.y -1.00);
    temp->currentVelocity3 = sf::Vector2f(velocity.x-1.00, velocity.y+1.00);
	//temp->currentVelocity4 = sf::Vector2f(velocity.x+2.00, velocity.y-2.00);
    //temp->currentVelocity5 = sf::Vector2f(velocity.x-2.00, velocity.y+2.00);

    if (melees == nullptr){
        melees = temp;
    } else {
        temp->next = melees;
        melees->prev = temp;
        melees = temp;
    }
}

void Melee::remove()
{
    Node<sf::CircleShape>* temp = melees;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        melees = temp;
    }
}

bool Melee::is_item(){
    int count = 0;
    Node<sf::CircleShape>* temp = melees;
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

void Melee::start() {
    currentIndex = 0;
}

void Melee::advance(){
    currentIndex ++;
}

void Melee::current()
{
    int count = 0;
    Node<sf::CircleShape>* temp = melees;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape1.move(temp->currentVelocity1);
			temp->shape2.move(temp->currentVelocity2);
			temp->shape3.move(temp->currentVelocity3);
			//temp->shape4.move(temp->currentVelocity4);
			//temp->shape5.move(temp->currentVelocity5);
        }
        count += 1;
        temp = temp->next;
    }

}

int Melee::size()
{
    int count = 0;
    Node<sf::CircleShape>* temp = melees;
    while(temp != nullptr){
        count += 1;
        temp = temp->next;
    }
    return count;
}
void Melee::currentDraw(sf::RenderWindow& window)
{
    Node<sf::CircleShape>* temp = melees;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape1);
			window.draw(temp->shape2);
			window.draw(temp->shape3);
			//window.draw(temp->shape4);
			//window.draw(temp->shape5);
        }
        count += 1;
        temp = temp->next;
    }
}

void Melee::erase(float X, float Y)
{
    Node<sf::CircleShape>* temp = melees;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp->shape1.getPosition().x < (X - 50) || temp->shape1.getPosition().x > (X + 50)
            ||temp->shape1.getPosition().y < (Y - 50) || temp->shape1.getPosition().y > (Y+50)
            ||temp->shape1.getPosition().x < 0 || temp->shape1.getPosition().y < 0
            ||temp->shape1.getPosition().y > 2480 || temp->shape1.getPosition().x > 2480)
            {

                std::cout<<"erase"<<std::endl;
                remove();
            }
        }
        count += 1;
        temp = temp->next;
    }
}

void Melee::reload(sf::CircleShape bullet, sf::Vector2f velocity, sf::Vector2f position)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity, position);
	}
}