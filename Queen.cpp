/* Name: Mateusz Serafin
** Number: 160272859
** Queen implementation
*/
#include "stdafx.h"
#include "Queen.h"

// constructor
Queen::Queen(double x, double y) :
	Piece(x, y), Bishop(x, y), Rook(x, y) {}

// destructor
Queen::~Queen(){}

// initialising score
int Queen::score = 0;

// move method - use of Rook and Bishop methods
bool Queen::move(double dx, double dy)
{
	if (Bishop::move(dx, dy))
		return true;

	else if (Rook::move(dx, dy))
		return true;

	else return false;
}

// random move method - use of Rook and Bishop methods
void Queen::moveRandom(double boardWidth, double boardHeight)
{
	// random choice how it should go 
	if (randomDouble(0, 2) < 1.0)
		Bishop::moveRandom(boardWidth, boardHeight);
	else
		Rook::moveRandom(boardWidth, boardHeight);
}
// adding points
void Queen::scoredPoint()
{
	score++;
}

// no point of displaying any other data, every Queen has the same radius
ostream & operator<<(ostream &out, const Queen &b)
{
	out << "Queen(x = " << b.getX() << ", y = " << b.getY() << ")";
	return out;
}
void Queen::print()
{
	cout << *this;
}