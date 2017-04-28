#include <iostream>
#include <vector>
#include <string>
#include "AnimalTree.h"


// Return the size of the tree
int AnimalTree::size() const
{
	return size_;
}

// Return true if the tree is empty
// Otherwise return false
bool AnimalTree::empty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}

// Return the string value and node ID
// Of the current node
void AnimalTree::currentNode() const
{
	cout << "The current string value of the node is: " << current_->value << endl;
	cout << "The current node ID number is : " << current_->nodeID << endl;
}

// Return the string value and node ID of the root
void AnimalTree::root() const
{
	cout << "The root string value of the node is: " << root_->value << endl;
	cout << "The root node ID number is : " << root_->nodeID << endl;
}

// Return the string value
// and the ID number of the parent node
void AnimalTree::parent() const
{
	Node* tmp;
	tmp = new(struct Node);
	tmp = current_;

	tmp->parent;
	cout << "The string value of the parent of the current node is: " << tmp->value << endl;
	cout << "The node ID for the parent of the current node  is : " << tmp->nodeID << endl;
	
}

// Return the string value and ID number
// for each of the children of the current node
void AnimalTree::children() const
{
	Node* tmp;

	for (int i = 0; i < current_->child.size(); ++i)
	{
		tmp = current_->child[i];
		cout << "The string value of node number " << i << " is: " << tmp->value << endl;
		cout << "The node ID for node number " << i << " is: " << tmp->nodeID << endl;
		cout << endl << endl;
	}
}

// Returns true if the current node is a leaf
// Else return false
bool AnimalTree::isLeaf() const
{
	if (current_->child.size() == NULL)
		return true;
	else
		false;
}

// Return true if the current node 
// is the root of the tree
// else return false
bool AnimalTree::isRoot() const
{
	if (current_->parent == NULL)
		return true;
	else
		return false;
}


	// Function to add a root node to the tree
void AnimalTree::addRoot(const Elem& content)
{
	if (root_ == NULL)
	{
		root_ == new(struct Node);
		root_->parent = NULL;
		root_->value = content;
		size_++;
	}
	else
	{
		cout << "The tree already has a root node." << endl;
	}
}


void AnimalTree::insert(const Elem& val)
{
	
}

// Searches for a specific node in the tree
// and sets the current pointer to that node
Node* AnimalTree::searchNodeString(const Elem& val, Node* subtree)
{

	//Step 1: set current to root
	// Step 2: set current to equal the running of the function.

	if (subtree->value == val || subtree->child.size() == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < subtree->value.size(); ++i)
		{
			subtree = subtree->child[i];
			searchNodeString(val, subtree);
		}
	}
}