#ifndef CELL_HPP
#define CELL_HPP

//fill character for live cell
enum class State {ALIVE = '#', DEAD = ' '};

class Cell {
public:
	Cell(int row, int col);
	State getState();
	void makeAlive();
	void makeDead();
	void setNextStatus(State next);
	State getStatus();
	void makeNext();
protected:
private:
	int cellRow;
	int cellCol;
	State status;
	State nextStatus;
};
#endif // !CELL_HPP
