// gol.cpp : Defines the entry point for the console application.
//

#include "board.hpp"

int main()
{

	std::cout << "How many rows? ";
	int rowInput = 0;
	std::cin >> rowInput;
	std::cout << "\nHow many columns? ";
	int colInput = 0;
	std::cin >> colInput;
	Board gameBoard(rowInput, colInput);
	std::cout << "How many cells to start? ";
	int startingCells;
	std::cin >> startingCells;
	if (startingCells < rowInput*colInput) {
		gameBoard.seedCells(startingCells);
	}
	else { std::cout << "\ntoo many cells\n"; }
	gameBoard.drawBoard();
	std::cout << "neighbor count, cell 0, 0: " << gameBoard.getNeighborCount(0, 0) << std::endl;
	//checkNeighbors sets next status in cells based on neighbor count
	gameBoard.checkNeighbors();
	//apply next iterates through board and sets current status to next status
	gameBoard.applyNext();
	gameBoard.drawBoard();
	for (int i = 0; i < 500; i++) {
		if (system("CLS")) system("clear");
		gameBoard.checkNeighbors();
		gameBoard.applyNext();
		gameBoard.drawBoard();
	}
    return 0;
}

