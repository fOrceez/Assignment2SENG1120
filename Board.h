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
		Board();
		// Mutator methods
		void addMove(std::string position); 
		int getMove() const;
		void input(std::string array[][3], int x, int y);
			// increment moves
			// change lastPosition
		void setLastMove(int lastPosition);
		int getLastMove() const;
		int getPreviousMoves(int a) const;
		bool findInPreviousMoves(int a) const;
		bool positionEmpty(int x, int y) const;
		int howManyPositionEmpty();
		void invalidMove();
		void incrementCounter(int a);
			// There is a value in that position, 
			// cin different position
		void playerTurn();
		bool isBoardFull();
		bool isWinner();
		int isAIWinner();
		void printWin();
		bool isSame(int x1, int y1, int x2, int y2);
		// bool isNumber(std::string myString);
		void printEmptyBoard();
		void printBoard() const;
		// overload ==

		// std::string& operator[] (const int x, const int y);
		// friend std::ostream operator << (std::ostream& out, const Board& a);
	private:
		std::string gameBoard[3][3];
		int moves;
		int previousMoves[10];
	};
}
#endif