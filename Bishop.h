/* Name: Mateusz Serafin
** Number: 160272859
** Header for Bishop
** Derived from Piece
*/
#pragma once
#include <iostream>
#include "Piece.h"
using namespace std;

// Bishop is a circle 
class Bishop : public virtual Piece
{
public:
	// constructor
	Bishop(double x, double y);

	// destructor 
	~Bishop() override;

	// move methods 
	virtual bool move(double dx, double dy);
	virtual void moveRandom(double boardWidth, double boardHeight);

	// adding points
	virtual void scoredPoint();

	// output overload 
	friend ostream& operator<<(ostream&out, const Bishop&b);

	// printing info
	virtual void print();

public:
	static int score; // store Bishop's points
};
