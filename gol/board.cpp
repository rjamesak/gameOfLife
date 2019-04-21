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
	std::cout << "drawing board\n ";

	for (int i = 0; i < boardCols; i++) {
		std::cout << i;
	}
	std::cout << std::endl;

	for (int i = 0; i < boardRows; i++) {
		std::cout << i;
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

//returns the number of ALIVE cells adjacent to row and column
//passed in as parameters
int Board::getNeighborCount(int row, int col)
{
	int neighbors = 0;
	int rowAbove, rowBelow, nextCol, prevCol;

	//bounds check adjacent row/cols
	if (row - 1 < 0) {
		rowAbove = boardRows - 1;
	}
	else { rowAbove = row - 1; }
	rowBelow = (row + 1) % boardRows;
	nextCol = (col + 1) % boardCols;
	if (col - 1 < 0) {
		prevCol = boardCols - 1;
	}
	else { prevCol = col - 1; }

	if (gameBoard[rowAbove][prevCol]->getState() == State::ALIVE) //nw
		neighbors++;
	if (gameBoard[rowAbove][col]->getState() == State::ALIVE) //n
		neighbors++;
	if (gameBoard[rowAbove][nextCol]->getState() == State::ALIVE) //ne
		neighbors++;
	if (gameBoard[row][prevCol]->getState() == State::ALIVE) //w
		neighbors++;
	if (gameBoard[row][nextCol]->getState() == State::ALIVE) //e
		neighbors++;
	if (gameBoard[rowBelow][prevCol]->getState() == State::ALIVE) //sw
		neighbors++;
	if (gameBoard[rowBelow][col]->getState() == State::ALIVE) //s
		neighbors++;
	if (gameBoard[rowBelow][nextCol]->getState() == State::ALIVE) //se
		neighbors++;

	return neighbors;
}
