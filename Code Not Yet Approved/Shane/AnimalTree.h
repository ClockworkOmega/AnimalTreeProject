#pragma once

#include <iostream>
#include <vector>

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
	int size(struct node* node) const;
	bool empty() const {return size() ==0;};
	bool isRoot() const;
	bool isExternal() const;
	Node root() const; //Get the root
	// We need a positions function
	// Which returns the positions of all nodes
	// positions () const; <- example

private:
	Node* root_;
	int size_;

};

int AnimalTree::size(struct node* node) const
{
	if(node==NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}

bool AnimalTree::isRoot() const
{
	if(parent == NULL)
		return 0;
	else
		return 1;
}

bool AnimalTree::isExternal() const
{
	if(children(NULL))
		return 0;
	else
		return 1;
}
