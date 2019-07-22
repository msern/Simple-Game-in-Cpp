/* Name: Mateusz Serafin
** Number: 160272859
** Header for Queen
** Derived from Rook and Bishop
*/

#pragma once
#include "Rook.h"
#include "Bishop.h"

using namespace std;

// Queen is a circle 
class Queen : public Rook, public Bishop
{
public:
	// constructor
	Queen(double x, double y);

	// destructor 
	~Queen() override;

	// move methods 
	bool move(double dx, double dy);
	void moveRandom(double boardWidth, double boardHeight);
	// adding points
	void scoredPoint();

	// output overload 
	friend ostream& operator<<(ostream&out, const Queen&b);
	// printing info
	void print();

public:
	static int score; // store Queen's points
};
