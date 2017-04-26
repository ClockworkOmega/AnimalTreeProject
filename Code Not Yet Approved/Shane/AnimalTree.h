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
	vector<Node*> children(current_) const;
	Node * FindFirstChild(current_) const;
    	Node * FindLastChild(current_) const;
    	Node * FindNthChild(int nth, current_) const;
	int size(struct node* node) const;
	bool empty() const {return size() ==0;};
	Node root() const; //Get the root
	// We need a positions function
	// Which returns the positions of all nodes
	// positions () const; <- example

private:
	Node* root_;
	Node* current_;
	int size_;

};

vector<Node*> Node::FindChildren(current_) const
{
    vector<Node*> children;
    for(vector<Node*>::const_iterator it = children.begin(); it < children.end(); it++) 
    {
        if (current_.compare((*it)->current_) == 0)
            children.push_back(*it);

    }
    return children;
}

Node * Node::FindFirstChild(current_) const
{
    for(vector<Node*>::const_iterator it = children.begin(); it < children.end(); it++) 
    {
        if (current_.compare((*it)->current_) == 0)
            return (*it);

    }
    return NULL;
}

Node * Node::FindNthChild(int nth, current_) const
{
    int n = 0;
    for(vector<Node*>::const_iterator it = children.begin(); it < children.end(); it--) 
    {
        if (current_.compare((*it)->current_) == 0)
        {
            if (++n == nth)
                return (*it);
        }

    }
    return NULL;
}
