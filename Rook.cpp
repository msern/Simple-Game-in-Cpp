/* Name: Mateusz Serafin
** Number: 160272859
** Rook implementation
*/
#include "stdafx.h"
#include "Rook.h"

// constructor
Rook::Rook(double x, double y) :
	Piece(x, y)
{
	size = 2;	// default side length - provided in specification 
}
// destructor
Rook::~Rook(){}

// initialising static variable score
int Rook::score = 0;

// move by distance x and distance y 
bool Rook::move(double dx, double dy)
{
	// both dx and dy shouldnt be equal to 0, and both shouldnt be different than 0 at the same time 
	if ((dx == 0 || dy == 0) && (dy != 0 || dx != 0))
	{
		Piece::move(dx, dy);
		return true;
	}
	// else will not move - incorrect distances
	return false;
}

// move Rook by a random distance
void Rook::moveRandom(double boardWidth, double boardHeight)
{
	// random choice which of Rook co-ordinates will be equal to 0 (this is rule for his move)
	// calculate correct min and max value for which it can move and get a random number between that min and max
	if (randomDouble(0, 2) >= 1.0) // <1, 2)
	{
		double min_x = (-(this->getX())) + ((this->getSize()) / 2);
		double max_x = boardWidth - this->getX() - (this->getSize()) / 2;		
		double distance = randomDouble(min_x, max_x);
		move(distance, 0);
	}
	else // <0 to 1)
	{
		double min_y = (-(this->getY())) + (this->getSize()) / 2;
		double max_y = boardHeight - this->getY() - (this->getSize()) / 2;	 
		double distance = randomDouble(min_y, max_y);
		move(0, distance);
	}
}

// method for increasing score 
void Rook::scoredPoint()
{
	score++;
}

// overloading - displays only x and y, size is the same for every Rook
ostream & operator<<(ostream &out, const Rook &r)
{
	out << "Rook(x = " << r.getX() << ", y = " <<r.getY() << ")";
	return out;
}
void Rook::print()
{
	cout << *this;
}