#include "button.h"
#include <iomanip>

Button::Button(sf::Vector2f size, sf::Color btn_color, string txt, unsigned int font_size, sf::Color txt_color)
{
    button.setSize(size);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);
    button.setFillColor(btn_color);

    btn_width = button.getSize().x;
    btn_height = button.getSize().y;

    text.setString(txt);
    text.setCharacterSize(font_size);
    text.setFillColor(txt_color);
}

bool Button::is_over(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float button_x = button.getPosition().x;
    float button_y = button.getPosition().y;

    float x_pos_width = button.getPosition().x + btn_width;
    float y_pos_height = button.getPosition().y + btn_height;

    if ((mouseX < x_pos_width) && (mouseX > button_x) && (mouseY < y_pos_height) && (mouseY > button_y))
    {
        text.setFillColor(sf::Color::White);
        return true;
    }
    else
    {
        text.setFillColor(_text_color);
        return false;
    }
}

void Button::set_pos(sf::Vector2f point)
{
    button.setPosition(point);

    // button text alignment
    float xPos = (point.x + btn_width/2) - (text.getLocalBounds().width);
    float yPos = (point.y + btn_height/1.3) - (text.getLocalBounds().height);
//    text.setOrigin(btn_width/2, btn_height/2);
    text.setOrigin(btn_width/2.2, btn_height * 1.1);
//    text.setPosition(xPos, yPos);
    text.setPosition(xPos + 10, yPos);
}

void Button::draw(sf::RenderWindow &window)
{
    //window.draw(button);
    window.draw(text);
}
void Button::set_size(sf::Vector2f size){
    button.setSize(sf::Vector2f(size.x, size.y));
    btn_height = size.y;
    btn_width = size.x;
}

void Button::set_text_color(sf::Color color){
    text.setFillColor(color);
    _text_color = color;
}