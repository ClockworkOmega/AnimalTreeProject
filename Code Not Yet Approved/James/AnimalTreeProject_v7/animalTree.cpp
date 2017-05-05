#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include "animalTree.h"


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
Elem& AnimalTree::root() const
{
	return root_->value;
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
bool AnimalTree::isLeaf(const Elem& searchVal)
{
	search(searchVal);				// Search for the node by it's element

	if (current_->child.size() == NULL)		// Determine if the current node
		return true;				// is a leaf or not
	else
		return false;
}

// Return true if the current node 
// is the root of the tree
// else return false
bool AnimalTree::isRoot(const Elem& searchVal)
{
	search(searchVal);			// Search for the node by its element


	if (current_->parent == NULL)		// Return whether the current node
		return true;			// is the root node or not
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

		//cout << insertVal << " was inserted into the tree." << endl;
	}
}

// Searches for a specific node in the tree
Node* AnimalTree::searchNodeString(const Elem& val, Node* subtree)
{

	if (subtree->value == val)
	{
		//cout << "The " << val << " node was found in the tree." << endl;	
		return subtree;
	}

	else if (subtree == NULL)
	{
		return NULL;
	}

	else
	{
		for (int i = 0; i < subtree->child.size(); ++i)
		{
			Node* result = searchNodeString(val, subtree->child[i]);
			if (result != NULL)
				return result;
		}
		return NULL;
	}
}

// Sets the current pointer to a certain node
void AnimalTree::search(const Elem& val)
{
	Node* tmp;
	tmp = searchNodeString(val, rootVal());

	if (tmp != NULL)
	{
		current_ = tmp;
	}
	else
	{
		cout << "The value you were looking for was not found.\n\n";
		return;
	}
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


void AnimalTree::readIn()
{
	//start by reading unitl :
	//check the string toUpper compared to each Node.name toUpper
	//if there is a match, add to that Node's vector. Else, the new string must be the root.
	//put the string up to : as the Node.name
	//put each string following the : as an individual Node, each string seperated by the ,
	//once "\0" is reached, insert the the last string and stop reading that line.


	fstream inFile;
	inFile.open("entities_hierarchy-1.txt");

	if (inFile.fail())
	{
		cout << "You done goofed." << endl;
		system("pause");
		exit(1);
	}
	cout << "File opened." << endl;
	string reader;
	char mine = 'a';
	while (inFile.good() && mine != ':')
	{
		inFile.get(mine);
		if (mine != ':')
			reader = reader + mine;
	}

	cout << reader << endl;
	addRoot(reader);

	//vector<Node*> tempVec;
	reader.clear();


	while (inFile.good() && mine != '\n')
	{
		//Node* tempNode = new Node;
		//tempNode->parent = root_;
		inFile.get(mine);
		inFile.get(mine);
		while (inFile.good() && mine != ',' && mine != '\n')
		{
			reader = reader + mine;
			inFile.get(mine);
		}
		cout << reader << endl;
		//tempNode->value = reader;
		insert(root_->value, reader);
		reader.clear();
		//root_->child.push_back(tempNode);
	}


	while (inFile.good())
	{
		while (inFile.good() && mine != ':')
		{
			inFile.get(mine);
			if (mine != ':')
				reader = reader + mine;
		}
		search(reader);
		reader.clear();
		while (inFile.good() && mine != '\n')
		{
			//Node* tempNode = new Node;
			//tempNode->parent = current_;
			inFile.get(mine);
			inFile.get(mine);
			while (inFile.good() && mine != ',' && mine != '\n')
			{
				reader = reader + mine;
				inFile.get(mine);
			}
			cout << reader << endl;
			//tempNode->value = reader;
			insert(current_->value, reader);
			reader.clear();
			//tempVec.push_back(tempNode);
		}
		//current_->child = tempVec;
		//tempVec.clear();
	}

	//cout << reader << endl;
	//root.value = reader;
	//reader.clear();


	inFile.close();

}

///////////////////////////////////////////////////////////////////////////
///////////////////////FUNCTIONS FOR THE GAME//////////////////////////////
///////////////////////////////////////////////////////////////////////////

Elem& AnimalTree::randomChild(const Elem& searchVal)
{
	srand((unsigned)time(NULL));								// Start the random seed generator

	search(searchVal);											// Find the parent node

	Node* tmp;
	tmp = current_->child[rand() % current_->child.size()];		// Return a random child from the vector
	return tmp->value;											// Return the string value
}

Elem& AnimalTree::checkSiblings(const Elem& searchVal)
{
	Node* tmp;
	Elem noSiblingsLeft = "Empty";
	search(searchVal);											// Search for a node

	tmp = current_->parent;										// Then set temp to the parent of the node

	for (int i = 0; i < current_->child.size(); ++i)			// Run a loop to find another sibling.
	{															// If that sibling has already been checked
		tmp = current_->child[i];								// use that sibling.
		if (tmp->check != false)
			return tmp->value;
	}

	return noSiblingsLeft;										// Otherwise all children have been used.
}																// Go ahead and return noSiblingsLeft.		

void AnimalTree::checkBool(const Elem& searchVal)
{
	search(searchVal);											// Search for a node

	current_->check = true;										// Then change it's bool to true
}
