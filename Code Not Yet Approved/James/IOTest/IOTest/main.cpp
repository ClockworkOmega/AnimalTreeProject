#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//read in string up to : as parent
//read in strings folowing : as children in the vector<node>
//when a , is reached, start a new child.
//if at end of line, start a new parent.
//before starting a new parent, check the tree to see if it already exists as a child.
//if not already a child, it must be a root.

struct Node
{
	string name;
	Node* parent;
	vector<Node*> children;
};

void readIn(Node& root)
{
	//start by reading unitl :
	//check the string toUpper compared to each Node.name toUpper
	//if there is a match, add to that Node's vector. Else, the new string must be the root.
	//put the string up to : as the Node.name
	//put each string following the : as an individual Node, each string seperated by the ,
	//once "\0" is reached, insert the the last string and stop reading that line.

	fstream inFile;
	inFile.open("txtTest.txt");

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
	root.name = reader;
	root.parent = NULL;
	vector<Node*> tempVec;
	reader.clear();


	while (inFile.good() && mine != '\n')
	{
		Node* tempNode = new Node;
		tempNode->parent = &root;
		inFile.get(mine);
		inFile.get(mine);
		while (inFile.good() && mine != ',' && mine != '\n')
		{	
			reader = reader + mine;
			inFile.get(mine);	
		}

		tempNode->name = reader;
		cout << reader << endl;
		cout << tempNode->name << endl;
		reader.clear();
		tempVec.push_back(tempNode);
	}
	inFile.close();
	root.children = tempVec;
	cout << root.children[0]->parent << endl;
}

void print()
{
	//print out the tree, trying to recreate the .txt file
}



int main()
{
	Node root;
	readIn(root);
	cout << root.name << endl;
	cout << &root << endl;
	cout << root.children[0]->name << endl;

	system("pause");
	return 0;
}
