#include <vector>
#include <iostream>
#include "Platform/Platform.hpp"

class Tile {
		public:
			Tile() = default;
			Tile(sf::Vector2f pos) {
				// if(!texture.loadFromFile("dirt.png")) {
				// 	std::cout << "failed to load" << std::endl;
				// }
				// shape.setTexture(&texture);
				// temp fix until i can get the texture to load in properlys

				// TODO: figure out how to have size of grid and size of the actual shape(in pixels)
				shape.setSize({50,50});
				shape.setFillColor(sf::Color(139,69,19));
				shape.setPosition(pos);
				shape.setOutlineThickness(1);
				shape.setOutlineColor(sf::Color::Green);
			}

			void Render(sf::RenderWindow* window) {
				window->draw(shape); // seg fault
			}

		private:
			sf::RectangleShape shape;
			sf::Texture texture;
	};