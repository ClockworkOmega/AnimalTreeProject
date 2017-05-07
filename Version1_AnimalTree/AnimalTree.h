#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef string Elem;

struct Node
{
	Elem value;
	int IDNum;
	Node* parent;
	vector<Node*> child;
	bool check = false;
};

class AnimalTree
{
public:
	AnimalTree() { root_ = NULL; }								// Create a tree
	~AnimalTree() {};											// Destuctor
	void currentNode() const;									// Cout current value
	Elem& currentVal();											// Return the current value
	void parent(const Elem& searchVal);							// Cout the parent value of current node
	Elem& parentVal(const Elem& searchVal);						// Return the string value of the parent node
	void children(const Elem& searchVal);						// Return string value of each node in current
	int size() const;											// Return size of tree
	bool empty() const;											// Return true if empty
	Elem& root() const;											// Get the root string value
	Node* rootVal();											// Return the root node
	bool isLeaf(const Elem& searchVal);							// Return true if current node is a leaf
	bool isRoot(const Elem& searchVal);							// Return true if current node is root
	bool isSibling(const Elem& searchVal, const Elem& sibling); // Return true if the two nodes passed in are siblings

	Node* searchNodeString(const Elem& val, Node* subtree);		// Search for a particular node by it's string value
	void search(const Elem& val);								// Find a node and set it to current
	void addRoot(const Elem& val);								// Add a root node to the tree
	void insert(const Elem& searchVal, const Elem& val);		// Create a child for the current node
	

	void readIn();												// Create the tree by reading in from a text file

	// Functions for Game One
	Elem& randomChild(const Elem& searchVal);					// Find a parent node and pick one of its children
	Elem checkSiblings(const Elem& searchVal);					// Find an unused sibling of the current node
	void checkBool(const Elem& searchVal);						// Change a node's bool to true

	// Functions for Game Two
	Node* searchNodeInt(const int num, Node* subtree);			// Search for a particular node by it's int value
	void searchInt(const int num);								// Find a node and set it to current


private:
	Node* root_;
	Node* current_;
	int size_;
};

