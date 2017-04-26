#include <iostream>
#include <vector>
#include <string>
#include "AnimalTree.h"


int AnimalTree::size() const
{
	return size_;
}

bool AnimalTree::empty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}

//Elem& AnimalTree::operator*() const
//{
//	return current_->value;
//}

void AnimalTree::currentNode() const
{
	cout << "The current string value of the node is: " << current_->value << endl;
	cout << "The current node ID number is : " << current_->nodeID << endl;
}

void AnimalTree::root() const
{
	cout << "The root string value of the node is: " << root_->value << endl;
	cout << "The root node ID number is : " << root_->nodeID << endl;
}


//Node AnimalTree::parent() const
//{
//
//	current_->parent;
//	return current_->value;
//}