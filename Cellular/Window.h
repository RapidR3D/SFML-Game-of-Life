#pragma once

#include <SFML\Graphics.hpp>

#include "Cell.h"
#include "Automata.h"

class Window
{
	sf::RenderWindow window;
	sf::Event event;

	float _dt;
	int _width;
	int _height;

	bool activateGrid;
	bool initAuto;

public:	
	Window(int width, int height);
	~Window();	

	Cell cell;		
	Automata  aut;
	CellState state;

	void run();
	void draw(sf::RenderWindow& window);
	void update(float dt);
	void processInput(sf::Event& event);
};

