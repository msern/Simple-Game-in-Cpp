/* Name: Mateusz Serafin
** Number: 160272859
** Piece implementation
*/
#include "stdafx.h"
#include "Piece.h"

// constructor - initialising centre points
Piece::Piece(double x_cord, double y_cord)
{
	x = x_cord;
	y = y_cord;
}

// default destructor
Piece::~Piece() = default;

// move method implementation - uses distance x and distance y 
bool Piece::move(double dx, double dy)
{
	x += dx;
	y += dy;
	return true;
}

// methods for getting x and y co-oridinates 
double Piece::getX() const
{
	return x;
}
double Piece::getY() const
{
	return y;
}
// getting Piece size
double Piece::getSize() const
{
	return size;
}

// output operator overload 
ostream & operator<<(ostream &out, const Piece &p)
{
	out << "Piece(x = " << p.getX() << ", y = " << p.getY() << ")";
	return out;
}

// method for generating random double - between min and max
double Piece::randomDouble(double min, double max)
{
	if (max == min) 
		return min;
	return min + (rand() / (RAND_MAX / (max - min)));
}
