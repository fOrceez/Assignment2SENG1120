// Programmer: Jeremy Law
// Course code: SENG1120
// Student number: c3183613

#ifndef AILOGIC_H
#define AILOGIC_H
#include "BTree.h"
#include "Board.h"
#include <sstream>
#include <cstdlib>
namespace assignment2_c3183613
{
	template <typename T>
	class AILogic

	{
		public:
			// Precondition: None
			// Postcondition: Initialises an instance of AILogic
			AILogic();
			// Precondition: A valid tree is inputted and the game has not met an end condition
			// Postcondition: For the purpose of this assignment, 
			// exhaustively creates a binary tree. Only reaches a stop condition if there
			// is a winner or the board is full.
			void expand(BTree<T>*& root);
			// Precondition: A valid tree is inputted and the game has not met an end condition
			// Postcondition: Calculates the the 'score' of the children of this root
			// The higher the score, the better the AI player does in this scenario
			int evaluate(const BTree<T>* tree);
			// Precondition: None
			// Postcondition: Returns a random number between 0 and 10 (non inclusive)
			int randomNumber();
			// Precondition: A valid tree is inputted and the game has not met an end condition
			// Postcondition: If the left child tree holds the (more) ideal move for the AI, 
			// returns the position that it used to lead it (returns the last inputted
			 // value of previousMoves[] in Board)
			int getComparison(const BTree<T>* root);

		private:
	};
	#include "AILogic.template"
}
#endif