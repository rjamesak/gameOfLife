#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include <vector>
#include <iostream>

class Board {
public:
	const char LIVE = '#';
	const char DEAD = ' ';
	enum class Fate{ KILL, CREATE };
	Board(int totalRows, int totalCols);
	~Board();
	void drawBoard();
	void seedCells(int totalCells);
	bool genCell(int row, int col);
	bool killCell(int row, int col);
	//init(int totalRows, int totalCols, int liveCells);
	//init(int totalRows, int totalCols);
	//void createCell(int row, int col);
	//void killCell(int row, int col);
	int getNeighborCount(int row, int col);
	//Fate determineFateOfCell(int numNeighbors);

protected:
private:
	int boardRows = 0;
	int boardCols = 0;
	//std::vector<cell> **world;
	Cell ***gameBoard;

};
#endif //BOARD_HPP