// Programmer: Jeremy Law
// Course code: SENG1120
// Student number: c3183613

#include <iostream>
#include "AILogic.h"
#include "BTree.h"
#include "Board.h"
#include <ctime>
using namespace std;
using namespace assignment2_c3183613;

int main()
{
	Board* gameBoard = new Board();
	BTree<Board>* gameTree = new BTree<Board>();
	AILogic<Board>* myAI = new AILogic<Board>();	
	std::string position = "";
	// Instructions
	cout << "Please read the 'readMe.txt' before continuing.\n";
	cout << "Welcome to the Tic-Tac-Toe gameboard\n"
		 << "Please use numbers 1-9 to input a position.\n"
		 << "\\s represent empty spaces in the board\n"
		 << "Gameboard positions: \n"; 
	// Print example board
	gameBoard->printEmptyBoard();
	// Print empty board (current state)
	gameBoard->printBoard();
	// Keep playing until either win, lose, or draw
	while (!(gameBoard->isBoardFull()) && !(gameBoard->isWinner()))
	{
		// Prompts player (X or O) that it is their turn
		std::cout << "It is player "; gameBoard->playerTurn(); std::cout<<"\'s turn. \n";
		// There are X many possible moves remaining
		std::cout << "There are " <<   gameBoard->howManyPositionEmpty() << " positions empty.\n"
				<< "Please enter a position to insert at (1-9): ";
		// Recieves input for desired position by player
		cin >> position;
		// Adds it to the board
		gameBoard->addMove(position);
		cout << endl;
		// Print current board state
		gameBoard->printBoard();
		cout << endl << endl;
		// If we have met an end condition,
		// Print the winner end the game
		if((gameBoard->isBoardFull()) || (gameBoard->isWinner()))
		{
			gameBoard->printWin();
			return 0;
		}
		//-------------------------
		// Slow and steady wins the race..
		cout << "Calculating the AI's move... (This make take a while)\n";
		gameTree->setData(*gameBoard);
		// Exhaustively creates possible outcomes for the given game board state
		myAI->expand(gameTree);
		int aiPosition = myAI->getComparison(gameTree);
		// Converts string stream to string
		std::string strMove = "";
		std::stringstream sStreamMove;
		sStreamMove << aiPosition;
		strMove = sStreamMove.str();
		// Add move (string)
		gameBoard->addMove(strMove);
		gameBoard->printBoard();
	}
	// If someone has won, print the winner
	if(gameBoard->isWinner())
		gameBoard->printWin();


	return 0;
}
// odd is O 	- 1
// even is X 	- 0 	

// int random = 0;
// random = myAI->randomNumber();
// cout << random << endl;