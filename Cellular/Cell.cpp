#include "Cell.h"
#include <iostream>

Cell::Cell()
{
	PopulateGrid();
}

Cell::~Cell()
{

}

//screenWidth 600;
//screenHeight 800
void Cell::PopulateGrid()
{		
	for(int i =	0; i < COLUMNS; i++)
	{		
		for(int j = 0; j < ROWS; j++)
		{
			//grid[i][j] = 0;
			if(i == 0 || i == COLUMNS - 1 || j == 0 || j == ROWS - 1)
			{
				grid[i][j] = 1;
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}
}

void Cell::UpdateMovement()
{
	
}

void Cell::DrawGrid(sf::RenderWindow& window)
{
	for(int i = 0; i <= 600; i += 10) //600
	{		
		for(int j = 0; j <= 600; j += 10)
		{
			if(grid[i / 10][j / 10] == 0) //10
			{
				indCell.setSize(sf::Vector2f(10 - 1, 10 - 1));
				indCell.setFillColor(sf::Color::Green);
				indCell.setPosition(i, j);
				indCell.setOutlineColor(sf::Color::Black);
				indCell.setOutlineThickness(1);
				window.draw(indCell);
			}
			if (grid[i / 10][j / 10] == 1)
			{
				indCell.setSize(sf::Vector2f(10 - 1, 10 - 1));
				indCell.setFillColor(sf::Color::Blue);
				indCell.setPosition(i, j);
				indCell.setOutlineColor(sf::Color::Black);
				indCell.setOutlineThickness(1);
				window.draw(indCell);
			}
		}
		
	}
}


