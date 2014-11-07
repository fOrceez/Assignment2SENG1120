#ifndef NODE_H
#define NODE_H

namespace assignment1_c3183613
{
	template <typename T>
	class BTNode
	{
	public:
		//CONSTRUCTOR
		BTNode(const T& init_data, BTNode<T>* parent_link = NULL, BTNode<T>* leftLink = NULL,  BTNode<T>* rightLink = NULL);
		//MUTATOR MEMBERS
		void setData(const T& new_data);
		void setParent(BTNode<T>* new_parent);
		void setLeft(BTNode<T>* newLeft);
		void setRight(BTNode<T>* newRight);
		//QUERY MEMBERS
		T getData() const;
		const BTNode<T>* getParent() const;
		BTNode<T>* getParent();
		const BTNode<T>* getLeft() const;
		BTNode<T>* getLeft();
		const BTNode<T>* getRight() const;
		BTNode<T>* getRight();
	private:
		BTNode<T>* parent;
		BTNode<T>* left;
		BTNode<T>* right;
		T data;
	};
	#include "BTNode.template"
};
#endif