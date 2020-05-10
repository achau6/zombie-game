#include "shotgun.h"

Shotgun::Shotgun()
{
	shotguns = nullptr;
	currentIndex = 0;
}

void Shotgun::push(sf::CircleShape bullet,
                    sf::Vector2f velocity, sf::Vector2f position)
{
    Nodes<sf::CircleShape>* temp = new Nodes<sf::CircleShape>;
    temp->key = 4;
    temp->shape1 = bullet;
    temp->shape2 = bullet;
    temp->shape3 = bullet;

    temp->prev = nullptr;
    temp->next = nullptr;

    temp->shape1.setPosition(position);
    temp->shape2.setPosition(position);
    temp->shape3.setPosition(position);

    temp->currentVelocity1 = velocity;
    temp->currentVelocity2 = sf::Vector2f(velocity.x - 1.00, velocity.y+1.00);
    temp->currentVelocity3 = sf::Vector2f(velocity.x + 1.00, velocity.y-1.00);

    if (shotguns == nullptr){
        shotguns = temp;
    } else {
        temp->next = shotguns;
        shotguns->prev = temp;
        shotguns = temp;
    }
}

void Shotgun::remove()
{
    Nodes<sf::CircleShape>* temp = shotguns;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        shotguns = temp;
    }
}

bool Shotgun::is_item(){
    int count = 0;
    Nodes<sf::CircleShape>* temp = shotguns;
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

void Shotgun::start() {
    currentIndex = 0;
}

void Shotgun::advance(){
    currentIndex ++;
}

void Shotgun::current()
{
    int count = 0;
    Nodes<sf::CircleShape>* temp = shotguns;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape1.move(temp->currentVelocity1);
			temp->shape2.move(temp->currentVelocity2);
			temp->shape3.move(temp->currentVelocity3);
        }
        count += 1;
        temp = temp->next;
    }

}

int Shotgun::size()
{
    int count = 0;
    Nodes<sf::CircleShape>* temp = shotguns;
    while(temp != nullptr){
        count += 1;
        temp = temp->next;
    }
    return count;
}

void Shotgun::currentDraw(sf::RenderWindow& window)
{
    Nodes<sf::CircleShape>* temp = shotguns;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape1);
			window.draw(temp->shape2);
			window.draw(temp->shape3);
        }
        count += 1;
        temp = temp->next;
    }
}

void Shotgun::erase(float X, float Y)
{
    Nodes<sf::CircleShape>* temp = shotguns;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
			//A REALLY LONG CHECK OF CONDITIONS
            if(temp->shape1.getPosition().x < (X - 100) || temp->shape1.getPosition().x > (X + 100)
            ||temp->shape1.getPosition().y < (Y - 100) || temp->shape1.getPosition().y > (X + 100)
            ||temp->shape1.getPosition().x < 0 || temp->shape1.getPosition().y < 0
            ||temp->shape1.getPosition().y > 2480 || temp->shape1.getPosition().x > 2480
			||temp->shape2.getPosition().x < (X - 100) || temp->shape2.getPosition().x > (X + 100)
            ||temp->shape2.getPosition().y < (Y - 100) || temp->shape2.getPosition().y > (X + 100)
            ||temp->shape2.getPosition().x < 0 || temp->shape2.getPosition().y < 0
            ||temp->shape2.getPosition().y > 2480 || temp->shape2.getPosition().x > 2480
			||temp->shape3.getPosition().x < (X - 100) || temp->shape3.getPosition().x > (X + 100)
            ||temp->shape3.getPosition().y < (Y - 100) || temp->shape3.getPosition().y > (X + 100)
            ||temp->shape3.getPosition().x < 0 || temp->shape3.getPosition().y < 0
            ||temp->shape3.getPosition().y > 2480 || temp->shape3.getPosition().x > 2480)
            {
                std::cout<<"erase"<<std::endl;
                remove();
            }
        }
        count += 1;
        temp = temp->next;
    }
}

void Shotgun::reload(sf::CircleShape bullet, sf::Vector2f velocity, sf::Vector2f position)
{
	for(int i = 0; i < 15; i ++)
	{
		push(bullet, velocity, position);
	}
}