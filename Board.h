// Programmer: Jeremy Law
// Course code: SENG1120
// Student number: c3183613

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <cassert>
#include <iostream>
namespace assignment2_c3183613
{
	class Board
	{
	public:
		//CONSTRUCTOR
		// Precondition: None
		// Postcondition: Initialises an empty board
		Board();
		// Mutator methods
		// Precondition: Board is initialised
		// Postcondition: Adds a move to the gameboard
		void addMove(std::string position); 
		// Precondition: Board is initialised
		// Postcondition: Returns move
		int getMove() const;
		// Precondition: Board is initialised
		// Postcondition: Adds the value 'X' or 'Y' to the 
		// game board at position x,y , depending on whose turn it is
		void input(std::string array[][3], int x, int y);
		// Not used
		void setLastMove(int lastPosition);
		// Not used
		int getLastMove() const;
		int getPreviousMoves(int a) const;
		// Precondition: Board is initialised
		// Postcondition: If a is in the array previousMoves, returns true. 
		// Returns false otherwise
		bool findInPreviousMoves(int a) const;
		// Precondition: Board is initialised
		// Postcondition: Returns true if gameBoard[x][y] is empty, false otherwise
		bool positionEmpty(int x, int y) const;
		// Precondition: Board is initialised
		// Postcondition: Returns the amount of empty positions on the current game board
		int howManyPositionEmpty();
		// Precondition: Board is initialised
		// Postcondition: Outputs that the given input is invalid and requests
		// for another input to be added to the gameboard
		void invalidMove();
		// useless
		void incrementCounter(int a);
		// Precondition: Board is initialised
		// Postcondition: Prints whose turn it is
		void playerTurn();
		// Precondition: Board is initialised
		// Postcondition: Returns true if all board slots are used
		bool isBoardFull();
		// Precondition: Board is initialised
		// Postcondition: Checks if there is a winner
		bool isWinner();
		// Precondition: Game has met an ending condition (a player has won or draw)
		// Postcondition: If AI wins, returns 1
		// if draw, returns 0, if AI loses, returns -1
		int isAIWinner();
		// Precondition: Board is initialised
		// Postcondition: Prints that a player is won
		void printWin();
		// Precondition: Board is initialised
		// Postcondition: Checks if two positions in the game board 
		// have the same value
		bool isSame(int x1, int y1, int x2, int y2);
		// Precondition: Board is initialised
		// Postcondition: Prints the layout of the board with numbers
		// representing how to choose the 'slot' to insert into
		void printEmptyBoard();
		// Precondition: Board is initialised
		// Postcondition: Prints the current state of the game board
		// 	With \s representing empty positons and X and Os in their places
		void printBoard() const;
		// overload ==

		// std::string& operator[] (const int x, const int y);
		// friend std::ostream operator << (std::ostream& out, const Board& a);
	private:
		std::string gameBoard[3][3];
		// Used to keep track of which player's turn it is,
		// using the modulus operator
		int moves;
		// Keeps track of which slots have been used
		int previousMoves[10];
	};
}
#endif