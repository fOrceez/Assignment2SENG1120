// Programmer: Jeremy Law
// Course code: SENG1120
// Student number: c3183613

#include "Board.h"
#include <cstdlib>
#include <sstream>
namespace assignment2_c3183613
{
	Board::Board()
	{
		for(int a=0; a<3 ; a++)
		{
			for(int b=0; b<3 ; b++)
			{
				gameBoard[a][b] = "";
			}
		}
		moves = 1;
	}

	void Board::addMove(std::string position)
	{
		// Because our values can only be 1-9
		// The length of 'position' can not be larger than 1
		// If the length is bigger than 1, 
		if (position.length() > 1)
			invalidMove();
		// Turns out string into an integer
		int intPosition = atoi(position.c_str());
		// If it is outside of our boundaries, throw invalidMove error
		if((intPosition <= 0 ) && (intPosition>9))
			invalidMove();
		// If intPosition is empty, adds that move
		// Otherwise, throws invalidMove error (which also requests for a new input)
		switch(intPosition)
		{
			case 1:
			{
				// check [0][0] is empty
				if((gameBoard[0][0] == "X") || (gameBoard[0][0] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,0,0);
					incrementCounter(1);
				}
				break;
			}
			case 2:
			{
				if((gameBoard[0][1] == "X") || (gameBoard[0][1] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,0,1);
					incrementCounter(2);
				}
				break;
			}
			case 3:
			{
				if((gameBoard[0][2] == "X") || (gameBoard[0][2] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,0,2);
					incrementCounter(3);
				}
				break;
			}
			case 4:
			{
				if((gameBoard[1][0] == "X") || (gameBoard[1][0] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,1,0);
					incrementCounter(4);
				}
				break;
			}
			case 5:
			{
				if((gameBoard[1][1] == "X") || (gameBoard[1][1] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,1,1);
					incrementCounter(5);
				}
				break;
			}
			case 6:
			{
				if((gameBoard[1][2] == "X") || (gameBoard[1][2] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,1,2);
					incrementCounter(6);
				}
				break;
			}
			case 7:
			{
				if((gameBoard[2][0] == "X") || (gameBoard[2][0] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,2,0);
					incrementCounter(7);
				}
				break;
			}
			case 8:
			{
				if((gameBoard[2][1] == "X") || (gameBoard[2][1] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,2,1);
					incrementCounter(8);
				}
				break;
			}
			case 9:
			{
				if((gameBoard[2][2] == "X") || (gameBoard[2][2] == "O"))
					invalidMove();
				else
				{
					input(gameBoard,2,2);
					incrementCounter(9);
				}
				break;
			}

			default:
			{
				invalidMove();
				break;
			}
		}
	}

	// If there is an invalid move, tell the user the input is no good
	// Ask for a position to input the player's turn
	void Board::invalidMove()
	{
		std::string input = "";
		std::cout << "Invalid input, please enter another location (1-9)\n";
		std::cin >> input;
		addMove(input);
	}

	// Sets the position of the gameboard
	// to the value of the respective player's turn
	// at the position [x][y]
	void Board::input(std::string array[][3], int x, int y)
	{
		if((moves%2) == 1)
			array[x][y] = "O";
		if((moves%2) == 0)
			array[x][y] = "X";
		moves++;
	}

	// Return which move the game is up to
	int Board::getMove() const
	{
		return moves;
	}

	void setLastMove(int lastPosition);
	int getLastMove();

	// If the position gameBoard[x][y] is unused,
	// Return true, otherwise, return false
	bool Board::positionEmpty(int x, int y) const
	{
		if((gameBoard[x][y] == "X") || (gameBoard[x][y] == "O"))
			return false;
		else
			return true;
	}

	// Checks how many unused positions there are in the game board
	int Board::howManyPositionEmpty()
	{
		// Initialise a counter integer of 9, decrement by 1
		// Each time there is a position in gameBoard that is used
		int counter = 9;
		for(int a=0; a<3; a++)
		{
			for(int b=0; b<3; b++)
			{
				if(positionEmpty(a,b) == false)
					counter--; 
			}
		}
		return counter;
	}
	
	// Prints the current state of the gameBoard.
	// \s represent empty positions
	void Board::printBoard() const
	{
		std::cout << "Gameboard: \n";
		for(int x=0; x<3; x++)
		{
			for(int y=0; y<3; y++)
			{
				if(positionEmpty(x,y))
					std::cout << "\\ ";
				else
					std::cout << gameBoard[x][y] << " ";
			}
			std::cout << "\n";
		}
	}

