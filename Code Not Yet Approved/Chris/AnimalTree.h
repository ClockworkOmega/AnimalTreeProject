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
};

class Tree
{
public:
	Tree() { root_ = NULL; }
	~Tree() {};
	void currentNode() const;					// Returns current value
	void parent(const Elem& searchVal);				// Return parent ID & value of current
	void children(const Elem& searchVal);				// Return string value of each node in current
	int size() const;						// Return size of tree
	bool empty() const;						// Return true if empty
	Node root() const;						// Get the root string value
	Node* rootVal();						// Return the root node
	bool isLeaf(const Elem& searchVal);				// Return true if current node is a leaf
	bool isRoot(const Elem& searchVal);				// Return true if current node is root

	Node* searchNodeString(const Elem& val, Node* subtree);		// Search for a particular node by it's string value
	void addRoot(const Elem& val);					// Add a root node to the tree
	void insert(const Elem& searchVal, const Elem& val);		// Create a child for the current node
	void search(const Elem& val);					// Find a node and set it to current

private:
	Node* root_;
	Node* current_;
	int size_ = 0;
};
