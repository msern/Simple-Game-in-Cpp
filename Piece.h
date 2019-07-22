/* Name: Mateusz Serafin
** Number: 160272859
** Header for Piece
*/
#pragma once
#include <iostream>
using namespace std;

// abstract class
class Piece
{
public:
	// constructor
	Piece(double x_cord, double y_cord);

	// destructor - pure virtual 
	virtual ~Piece() = 0;

	// move methods
	virtual bool move(double dx, double dy);
	virtual void moveRandom(double boardWidth, double boardHeight) = 0;
	
	// adding points 
	virtual void scoredPoint() = 0;

	// methods for getting x and y co-ordinates - middle of Piece
	double getX() const;
	double getY() const;
	
	// getting size of Piece
	double getSize() const;

	// methods for prining Piece object 
	friend ostream& operator<<(ostream&out, const Piece&p);
	virtual void print() = 0; 

	// method for generating random double number between <min, max)
	double randomDouble(double min, double max);

protected:
	// centre points of Piece - x and y co-ordinates 
	double x, y;
	// Piece size 
	double size;
};

