#include <iostream>
#include <string>
#include <vector>
#include "animalTree.h"

using namespace std;

int main()
{

	AnimalTree tree;
	tree.addRoot("Cat");
	tree.readIn(tree.root());


	system("pause");

	return 0;
}