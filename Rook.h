/* Name: Mateusz Serafin
** Number: 160272859
** Header for Rook class
** Derived from Piece
*/
#pragma once
#include <iostream>
#include "Piece.h"

using namespace std;

// Rook is a square
class Rook : public virtual Piece
{
public:
	// consturctor
	Rook(double x, double y);
	
	// destructor
	~Rook() override;

	// move methods
	virtual bool move(double dx, double dy);
	virtual void moveRandom(double boardWidth, double boardHeight);
	
	// adding points for Rooks
	virtual void scoredPoint();

	// operator overload
	friend ostream& operator<<(ostream&out, const Rook&r);

	// printing info about Rook
	virtual void print();

public:
	static int score; // store Rook's points
};
