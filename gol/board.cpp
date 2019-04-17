#include "board.hpp"

Board::Board(int totalRows, int totalCols)
{
	//make a vector within a vector
	//link https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector
	//std::vector<std::vector<char>> initVec(totalRows, std::vector<char>(totalCols, LIVE));
	//gameBoard = &initVec;//this is going out of scope
	gameBoard = new std::vector<std::vector<char>> (totalRows, std::vector<char>(totalCols, LIVE));
	
	/*test print
	for (auto &row : *gameBoard) {
		for (auto cell : row) {
			std::cout << cell;
		}
		std::cout << "\n";
	}
	*/
}

void Board::drawBoard()
{
	std::cout << "drawing board\n";

	for (auto &row : *gameBoard) {
		for (auto cell : row) {
			std::cout << cell;
		}
		std::cout << "\n";
	}
}