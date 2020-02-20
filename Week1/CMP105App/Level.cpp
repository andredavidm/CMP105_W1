#include "Level.h"
int x = 0;
int y = 0;
int other = 0;
Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	
	

	// initialise game objects
	//restangle
	rect.setPosition(1200/2, 675/2);
	rect.setSize(sf::Vector2f(60, 60));
	rect.setFillColor(sf::Color::Red);
	
	rect1.setPosition(1200 / 2+10, 675 / 2+10);
	rect1.setSize(sf::Vector2f(40, 40));
	rect1.setFillColor(sf::Color::Green);
	
	rect2.setPosition(1200 / 2+20, 675 / 2+20);
	rect2.setSize(sf::Vector2f(20, 20));
	rect2.setFillColor(sf::Color::Blue);

	font.loadFromFile("font/arial.ttf");
	//text
	text.setFont(font);
	text.setCharacterSize(70);
	text.setFillColor(sf::Color::Red);
	text.setString("Hello world");
	text.setPosition(1200/2, 100);



	/*//circle
	circle.setRadius(50);
	circle.setPosition(1200/2, 675/2);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Blue);*/
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	if (other == 0)
	{

		rect.setPosition(x, y);

		x = x + 1;
	
	}
	
	if (x >= 1200)
	{
		y = y + 60;
		other = 1;
		
		
	}

	if (other == 1) {

		x = x - 1;
		rect.setPosition(x, y);

		if (x <= 0)
		{
			other = 0;
		}
	}
	
	
	sf::Vector2u pos = window->getSize();
	
	rect.setPosition(pos.x-60,pos.y-60);

	//sf::Level::rect.setPosition(pos);
	
}

// Render level
void Level::render()
{
	

	

	beginDraw();
	
	window->draw(rect);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(text);
	endDraw();
}

void Level::beginDraw()
{
	//window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}