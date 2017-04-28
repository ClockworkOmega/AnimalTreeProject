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

void AnimalTree::children() const
{
	Node* tmp;

	for (int i = 0; i < current_->child.size(); ++i)
	{
		tmp = current_->child[i];
		cout << "The string value of node number " << i << " is: " << tmp->value << endl;
		cout << "The node ID for node number " << i << " is: " << tmp->nodeID << endl;
	}
}

bool AnimalTree::isLeaf() const
{
	if (current_->child.size() == NULL)
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
	int lowestNodeNum;

	current_ = root_;
	if (root_->value == val)
	{
		current_ = root_;
	}
	else
	{
		
		while (current_ != NULL)
		{
			current_ = current_->child[lowestNodeNum];

			if (current_->value == val)
			{
				break;
			}
		}



	}
}