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
		if (position.length() > 1)
			invalidMove();
		// Check input is a number
		// if(!isNumber(position))
		// 	invalidMove();
		// int intPosition = 0;
		// std::istringstream(position) >> intPosition;
		int intPosition = atoi(position.c_str());
		// within value range
		// check that position is empty
		// add X or O depending on moves
		if((intPosition <= 0 ) && (intPosition>9))
			invalidMove();
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

	void Board::invalidMove()
	{
		std::string input = "";
		std::cout << "Invalid position, please enter another location (1-9)\n";
		std::cin >> input;
		addMove(input);
	}

	void Board::input(std::string array[][3], int x, int y)
	{
		if((moves%2) == 1)
			array[x][y] = "O";
		if((moves%2) == 0)
			array[x][y] = "X";
		moves++;
	}

	int Board::getMove() const
	{
		return moves;
	}
		// increment moves
		// change lastPosition
	void setLastMove(int lastPosition);
	int getLastMove();
	bool Board::positionEmpty(int x, int y) const
	{
		if((gameBoard[x][y] == "X") || (gameBoard[x][y] == "O"))
			return false;
		else
			return true;
	}

	int Board::howManyPositionEmpty()
	{
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
		int a=0;
		for(int x=0; x<3; x++)
		{
			for(int y=0; y<3; y++)
			{
				if(!(positionEmpty(x,y)))
					a++;
			}
		}
		if ((a==9) && !(isWinner()))
		{
			std::cout << "It was a draw!\n";
			return true;
		}
		else
			return false;
	}

	bool Board::isSame(int x1, int y1, int x2, int y2)
	{
		if (((gameBoard[x1][y1] == "X") &&  (gameBoard[x2][y2] == "X")) || ((gameBoard[x1][y1] == "O") &&  (gameBoard[x2][y2] == "O")))
			return true;
		else
			return false;
	}
	bool Board::isWinner()
	{
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

	int Board::isAIWinner()
	{
		std::cout << "Do I get here?\n";
		if(isBoardFull() && !(isWinner()))
			return 0;
		else if (isWinner() && (moves-1)%2 == 0 )
			return 1;
		else
			return -1;
	}

	void Board::printWin()
	{
		if (isSame(0,0,0,1) && isSame(0,1,0,2))
			std::cout << "1- Player " << gameBoard[0][0] << " wins!\n";
		else if (isSame(1,0,1,1) && isSame(1,1,1,2))
			std::cout << "2- Player " << gameBoard[1][0] << " wins!\n";
		else if (isSame(2,0,2,1) && isSame(2,1,2,2))
			std::cout << "3- Player " << gameBoard[2][0] << " wins!\n";
		else if (isSame(0,0,1,0) && isSame(1,0,2,0))
			std::cout << "4- Player " << gameBoard[0][0] << " wins!\n";
		else if (isSame(0,1,1,1) && isSame(1,1,2,1))
			std::cout << "5- Player " << gameBoard[2][1] << " wins!\n";
		else if (isSame(0,2,1,2) && isSame(1,2,2,2))
			std::cout << "6- Player " << gameBoard[2][2] << " wins!\n";
		else if (isSame(0,0,1,1) && isSame(1,1,2,2))
			std::cout << "7- Player " << gameBoard[2][2] << " wins!\n";
		else if (isSame(0,2,1,1) && isSame(1,1,2,0))
			std::cout << "8- Player " << gameBoard[1][1] << " wins!\n";
	}

	void Board::playerTurn()
	{
		if((moves%2) == 1)
			std::cout <<  "O";
		if((moves%2) == 0)
			std::cout << "X";
	}
	
	void Board::printEmptyBoard()
	{
		std::cout << "1 2 3 \n4 5 6\n7 8 9\n";
	}

	void Board::incrementCounter(int a)
	{
		int counter = moves-2;
		previousMoves[counter] = a;
	}

	int Board::getPreviousMoves(int a) const
	{
		return previousMoves[a];
	}

	// Returns true if a exists in previousMoves[]
	bool Board::findInPreviousMoves(int a) const
	{
		for(int i=0; i<10; i++)
		{
			if(a == previousMoves[i])
				return true;
		}
		return false;
	}

	// bool Board::isNumber(std::string myString)
	// {
	// 	std::string numbers = "123456789";
	// 	for(int a=0; a<9;a++)
	// 	{
	// 		if (myStricng==numbers[a])
	// 			return true;
	// 	}
	// 	return false;
	// }

	// std::string& Board::operator[] (const int x, const int y)
	// {
	//     return gameBoard[x][y];
	// }

	// std::ostream operator << (std::ostream& out, const Board a)
	// {
	// 	out << "Gameboard: \n";
	// 	for(int x=0; x<3; x++)
	// 	{
	// 		for(int y=0; y<3; y++)
	// 		{
	// 			if(a.positionEmpty(x,y))
	// 				out << "\\ ";
	// 			else
	// 				out << a[x][y] << " ";
	// 		}
	// 		out << "\n";
	// 	}
	// 	return out;
	// }
}
