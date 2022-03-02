#include "Automata.h"


Automata::Automata()
{
	test = "CELLULAR AUTOMATA";
	cols = 60;
	rows = 60;
	std::cout << test << std::endl;	
	std::cout << "Press A to initialize first generation of Cells" << std::endl;	
}

Automata::~Automata()
{
	
}

void Automata::drawCells(sf::RenderWindow& window)
{
	for (unsigned int r = 0; r < state.size(); r++) 
	{
		for (unsigned int c = 0; c < state[r].size(); c++) 
		{
			if (state[r][c] == 1)
			{
				liveCell.setSize(sf::Vector2f(10 - 1, 10 - 1));
				liveCell.setFillColor(sf::Color::Green);
				liveCell.setPosition(r * 10, c * 10);
				liveCell.setOutlineColor(sf::Color::Black);
				liveCell.setOutlineThickness(1);
				window.draw(liveCell);
			}
			else if (state[r][c] == 0)
			{
				deadCell.setSize(sf::Vector2f(10 - 1, 10 - 1));
				deadCell.setFillColor(sf::Color::Black);
				deadCell.setPosition(r * 10, c * 10);
				deadCell.setOutlineColor(sf::Color::Black);
				deadCell.setOutlineThickness(1);
				window.draw(deadCell);
			}
			
		}		
	}
}

void Automata::initialize(unsigned int rows, unsigned int cols, sf::RenderWindow& window)
{	
	std::cout << "Initialization in progress... " << std::endl;


	state.resize(rows);
	for (int r = 0; r < rows; r++)
	{
		state[r].resize(cols);
	}

	nextState.resize(rows);
	for (int r = 0; r < rows; r++)
	{
		nextState[r].resize(cols);
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{			
			const int randomBit = rand() % 2;
			if (randomBit == 1)
			{
				state[i][j] = CellState::ALIVE;								
				std::cout << state[i][j] << std::endl;
			}
			else
			{
				state[i][j] = CellState::DEAD;				
				std::cout << state[i][j] << std::endl;				
			}						
		}
	}
	std::cout << "Press I for each iteration forward... " << std::endl;
}

void Automata::iterate()
{
	int iterations = 1;

	for (int i = 0; i < iterations; i++)
	{
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				int count = countNeighbors(state, r, c);

				if (state[r][c] == 1)
				{
					if (count < 2 || count > 3)
					{
						nextState[r][c] = CellState::DEAD;
					}
					else if(count == 3)
					{
						nextState[r][c] = CellState::ALIVE;
					}					
				}
				if (state[r][c] == 0)
				{
					if (count < 2 || count > 3)
					{
						nextState[r][c] = CellState::DEAD;
					}
					else if (count == 3)
					{
						nextState[r][c] = CellState::ALIVE;
					}
				}				
			}			
		}

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				state[r][c] = nextState[r][c];				
			}
			
		}
	}	
}

int Automata::countNeighbors(std::vector<std::vector<CellState>>& state, int r, int c)
{
	int count = 0;
	bool top = r <= 0;
	bool bottom = r >= (rows - 1); //rows in state[][]
	bool left = c <= 0;
	bool right = c >= (cols - 1); // cols in state[][]	

	if (!left && state[r][c - 1] == CellState::ALIVE)
	{
		++count;
	}

	if (!right && state[r][c + 1] == CellState::ALIVE)
	{
		++count;
	}

	if (!top)
	{
		if (state[r - 1][c] == CellState::ALIVE)
			++count;
		if (!left && state[r - 1][c - 1] == CellState::ALIVE)
			++count;
		if (!right && state[r - 1][c + 1] == CellState::ALIVE)
			++count;
	}

	if (!bottom)
	{
		if (state[r + 1][c] == 1)
			++count;
		if (!left && state[r + 1][c - 1] == CellState::ALIVE)
			++count;
		if (!right && state[r + 1][c + 1] == CellState::ALIVE)
			++count;
	}

	return count;
}

//! NOT YET IMPLEMENTED
int Automata::wrapValue(int v, int vMax)
{
	// To generalize this, use modulo
	if (v == -1) return vMax - 1;
	if (v == vMax) return 0;
	return v;
}

