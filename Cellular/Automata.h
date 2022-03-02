#pragma once
//https://stackoverflow.com/questions/41054730/cellular-automaton-in-c
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <Windows.h>



enum CellState {
	DEAD, ALIVE
};



class Automata
{
public:	
	Automata();
	~Automata();
	
	void initialize(const unsigned int rows, const unsigned int cols, sf::RenderWindow& window);	
	void iterate();
	int countNeighbors(std::vector<std::vector<CellState>>& state, int r, int c);	

	void drawCells(sf::RenderWindow& window);	

	//! YET TO BE IMPLEMENTED
	int wrapValue(int v, int vMax);

	int cols;
	int rows;
private:
	sf::RectangleShape liveCell;
	sf::RectangleShape deadCell;

	std::string test;	
	
	int count;

	bool top;
	bool bottom;
	bool right;
	bool left;		
	std::vector<std::vector<CellState>> nextState;
	std::vector<std::vector<CellState>> state;	
};