	bool Board::isBoardFull()
	{
		// Increments by one if a slot on the board is used
		// 
		int a=0;
		for(int x=0; x<3; x++)
		{
			for(int y=0; y<3; y++)
			{
				if(!(positionEmpty(x,y)))
					a++;
			}
		}

		// If the gameboard is full and there is no winner,
		// there was a draw, return true. Otherwise, return false
		if ((a==9) && !(isWinner()))
		{
			return true;
		}
		else
			return false;
	}

	// If the value of gameBoard[X1][Y1] is the same as
	// gameBoard[X2][Y2], return true. Return false otherwise
	bool Board::isSame(int x1, int y1, int x2, int y2)
	{
		if (((gameBoard[x1][y1] == "X") &&  (gameBoard[x2][y2] == "X")) || ((gameBoard[x1][y1] == "O") &&  (gameBoard[x2][y2] == "O")))
			return true;
		else
			return false;
	}
	bool Board::isWinner()
	{
		// Returns true if there is a winner at the winning combinations
		// False otherwise
		if (isSame(0,0,0,1) && isSame(0,1,0,2))
		{
			return true;
		}
		else if (isSame(1,0,1,1) && isSame(1,1,1,2))
		{
			return true;
		}
		else if (isSame(2,0,2,1) && isSame(2,1,2,2))
		{
			return true;
		}
		else if (isSame(0,0,1,0) && isSame(1,0,2,0))
		{
			return true;
		}
		else if (isSame(0,1,1,1) && isSame(1,1,2,1))
		{
			return true;
		}
		else if (isSame(0,2,1,2) && isSame(1,2,2,2))
		{
			return true;
		}
		else if (isSame(0,0,1,1) && isSame(1,1,2,2))
		{
			return true;
		}
		else if (isSame(0,2,1,1) && isSame(1,1,2,0))
		{
			return true;
		}
		else
			return false;
	}

	// Returns 0 if there is a draw, 
	// 1 if the 'O' player (AI) wins
	// -1 if the 'X' player wins
	int Board::isAIWinner()
	{
		if(isBoardFull() && !(isWinner()))
			return 0;
		else if (isWinner() && (moves-1)%2 == 0 )
			return 1;
		else
			return -1;
	}

	void Board::printWin()
	{
		// Outputs that a player has won
		if (isSame(0,0,0,1) && isSame(0,1,0,2))
			std::cout << "Player " << gameBoard[0][0] << " wins!\n";
		else if (isSame(1,0,1,1) && isSame(1,1,1,2))
			std::cout << "Player " << gameBoard[1][0] << " wins!\n";
		else if (isSame(2,0,2,1) && isSame(2,1,2,2))
			std::cout << "Player " << gameBoard[2][0] << " wins!\n";
		else if (isSame(0,0,1,0) && isSame(1,0,2,0))
			std::cout << "Player " << gameBoard[0][0] << " wins!\n";
		else if (isSame(0,1,1,1) && isSame(1,1,2,1))
			std::cout << "Player " << gameBoard[2][1] << " wins!\n";
		else if (isSame(0,2,1,2) && isSame(1,2,2,2))
			std::cout << "Player " << gameBoard[2][2] << " wins!\n";
		else if (isSame(0,0,1,1) && isSame(1,1,2,2))
			std::cout << "Player " << gameBoard[2][2] << " wins!\n";
		else if (isSame(0,2,1,1) && isSame(1,1,2,0))
			std::cout << "Player " << gameBoard[1][1] << " wins!\n";
	}

	// Checks which players turn it is via modulus arithmatic
	// Odd number of turns, player Os turn
	// Even number of turns, player Xs turn
	void Board::playerTurn()
	{
		if((moves%2) == 1)
			std::cout <<  "O";
		if((moves%2) == 0)
			std::cout << "X";
	}
	
	// Prints each "position" of slots of the board
	void Board::printEmptyBoard()
	{
		std::cout << "1 2 3 \n4 5 6\n7 8 9\n";
	}

	// Useless
	void Board::incrementCounter(int a)
	{
		int counter = moves-2;
		previousMoves[counter] = a;
	}

	// Return what is in the array at position a
	int Board::getPreviousMoves(int a) const
	{
		return previousMoves[a];
	}

	// Returns true if a exists in previousMoves[]
	bool Board::findInPreviousMoves(int a) const
	{
		// Checks each element within the array previousMoves
		// If a is found in previousMoves, return true
		for(int i=0; i<10; i++)
		{
			if(a == previousMoves[i])
				return true;
		}
		return false;
	}

}
