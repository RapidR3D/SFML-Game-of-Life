#include "Window.h"

Window::Window(int width, int height) : event(),
	window(sf::VideoMode(width, height), "Cellular Autonomous")
{
	_dt = 1.0f / 60.0f;

	window.setFramerateLimit(60);

	activateGrid = true;
	initAuto = false;

	run();
}

Window::~Window()
{

}

void Window::run()
{
	while(window.isOpen())
	{
		processInput(event);
		update(_dt);
		draw(window);
	}
}

void Window::draw(sf::RenderWindow& window)
{	 
	window.clear();

	if(activateGrid)
	{
		cell.DrawGrid(window);		
	}
	
	if (initAuto)
	{
		aut.drawCells(window);
	}

	window.display();
}

void Window::update(float dt)
{
	if (initAuto)
	{
		//aut.updateAutomata();
	}
}

void Window::processInput(sf::Event& event)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{			
			activateGrid = true;			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			activateGrid = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			aut.initialize(aut.rows, aut.cols, window);			
			initAuto = true;			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			aut.iterate();
			initAuto = true;
		}		
	}
}