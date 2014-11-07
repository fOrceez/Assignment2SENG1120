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
		void setData(const T& new_data);
		void setParent(BTree<T>* new_parent);
		void setLeft(BTree<T>* newLeft);
		void setRight(BTree<T>* newRight);
		//QUERY MEMBERS
		T getData() const;
		const BTree<T>* getParent() const;
		BTree<T>* getParent();
		const BTree<T>* getLeft() const;
		BTree<T>* getLeft();
		const BTree<T>* getRight() const;
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