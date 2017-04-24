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
	Node* left;
	Node* right;
	vector<Node>* child;
};

class AnimalTree
{
public:
	AnimalTree() { root_ == NULL; }
	~AnimalTree() {};
	Elem& operator*() const;
	Node parent() const;
	vector<Node> children() const;
	int size() const;
	bool empty() const;
	bool isRoot() const;
	bool isExternal() const;
	Node root() const; //Get the root
	// We need a positions function
	// Which returns the positions of all nodes
	// positions () const; <- example
	
	// void insert();
	// void delete();

private:
	Node* root_;
	int size_;

};
