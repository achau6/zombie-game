//
// Created by Dave R. Smith on 10/26/19.
//

#include "Thumbnail.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

float Thumbnail::x = 0;
float Thumbnail::y = 0;
//float Thumbnail::padding = 50.f;
bool Thumbnail::firstThumbnail = true;


void Thumbnail::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(*sprite, states);
}
Thumbnail::Thumbnail()
{

}

Thumbnail::Thumbnail(std::string image_path, std::string title, sf::Rect<float> leftMargin, sf::Vector2u windowSize)
:title(title, 64, sf::Vector2f(windowSize.x/2,
                               windowSize.y*0.85))
{
    setLeftMargin(leftMargin);
    setWindowSize(windowSize);
    this->image_path = image_path;
    initialize();
}
std::string Thumbnail::getImagePath() {
    return image_path;
}
Thumbnail::~Thumbnail()
{
   if(texture != nullptr)
       delete texture;
   if(sprite != nullptr)
       delete sprite;
}
void Thumbnail::initialize()
{
    texture = new sf::Texture;
    sprite = new sf::RectangleShape;
    setThumbnail();
}
void Thumbnail::setPosition()
{
    y = windowSize.y/2 - sprite->getGlobalBounds().height/2;
    if(firstThumbnail == true) {
        x += sprite->getSize().x - 20;
        firstThumbnail = false;
        selected = true;
    }
    else {
        x += sprite->getSize().x + padding;
    }

    sprite->setPosition(x, y);
}
void Thumbnail::setFrame()
{
    sprite->setTextureRect(sf::IntRect(0, 0, 0, 285));
}
void Thumbnail::setThumbnail()
{
    if (texture->loadFromFile(image_path))
    {
        texture->setRepeated(false);
        sprite->setTexture(texture);
        sprite->setOutlineColor(sf::Color::White);
        sprite->setSize(sf::Vector2f(300.f, 300.f));
        sprite->setOutlineThickness(5.f);
        loaded = true;
        setPosition();
        //setFrame();

    }
    else
    {
        loaded = false;
        std::cout<<"image not loaded";
    }

    //assert(isThumbnailLoaded());
}
bool Thumbnail::isThumbnailLoaded()
{
    return loaded;
}

sf::RectangleShape* Thumbnail::getThumbnail(){

    return sprite;
}

void Thumbnail::setWindowSize(sf::Vector2<unsigned int> windowSize)
{
    this->windowSize.x =  windowSize.x;
    this->windowSize.y =  windowSize.y;
}

void Thumbnail::setLeftMargin(sf::Rect<float>& margin)
{
    leftMargin.width = margin.width;
    leftMargin.height = margin.height;
}


GameText Thumbnail::getTitle()
{
    return title;
}
void Thumbnail::setSelected(bool choice)
{
    selected = choice;
}
bool Thumbnail::getSelected()
{
    return selected;
}
void Thumbnail::highlightThumbnail()
{
    sprite->setOutlineThickness(10.f);
    sprite->setOutlineColor(sf::Color::Yellow);
}
void Thumbnail::unhighlightThumbnail()
{
    sprite->setOutlineThickness(5.f);
    sprite->setOutlineColor(sf::Color::White);
}

sf::Texture* Thumbnail::getTexture(){
    return texture;
}