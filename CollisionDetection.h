/* Name: Mateusz Serafin
** Number: 160272859
** Header for CollisionDetection
*/
#pragma once
#include <vector>
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"

// has methods to detect collisions between pieces
class CollisionDetection
{
public:
	// check if there is collision between moving Piece and any other Pieces in Vector
	static void detectCollision(int indexOfMovingPiece, vector<Piece*> &pieces);

	// check collision between two pieces - checks their type and return one of the methods below 
	static bool collision(Piece*, Piece*);

	// checks collision between two circles
	static bool collisionCircles(const double circle1X, const double circle1Y, const double circle1Size, const double circle2X, const double circle2Y, const double circle2Size);

	// checks collision between two squares
	static bool collisionSquares(const double squre1X, const double square1Y, const double square1Size, const double square2X, const double square2Y, const double square2Size);

	// checks collision between circle and square
	static bool collisionCircleSquare(const double circleX, const double circleY, const double circleSize, const double squareX, const double squareY, const double squareSize);
};