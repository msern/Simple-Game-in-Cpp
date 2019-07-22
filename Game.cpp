/* Name: Mateusz Serafin
** Number: 160272859
** Game class - simulation of a game
*/
#pragma once
#include "stdafx.h"
#include "CollisionDetection.h"
#include <ctime>

// Game settings
const double BOARD_WIDTH = 100, BOARD_HEIGHT = 100; // board size
const int BISHOPS = 10, ROOKS = 10, QUEENS = 10; // number of each pieces
const int MAX_ROUNDS = 100; // maximum number of rounds

// viariables used to initialise not colliding starting positions
const int ROW_SIZE = (int)BOARD_WIDTH / 5;	// max elements in one row
const int COLUMN_SIZE = (int)BOARD_HEIGHT / 5; // max num of columns 
int currentRow = 1;
int currentColumn = 1;

// methods signatures
void initializePieces(vector<Piece*>&);
bool isSpace();

int main()
{
	// making random numbers different in run of a program
	srand(time(NULL));

	// storing all pieces
	vector<Piece*> pieces;
	// initialise them using helper method 
	initializePieces(pieces);

	// number of current round
	int round = 1;
	while (MAX_ROUNDS >= round && pieces.size() != 1) // until max rounds reached or only 1 piece left in the game
	{
		cout << "\n\t########## ROUND " << round << " ##########\n";

		for (int i = 0; i < (int)pieces.size(); i++) // for every piece 
		{
			pieces[i]->print(); // print info about it 
			pieces[i]->moveRandom(BOARD_HEIGHT, BOARD_WIDTH); // move it randomly 
			cout << " moves to new position -> "; // indicating that it moved
			pieces[i]->print(); // printing new position
			cout << "\n";

			// after it moved, check if there is any collision between it and other pieces
			CollisionDetection::detectCollision(i, pieces);
		}
		round++; // after everyone has moved -> next round 
	}

	cout << "\n\t########## GAME OVER ##########\n\n";

	// Prining the number of pieces that left 
	cout << "### Number of Pieces left: " << pieces.size() << "\n";

	// if only one left, print it 
	if (pieces.size() == 1)
	{
		cout << "### Winning Piece: ";
		pieces.front()->print();
		cout << "\n";
	}
	// print score for each type
	cout << "### Bishop's score: " << Bishop::score << "\n";
	cout << "### Rook's score: " << Rook::score << "\n";
	cout << "### Queen's score: " << Queen::score << "\n";

	cout << "\n##########################################\n\n";

	// clear pieces, release memory
	for (int i = 0; i < (int)pieces.size(); i++)
		delete pieces[i];

	pieces.clear();

	system("pause");
	return 0;
}

// method which fills vector with pieces 
void initializePieces(vector<Piece*> &vector)
{
	for (int i = 0; i < BISHOPS; i++)
		if (isSpace())
			vector.push_back(new Bishop(currentRow * 5 - 2, currentColumn * 5 - 2));

	for (int i = 0; i < ROOKS; i++)
		if (isSpace())
			vector.push_back(new Rook(currentRow * 5 - 2, currentColumn * 5 - 2));

	for (int i = 0; i < QUEENS; i++)
		if (isSpace())
			vector.push_back(new Queen(currentRow * 5 - 2, currentColumn * 5 - 2));

	if ((int)vector.size() < BISHOPS + ROOKS + QUEENS)
		cout << "#### Too many Pieces requested and/or too small board - not all Pieces were added #### \n";
}

// method which checks if there is still some space for another Piece
bool isSpace() {
	if (currentRow < ROW_SIZE) {
		currentRow++;
		return true;
	}
	else if (currentColumn < COLUMN_SIZE) {
		currentRow = 1;
		currentColumn++;
		return true;
	}
	return false;
}
