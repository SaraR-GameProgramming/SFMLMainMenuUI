#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Yaahowu.ttf"))
	{
		// error
	}

	// selectable menu elements
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Green);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(30);
	mainMenu[0].setPosition(sf::Vector2f(width / 2, height / (MAx_ITEMS + 1) * 1));

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::Red);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(30);
	mainMenu[1].setPosition(sf::Vector2f(width / 2, height / (MAx_ITEMS + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::Red);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(30);
	mainMenu[2].setPosition(sf::Vector2f(width / 2, height / (MAx_ITEMS + 1) * 3));

	highlightedItem = 0;
}

// deconstructor
Menu::~Menu()
{
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < MAx_ITEMS; i++)
	{
		window.draw(mainMenu[i]);
	}
}


// set char size is used in the scroll up and down to make the highlighted text larger for player convenience.
void Menu::scrollUp()
{
	if (highlightedItem - 1 >= 0)
	{
		mainMenu[highlightedItem].setFillColor(sf::Color::Green);
		mainMenu[highlightedItem].setCharacterSize(30);
		highlightedItem--;
		mainMenu[highlightedItem].setFillColor(sf::Color::Red);
		mainMenu[highlightedItem].setCharacterSize(40);
	}
}

void Menu::scrollDown()
{
	if (highlightedItem + 1 <  MAx_ITEMS)
	{
		mainMenu[highlightedItem].setFillColor(sf::Color::Green);
		mainMenu[highlightedItem].setCharacterSize(30);
		highlightedItem++;
		mainMenu[highlightedItem].setFillColor(sf::Color::Red);
		mainMenu[highlightedItem].setCharacterSize(40);
	}
}


