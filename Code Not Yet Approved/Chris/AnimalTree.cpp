#include <iostream>
#include <vector>
#include <string>
#include "AnimalTree.h"


int AnimalTree::size() const
{
	return size_;
}

bool AnimalTree::empty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}

void AnimalTree::currentNode() const
{
	cout << "The current string value of the node is: " << current_->value << endl;
	cout << "The current node ID number is : " << current_->nodeID << endl;
}

void AnimalTree::root() const
{
	cout << "The root string value of the node is: " << root_->value << endl;
	cout << "The root node ID number is : " << root_->nodeID << endl;
}


void AnimalTree::parent() const
{
	Node* tmp;
	tmp = new(struct Node);
	tmp = current_;

	tmp->parent;
	cout << "The string value of the parent of the current node is: " << tmp->value << endl;
	cout << "The node ID for the parent of the current node  is : " << tmp->nodeID << endl;
	
}

bool AnimalTree::isLeaf() const
{
	if (current_->child == NULL)
		return true;
	else
		false;
}

bool AnimalTree::isRoot() const
{
	if (current_->parent == NULL)
		return true;
	else
		return false;
}

void AnimalTree::searchNodeString(string val)
{
	current_ = root_;
	if (root_->value == val)
	{
		current_ = root_;
	}
	else
	{
		vector<Node>* tmp;
		tmp = current_->child;

		// Point the current pointer to the child of root
		// child == vector of nodes (search through the vector)

		//  if (child == NULL) continue;
		// for (int i = 0; i < size; ++i)
		//{
		for (int i = 0; i < (tmp).size(); i++)
		{
			if ((tmp)[i].value == val) //...
			{
				current_ = (tmp)[i];
			}
		}
		//	else ((*child)[i].searchNodeString (...)) ...
		//}

		//AnimalTree::search(~)
		/*{
			root->search(~)
		}*/

	}
}