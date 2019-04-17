#ifndef BOARD_HPP
#define BOARD_HPP

//#include "cell.hpp"
#include <vector>
#include <iostream>

class Board {
public:
	const char LIVE = '#';
	const char DEAD = ' ';
	enum class Fate{ KILL, CREATE };
	Board(int totalRows, int totalCols);
	void drawBoard();
	//init(int totalRows, int totalCols, int liveCells);
	//init(int totalRows, int totalCols);
	//void createCell(int row, int col);
	//void killCell(int row, int col);
	//int getNeighborCount(int row, int col);
	//Fate determineFateOfCell(int numNeighbors);

protected:
private:
	int rows = 0;
	int cols = 0;
	//std::vector<cell> **world;
	std::vector<std::vector<char>> *gameBoard;

};
#endif //BOARD_HPP