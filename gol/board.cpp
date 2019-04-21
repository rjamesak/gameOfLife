#include "board.hpp"
#include <cstdlib>

Board::Board(int totalRows, int totalCols)
{
	//init 2d array of pointers to cells
	gameBoard = new Cell**[totalRows];
	for (int i = 0; i < totalRows; i++) {
		gameBoard[i] = new Cell*[totalCols];
		for (int j = 0; j < totalCols; j++) {
			gameBoard[i][j] = new Cell(i, j);
		}

	}
	boardRows = totalRows;
	boardCols = totalCols;
}

//deallocate memory
Board::~Board()
{
	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			delete gameBoard[i][j];
		}
		delete [] gameBoard[i];
	}
	delete [] gameBoard;
}

void Board::drawBoard()
{
	std::cout << "drawing board\n";

	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			std::cout << static_cast<char>(gameBoard[i][j]->getState());
		}
		std::cout << std::endl;
	}
}

void Board::seedCells(int totalCells)
{
	int added = 0;
	int row, col;
	row = col = 0;
	while (added < totalCells) {
		row = rand() % boardRows;
		col = rand() % boardCols;
		if (genCell(row, col)) {
			added++;
		}
	}
}

bool Board::genCell(int row, int col)
{
	if (gameBoard[row][col]->getState() == State::DEAD) {
		gameBoard[row][col]->makeAlive();
		return true;
	}
	return false;
}

bool Board::killCell(int row, int col)
{
	if (gameBoard[row][col]->getState() == State::ALIVE) {
		gameBoard[row][col]->makeDead();
		return true;
	}
	return false;
}
