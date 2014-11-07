#ifndef AILOGIC_H
#define AILOGIC_H
#include "BTree.h"
#include "Board.h"
#include <sstream>
namespace assignment2_c3183613
{
	template <typename T>
	class AILogic

	{
		public:
			AILogic();
			void expand(BTree<T>*& root);
			int evaluate(const BTree<T>* tree);
			int randomNumber();
			int findLastMove(const Board gameBoard);
			int getComparison(const BTree<T>* root);

		private:
	};
	#include "AILogic.template"
}
#endif