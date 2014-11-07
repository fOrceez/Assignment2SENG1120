// Programmer: Jeremy Law
// Course code: SENG1120
// Student number: c3183613

#ifndef NODE_H
#define NODE_H

namespace assignment2_c3183613
{
	template <typename T>
	class BTree
	{
	public:
		//CONSTRUCTOR
		BTree();
		BTree(const T& init_data, BTree<T>* parent_link = NULL, BTree<T>* leftLink = NULL,  BTree<T>* rightLink = NULL);
		//DESTRUCTOR
		~BTree();
		//MUTATOR MEMBERS

		// Precondition: Tree is initialised
		// Postcondition: Sets value of 'data' to 'new_data'
		void setData(const T& new_data);
		// Precondition: Tree is initialised
		// Postcondition: sets pointer 'parent' to 'new_parent'
		void setParent(BTree<T>* new_parent);
		// Precondition: Tree is initialised
		// Postcondition: sets pointer 'left' to 'new_left'
		void setLeft(BTree<T>* newLeft);
		// Precondition: Tree is initialised
		// Postcondition: sets pointer 'right' to 'new_right'
		void setRight(BTree<T>* newRight);
		//QUERY MEMBERS
		// Precondition: Tree is initialised and data has a valid value
		// Postcondition: Returns data
		T getData() const;
		// Precondition: Tree is initialised and Parent has been set
		// Postcondition: Returns parent
		const BTree<T>* getParent() const;
		// Precondition: Tree is initialised and Parent has been set
		// Postcondition: Returns parent
		BTree<T>* getParent();
		// Precondition: Tree is initialised and left has been set
		// Postcondition: Returns left
		const BTree<T>* getLeft() const;
		// Precondition: Tree is initialised and left has been set
		// Postcondition: Returns left
		BTree<T>* getLeft();
		// Precondition: Tree is initialised and right has been set
		// Postcondition: Returns right
		const BTree<T>* getRight() const;
		// Precondition: Tree is initialised and right has been set
		// Postcondition: Returns right
		BTree<T>* getRight();
	private:
		BTree<T>* parent;
		BTree<T>* left;
		BTree<T>* right;
		T data;
	};
	#include "BTree.template"
};
#endif

/*
		// Precondition: Tree is initialised
		// Postcondition: 
*/