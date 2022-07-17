#pragma once
#include <SFML/Graphics.hpp>

#define MAx_ITEMS 3
class Menu
{
private:
	int highlightedItem;
	sf::Font font;
	sf::Text mainMenu[MAx_ITEMS];
public:
	Menu(float width, float height);
	~Menu();

	void drawMenu(sf::RenderWindow& window);
	void scrollUp();
	void scrollDown();
	int PressedItem() { return highlightedItem; }
};

