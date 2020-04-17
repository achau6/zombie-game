#include "Platform/Platform.hpp"
#include <vector>
#include "weapon/weapon.h"
#include <iostream>

int main()
{
	util::Platform platform;
	weapons w;
	std::vector<int> vector2;



#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1000.0 * screenScalingFactor, 500.0 * screenScalingFactor), "SFML");
	platform.setIcon(window.getSystemHandle());

	sf::RectangleShape rectangle(sf::Vector2f(200, 200));
	//shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("C:/Users/SICK/Documents/CS/test/content/http___pluspng.com_img-png_gun-png-handgun-png-image-png-image-1024.png");
	rectangle.setTexture(&shapeTexture);

	sf::Event event;
	w.pick_Up_Gun(w.shotgunAmmo);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch( event.type )
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					std::cout<<"Mouse Button Pressed"<<std::endl;
					switch(event.key.code)
					{
						case sf::Mouse::Left:
							std::cout<<"Left Mouse Button Pressed"<<std::endl;
							std::cout<<"ShotGun Ammo: "<<w.size(w.shotgunAmmo)<<std::endl;
							w.fire(w.shotgunAmmo);
							std::cout<<"ShotGun Ammo: "<<w.size(w.shotgunAmmo)<<std::endl;
							std::cout<<std::endl<<std::endl;
							std::cout<<"==================="<<std::endl;

							break;
						case sf::Mouse::Right:
							std::cout<<"Right Mouse Button Pressed"<<std::endl;
							std::cout<<"ShotGun Ammo: "<<w.size(w.shotgunAmmo)<<std::endl;
							w.push(w.shotgunAmmo);
							std::cout<<"ShotGun Ammo: "<<w.size(w.shotgunAmmo)<<std::endl;
							break;
						case sf::Event::MouseWheelMoved:
							window.close();
							break;
						default:
							break;
					}
					break;

				default:
					break;
			}
		}

		window.clear();
		window.draw(rectangle);
		window.display();
	}

	return 0;
}
