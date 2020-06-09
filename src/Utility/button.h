#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Button
{
public:
    Button() = default;

    Button(sf::Vector2f size, sf::Color btn_color, string txt, unsigned int font_size, sf::Color txt_color);

    bool is_over(sf::RenderWindow& window);

    void set_font(sf::Font &font) {text.setFont(font);}

    void set_background(sf::Color color) {button.setFillColor(color);}

    void set_text_color(sf::Color color);

    void set_origin(sf::Vector2f origin) {button.setOrigin(origin);}

    void set_pos(sf::Vector2f point);

    void set_size(sf::Vector2f size);

    void set_font_size(unsigned int size){text.setCharacterSize(size);}

    void set_str(string str) {text.setString(str);}

    string str() {return text.getString();}

    sf::Vector2f get_size() {return button.getSize();}

    void draw(sf::RenderWindow& window);
private:
    sf::RectangleShape button;
    sf::Text text;

    sf::Color _text_color;
    float btn_width;
    float btn_height;
};