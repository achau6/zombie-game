#include "ZombieGame/ZombieGame.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    bool GAME_STARTED = true;

    sf::RenderWindow window(sf::VideoMode(1920,1080,32),"InfestationZ");
    window.setFramerateLimit(144);
    sf::Image icon;
    icon.loadFromFile("../zombie-game/content/game_thumbnail.png"); // File/Image/Pixel
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    ZombieGame game(&window);

    game.start(window);

    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();

            }
            game.addEvents(window, event);
        }

        game.Update();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            GAME_STARTED = false;
            game.exit();
        }

        window.clear(sf::Color::Black);
        if(GAME_STARTED) {
            game.addEvents(window);
            window.draw(game);
            // window.draw(game.getThumbnail());
            // window.draw(game.getInfo(window));
        }
        window.display();
    }
    return 0;
}
