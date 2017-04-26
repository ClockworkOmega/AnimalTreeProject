#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef string Elem;

struct Node
{
	int nodeID;
	Elem value;
	Node* parent;
	Node* left;
	Node* right;
	vector<Node>* child;
};

class AnimalTree
{
public:
	AnimalTree() { root_ == NULL; }
	~AnimalTree() {};
	void currentNode() const;				// Returns current node ID & value
	void parent() const;					// Return parent ID & value of current
	vector<Node> children() const;
	int size() const;						//DONE
	bool empty() const;
	void root() const;						// Get the root ID & value
	// We need a positions function
	// Which returns the positions of all nodes
	// positions () const; <- example

	//'void search
	void currentNode() const;

private:
	Node* root_;
	Node* current_;
	int size_;
};