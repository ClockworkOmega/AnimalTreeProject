#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef string Elem;

struct Node
{
	//int nodeID;
	Elem value;
	Node* parent;
	vector<Node*> child;
};

class AnimalTree
{
public:
	AnimalTree() { root_ = NULL; }
	~AnimalTree() {};
	void currentNode() const;				// Returns current node ID & value
	void parent() const;					// Return parent ID & value of current
	void children(const Elem& searchVal);			// Return string value of each node in current
	int size() const;						// Return size of tree
	bool empty() const;						// Return true if empty
	void root() const;						// Get the root string value
	bool isLeaf() const;					// Return true if current node is a leaf
	bool isRoot() const;					// Return true if current node is root
	
	Node* searchNodeString(const Elem& val, Node* subtree);				// Search for a particular node by it's string value
	void addRoot(const Elem& val);										// Add a root node to the tree
	void insert(const Elem& searchVal, const Elem& val);				// Create a child for the current node
	void search(const Elem& val);										// Find a node and set it to current

	Node* rootVal();
	Node* currentVal();

	// TEST FUNCTIONS
	void testSearch(const Elem& val);
	void childSize(const Elem& val);

private:
	Node* root_;
	Node* current_;
	int size_ = 0;
};