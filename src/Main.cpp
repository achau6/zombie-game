// #include "Platform/Platform.hpp"
#include "game.h"

int main()
{
// 	util::Platform platform;
// 	std::vector<int> vector2;

// #if defined(_DEBUG)
// 	std::cout << "Hello World!" << std::endl;
// #endif

// 	sf::RenderWindow window;
// 	// in Windows at least, this must be called before creating the window
// 	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
// 	// Use the screenScalingFactor
// 	window.create(sf::VideoMode(1000.0 * screenScalingFactor, 500.0 * screenScalingFactor), "SFML");
// 	platform.setIcon(window.getSystemHandle());

// 	sf::RectangleShape rectangle(sf::Vector2f(200, 200));
// 	//shape.setFillColor(sf::Color::White);

// 	sf::Texture shapeTexture;
// 	shapeTexture.loadFromFile("C:/Users/SICK/Documents/CS/test/content/http___pluspng.com_img-png_gun-png-handgun-png-image-png-image-1024.png");
// 	rectangle.setTexture(&shapeTexture);

// 	sf::Event event;

// 	while (window.isOpen())
// 	{
// 		while (window.pollEvent(event))
// 		{
// 			switch( event.type )
// 			{
// 				case sf::Event::Closed:
// 					window.close();
// 					break;
// 				case sf::Event::MouseButtonPressed:
// 					std::cout<<"Mouse Button Pressed"<<std::endl;
// 					break;
// 				default:
// 					break;
// 			}
// 		}

// 		window.clear();
// 		window.draw(rectangle);
// 		window.display();
// 	}

	Game game;
	
	game.Run();

	return 0;
}
