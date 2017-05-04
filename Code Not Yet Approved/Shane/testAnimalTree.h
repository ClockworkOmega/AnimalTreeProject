#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef string Elem;

struct Node
{
	Elem value;
	Node* parent;
	vector<Node*> child;
	bool check;
};

class AnimalTree
{
public:
	AnimalTree() { root_ = NULL; }								// Create a tree
	~AnimalTree() {};
	void currentNode() const;									// Returns current value
	void parent(const Elem& searchVal);							// Return parent ID & value of current
	void children(const Elem& searchVal);						// Return string value of each node in current
	int size() const;											// Return size of tree
	bool empty() const;											// Return true if empty
	Elem& root() const;											// Get the root string value
	Node* rootVal();											// Return the root node
	bool isLeaf(const Elem& searchVal);							// Return true if current node is a leaf
	bool isRoot(const Elem& searchVal);							// Return true if current node is root

	Node* searchNodeString(const Elem& val, Node* subtree);		// Search for a particular node by it's string value
	void addRoot(const Elem& val);								// Add a root node to the tree
	void insert(const Elem& searchVal, const Elem& val);		// Create a child for the current node
	void search(const Elem& val);								// Find a node and set it to current

	void readIn(Node& root);									// Create the tree by reading in from a text file

	// Functions for Game
	Elem& randomChild(const Elem& searchVal);					// Find a parent node and pick one of its children
	Elem& checkSiblings(const Elem& searchVal);					// Find an unused sibling of the current node
	void checkBool(const Elem& searchVal);						// Change a node's bool to true

private:
	Node* root_;
	Node* current_;
	int size_ = 0;
};
