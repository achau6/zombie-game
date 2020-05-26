//
// Created by Dave R. Smith on 10/27/19.
//

#include "GameText.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void GameText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*text, states);
}
GameText::GameText(std::string text, unsigned int charSize, sf::Vector2f position)
{
    this->text = new sf::Text;
    font = new sf::Font;
    font->loadFromFile("Game/OpenSans-Bold.ttf");
    this->text->setString(text);
    this->text->setFont(*font);
    this->text->setCharacterSize(charSize);
    this->text->setPosition(position.x - this->text->getGlobalBounds().width/2,
                            position.y - this->text->getGlobalBounds().height/2);
    this->text->setOutlineColor(sf::Color::Yellow);
}
//GameText::GameText(const GameText& gameText)
//{
//    std::cout <<"gtextpos("<<gameText.text.getPosition().x<<", "<<gameText.text.getPosition().y<<std::endl;
//    text = gameText.text;
//    font = gameText.font;
//    text.setPosition(gameText.text.getPosition());
//}
void GameText::setPosition(float x, float y)
{
    std::cout <<"pos("<<x<<", "<<y<<std::endl;
    text->setPosition(x, y);
    //std::cout <<"textpos("<<text->getPosition().x<<", "<<textgetPosition().y<<std::endl;
}
sf::Text* GameText::getText()
{
    return text;
}
GameText::GameText(){}