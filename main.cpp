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
	cout << "Welcome to the Tic-Tac-Toe gameboard\n"
		 << "Please use numbers 1-9 to input a position.\n"
		 << "\\s represent empty spaces in the board\n"
		 << "Gameboard positions: \n"; 
	gameBoard->printEmptyBoard();
	gameBoard->printBoard();
	while (!(gameBoard->isBoardFull()) && !(gameBoard->isWinner()))
	{
		std::cout << "It is player "; gameBoard->playerTurn(); std::cout<<"\'s turn. \n";
		std::cout << "There are " <<   gameBoard->howManyPositionEmpty() << " positions empty.\n"
				<< "Please enter a position to insert at (1-9): ";
		cin >> position;
		gameBoard->addMove(position);
		cout << endl;
		gameBoard->printBoard();
		cout << endl << endl;
		if((gameBoard->isBoardFull()) && (gameBoard->isWinner()))
			break;
		//-------------------------

		gameTree->setData(*gameBoard);
		cout << "Beginning to expand tree\n";
		myAI->expand(gameTree);
		cout << "Expanded tree\n";
		int aiPosition = myAI->getComparison(gameTree);
		cout << "Finished evaluating tree\n";
		std::string strMove = "";
		std::stringstream sStreamMove;
		sStreamMove << aiPosition;
		cout << "int to sstream\n";
		strMove = sStreamMove.str();
		cout << "strMove = " << strMove << endl;
		cout << "sstream to string\n";
		gameBoard->addMove(strMove);
		cout << "Add move from AI\n";
		gameBoard->printBoard();
	}
	if(gameBoard->isWinner())
		gameBoard->printWin();


	return 0;
}
// odd is O 	- 1
// even is X 	- 0 	

// int random = 0;
// random = myAI->randomNumber();
// cout << random << endl;