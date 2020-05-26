//
// Created by Dave R. Smith on 10/25/19.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//std::map<std::string, const Game&> Game::LOAD_GAME;

sf::RectangleShape* Game::getSfThumbnail() {

    return thumbnail.getThumbnail();
}

void Game::setThumbnail() {
    //thumbnail.initialize(image_path);
}

string Game::getTitle(){
    return title;
}

void Game::init(){
    //setThumbnail();
}
Game::Game(){

}

void Game::load_game()
{
    //std::cout << "game image path is " << image_path;
    //Console::load_game(title, this);
}

//std::map<std::string, const Game&> Game::getMap()
//{
//    return Game::LOAD_GAME;
//}

//sf::RenderWindow Game::getWindow()
//{
//    return window;
//}
std::string Game::getImagePath(){
    return image_path;
}
Thumbnail Game::getThumbnail(){
    Thumbnail* t = new Thumbnail(image_path, title, sf::Rect<float>(10,10, 300, 300), sf::Vector2u(500,500));
    t->getThumbnail()->setPosition(500, 500);
    return *t;
}
GameText Game::getInfo(sf::RenderWindow &window)
{
    std::ifstream filereader;
    filereader.open(info_path);
    string s = "";
    string next;
    while(std::getline(filereader, next))
        s += next+'\n';
    sf::Vector2u winSize= window.getSize();
    GameText info(s,24, sf::Vector2f(20, 20));
    sf::Rect<float> size = info.getText()->getGlobalBounds();
    info.getText()->setPosition(winSize.x/2 - size.width/2, winSize.y/2 - size.height/2 );
    return info;

}
void Game::exit()
{

}