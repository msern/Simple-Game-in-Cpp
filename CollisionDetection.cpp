/* Name: Mateusz Serafin
** Number: 160272859
** CollisionDetection methods implementation
*/
#include "stdafx.h"
#include "CollisionDetection.h"

void CollisionDetection::detectCollision(int indexOfMovingPiece, vector<Piece*> &pieces)
{
	for (int i = 0; i < (int)pieces.size(); i++) // For every piece in vector of pieces  
	{
		if (indexOfMovingPiece != i)  // but not the moving one
		{
			if (CollisionDetection::collision(pieces[indexOfMovingPiece], pieces[i])) // check if there is a collision 
			{
				// if yes
				pieces[indexOfMovingPiece]->scoredPoint(); // piece scored another point

				// release memory and remove from vector
				delete pieces[i];
				pieces.erase(pieces.begin() + i);

				// print out some info to console
				cout << "******* COLLISION ****** PIECES LEFT: ";
				cout << pieces.size() << " ******\n";

				if (i < indexOfMovingPiece) // if deleted Piece was before moving Piece in vector then changed its index 
					indexOfMovingPiece--;
			}
		}
	}
}
// detecting collision between two pieces 
bool CollisionDetection::collision(Piece *p1, Piece *p2) 
{
	// checking is p1 and p2 are circles - Queen or Bishop
	bool isP1Circle = typeid(*p1) == typeid(Queen) || typeid(*p1) == typeid(Bishop);
	bool isP2Circle = typeid(*p2) == typeid(Queen) || typeid(*p2) == typeid(Bishop);

	if (isP1Circle && isP2Circle) // two circles -> call the right method 
		return collisionCircles(p1->getX(), p1->getY(), p1->getSize(), p2->getX(), p2->getY(), p2->getSize());

	// checking if p1 and p2 are squares - Rook
	bool isP1Square = typeid(*p1) == typeid(Rook);
	bool isP2Square = typeid(*p2) == typeid(Rook);

	if (isP1Square && isP2Square) // two squares-> call the right method 
		return collisionSquares(p1->getX(), p1->getY(), p1->getSize(), p2->getX(), p2->getY(), p2->getSize());

	if (isP1Circle && isP2Square) // circle and square -> call the right method 
		return collisionCircleSquare(p1->getX(), p1->getY(), p1->getSize(), p2->getX(), p2->getY(), p2->getSize());

	if (isP2Circle && isP1Square) // square and circle -> call the right method  
		return collisionCircleSquare(p2->getX(), p2->getY(), p2->getSize(), p1->getX(), p1->getY(), p1->getSize());

	// else type does not exist
	return false;
}

// detecting collision between two circles
bool CollisionDetection::collisionCircles(const double circle1X, const double circle1Y, const double circle1Size, const double circle2X, const double circle2Y, const double circle2Size)
{
	// distance between two points - circle's centeres point (before taking sqrt)
	double distanceSqr = ((circle1X - circle2X) * (circle1X - circle2X)) + ((circle1Y - circle2Y) * (circle1Y - circle2Y));
	// sum of radiuses length (to the power of two)
	double radiusSumSqr = (circle1Size + circle2Size) * (circle1Size + circle2Size);

	// comparing distance and radius sum (both squared) -> if true then collison happend
	if (distanceSqr <= radiusSumSqr)
		return true;
	// else no collision 
	return false;
}

// detecting collision between two squares
bool CollisionDetection::collisionSquares(const double square1X, const double square1Y, const double square1Size, const double square2X, const double square2Y, const double square2Size)
{
	// check if squares are completly outside each other 
	bool isOutsideLeft = square1X + (square1Size / 2) < square2X - (square2Size / 2);
	bool isOutsideRight = square1X - (square1Size / 2) > square2X + (square2Size / 2);
	bool isOutsideTop = square1Y + (square1Size / 2) < square2Y - (square2Size / 2);
	bool isOutsideBottom = square1Y - (square1Size / 2) > square2Y + (square2Size / 2);

	// if all conditions above are false then there is a collision
	return !(isOutsideLeft || isOutsideRight || isOutsideTop || isOutsideBottom);
}

// detecting collision between circle and square
bool CollisionDetection::collisionCircleSquare(const double circleX, const double circleY, const double circleSize, const double squareX, const double squareY, const double squareSize)
{
	// check if there is collision in a distance of a half of the square side lenghth and circle  
	if (collisionCircles(circleX, circleY, circleSize, squareX, squareY, squareSize/2))
		return true;

	// if false then need to check corners - which were not checked in method above 
	double cornerDistance_sq = (abs(circleX - squareX) - squareSize / 2) * (abs(circleX - squareX) - squareSize / 2) +
		(abs(circleY - squareY) - squareSize / 2) * (abs(circleY - squareY) - squareSize / 2);

	// comparing squared distances - if true then there is a collision 
	return (cornerDistance_sq <= (circleSize * circleSize));
}