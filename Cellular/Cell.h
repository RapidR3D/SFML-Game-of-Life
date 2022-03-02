#pragma once

#include <SFML\Graphics.hpp>

class Cell
{
public:
	const static int COLUMNS =  60;
	const static int ROWS =  60;
	sf::RectangleShape indCell;	
	
	int grid[COLUMNS][ROWS]{};

	float sizeX = 10;
	float sizeY = 10;

	Cell();
	~Cell();

	void PopulateGrid();
	void UpdateMovement();
	void DrawGrid(sf::RenderWindow& window);
};

