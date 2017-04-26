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
	vector<Node>* children;
	vector<Node>& operator*() {return this;}
	const vector<Node>& operator*() const { return this;}

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
	inFile.close();
	cout << reader << endl;
	root.name = reader;
	root.parent = NULL;
	Node tempNode;
	vector<Node> tempVec;
	root.children = *tempVec;
}

void print()
{
	//print out the tree, trying to recreate the .txt file
}



int main()
{

	Node testNode;
	testNode.name = "hi";
	cout << testNode.name << endl;
	Node root;
	readIn(root);
	cout << root.name << endl;

	system("pause");
	return 0;
}
