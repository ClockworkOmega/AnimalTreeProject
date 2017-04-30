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
}

// Return the string value of the root
void AnimalTree::root() const
{
	cout << "The root string value of the node is: " << root_->value << endl;
}

// Return the string value of the parent node
void AnimalTree::parent() const
{
	if (current_->parent == NULL)
	{
		cout << "This is the root node.\n\n";
	}
	else
	{
		Node* tmp;
		tmp = new(struct Node);
		tmp = current_;

		tmp->parent;
		cout << "The string value of the parent of the current node is: " << tmp->value << endl;
	}
	
}

// Return the string value
// for each of the children of the current node
void AnimalTree::children(const Elem& searchVal)
{
	Node* tmp;

	search(searchVal);

	if (current_->child.size() != 0)
	{

		for (int i = 0; i < current_->child.size(); ++i)
		{
			tmp = current_->child[i];
			cout << "The string value of node number " << i << " is: " << tmp->value << endl;
			cout << endl << endl;
		}
	}
	else
	{
		cout << "The current node does not have an children. It is a leaf.\n\n";
	}
}

// Returns true if the current node is a leaf
// Else return false
bool AnimalTree::isLeaf() const
{
	if (current_->child.size() == NULL)
		return true;
	else
		return false;
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
		root_ = new(struct Node);
		root_->parent = NULL;
		root_->value = content;
		current_ = root_;
		size_++;
	}
	else
	{
		cout << "The tree already has a root node." << endl;
	}
}


void AnimalTree::insert(const Elem& searchVal, const Elem& insertVal)
{
	// Find the parent node
	search(searchVal);	// Search for the node pointer you want to find

	if (current_->value != searchVal)
	{
		cout << "The insertion cannot be completed because the parent node "
			 << "does not exist.\n\n";
	}
	else
	{

		// Create a child and point the parent
		// pointer to the parent
		Node* tmp;								// Create a new node
		tmp = new(struct Node);					// Allocate memory to the new node
		tmp->parent = current_;					// Set new node parent pointer to current(parent) node
		tmp->value = insertVal;					// Assign user value to the value of the new node

		// Create a pointer for the parent
		// To point to the child
		Node* childPtr;							// Create a node pointer
		childPtr = tmp;							// Set node pointer to the new node
		current_->child.push_back(childPtr);	// Add the node pointer the vector of child node pointers

		// Increase size of the tree by one
		++size_;								// Increment the size for the new added node

		cout << insertVal << " was inserted into the tree." << endl;
	}
}

// Searches for a specific node in the tree
Node* AnimalTree::searchNodeString(const Elem& val, Node* subtree)
{

	//Node* nodePtr = root_;

	if (subtree != NULL && subtree->value != val)
	{
		for (int i = 0; i < subtree->child.size(); ++i)
		{
			searchNodeString(val, subtree = subtree->child[i]);
		}
	}
	
	if (subtree->value == val)
	{
		cout << "The " << subtree->value << " node was found in the tree." << endl;
		return subtree;
	}
	else
	{
		cout << "The " << subtree->value << " node was not found in the tree." << endl;
		subtree = NULL;
		return subtree;
	}
}

// Sets the current pointer to a certain node
void AnimalTree::search(const Elem& val)
{
	Node* tmp;
	current_ = root_;
	tmp = searchNodeString(val, current_);
	current_ = tmp;
}

Node* AnimalTree::rootVal()
{
	return root_;
}

Node* AnimalTree::currentVal()
{
	return current_;
}

////////////////////////////////////////////////////
///////////////////TEST FUNCTIONS///////////////////
////////////////////////////////////////////////////

void AnimalTree::testSearch(const Elem& val)
{
	search(val);
	currentNode();
}

void AnimalTree::childSize(const Elem& val)
{
	search(val);
	cout << current_->child.size() << endl;
}

