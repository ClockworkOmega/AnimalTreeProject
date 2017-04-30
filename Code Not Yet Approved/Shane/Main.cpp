#include <iostream>
#include <string>
#include <vector>
#include "testAnimalTree.h"

using namespace std;

int main()
{
	AnimalTree tree; 
	tree.empty();
	if (tree.empty() == true)
		cout << "empty = True" << endl;
	else
		cout << "empty = False" << endl;

	tree.addRoot("works");
	tree.root();
	
	tree.isRoot();
	if (tree.isRoot() == true)
		cout << "isRoot = True" << endl;
	else
		cout << "isRoot = False" << endl;
	tree.isLeaf();
	if (tree.isLeaf() == true)
		cout << "isLeaf = True" << endl;
	else
		cout << "isLeaf = False" << endl;
	tree.currentNode();
	tree.root();
	//Node* temp = tree.root;
	//tree.searchNodeString("works", temp);
	system("pause");

	return 0;
}
