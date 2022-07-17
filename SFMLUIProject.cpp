// SFMLUIProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is a small project to help me with UI programming using SFML. 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "UI Practice Project");

	Menu thisMainMenu(window.getSize().x, window.getSize().y);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					thisMainMenu.scrollUp();
					break;
				case sf::Keyboard::Down:
					thisMainMenu.scrollDown();
					break;



				case::sf::Keyboard::Return:
					switch (thisMainMenu.PressedItem())
					{
						// allows the player access to play mode.
					case 0:
						std::cout << "Play selected, starting program" << std::endl;
						break;
						// allows the player access to the options.
					case 1:
						std::cout << "Options selected" << std::endl;
						break;
						// ends the program from the main menu.
					case 2:
						std::cout << "Exit program" << std::endl;
						window.close();
					}
			

					break;
				}
				break;

			case sf::Event::Closed:
				window.close();

				break;


			}
		}

		window.clear();

		thisMainMenu.drawMenu(window);

		window.display();

	}

	
}