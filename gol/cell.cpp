#include "cell.hpp"

Cell::Cell(int row, int col)
{
	cellRow = row;
	cellCol = col;
	status = State::DEAD;
	nextStatus = State::DEAD;
}

State Cell::getState()
{
	return status;
}

void Cell::makeAlive()
{
	status = State::ALIVE;
}

void Cell::makeDead()
{
	status = State::DEAD;
}
