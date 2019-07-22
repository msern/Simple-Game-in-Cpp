/* Name: Mateusz Serafin
** Number: 160272859
** Bishop implementation
*/
#include "stdafx.h"
#include "Bishop.h"

// constructor
Bishop::Bishop(double x, double  y) :
	Piece(x, y)
{
	size = 1;	// default radius - provided in specification 
}

// destructor
Bishop::~Bishop(){};

// initialising static variable score
int Bishop::score = 0;

// move method implementation
bool Bishop::move(double dx, double dy)
{	
	// move must be diagonal - absolute value of x and y should be the same 
	if ((dx != 0 && dy != 0) && (abs(dx) == abs(dy)))
	{
		Piece::move(dx, dy);
		return true;
	}
	// else will not move - incorrect distances
	return false;
}

// random move implementation
void Bishop::moveRandom(double boardWidth, double boardHeight)
{
	// calculating min and max for x and y values
	double max_x = boardWidth - this->getX() - this->getSize();
	double min_x = -this->getX() + this->getSize();

	double max_y = boardHeight - this->getY() - this->getSize();
	double min_y = -this->getY() + this->getSize();

	double dx;
	double dy;

	double randomChoice = randomDouble(0, 4);
	if (randomChoice < 1.0) // up-right
	{
		// smaller is max value by which Bishop can move 
		double smaller = max_x < max_y ? max_x : max_y;
		dx = randomDouble(0.001, smaller);
		dy = dx;
	}
	else if (randomChoice >= 1.0 && randomChoice < 2.0) // up-left
	{
		double smaller = abs(min_x) < max_y ? abs(min_x) : max_y;

		dy = randomDouble(0.001, smaller);
		dx = dy * (-1);
	}
	else if (randomChoice >= 2 && randomChoice < 3.0) // down-right
	{
		double smaller = max_x < abs(min_y) ? max_x : abs(min_y);

		dx = randomDouble(0.001, smaller);
		dy = dx * (-1);
	}
	else // down-left
	{ 
		double smaller = abs(min_x) < abs(min_y) ? abs(min_x) : abs(min_y);

		dx = randomDouble(0.001, smaller) * (-1);
		dy = dx;
	}
			
	move(dx, dy);
}
// adding point
void Bishop::scoredPoint()
{
	score++;
}

// no point of displaying any other data, every bishop has the same radius
ostream & operator<<(ostream &out, const Bishop &b)
{
	out << "Bishop(x = " << b.getX() << ", y = " << b.getY() << ")";
	return out;
}
void Bishop::print()
{
	cout << *this;
}

