#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "AnimalTree.h"

using namespace std;

void easyQuiz(AnimalTree animals);
void mediumQuiz(AnimalTree animals);
void hardQuiz(AnimalTree animals);
void compQuestion(AnimalTree animals, int counter, string computerGuess, int numOfGuesses);

int main()
{
	AnimalTree tree;
	int difficulty;
	//tree.addRoot("Cat");
	//tree.readIn(tree.root());

	// Game Number 1 - Computer Guesses

	cout << "Welcome to the tree guessing game!\n\n";

	cout << "For the first part of the game the computer \n"
		 << "will try to guess the node of your choice.\n\n";

	cout << "Which difficulty do you want "
		 << "the game to be for the computer?\n\n";

	do {
		cout << "For Easy input 1, for Medium input 2, "
			 << "for Hard input 3: ";
		cin >> difficulty;
	} while (difficulty < 1 || difficulty > 3);
		
	if (difficulty == 1)
		easyQuiz(tree);
	else if (difficulty = 2)
		mediumQuiz(tree);
	else
		hardQuiz(tree);

	// Reset the tree
	// either erase and recreate it
	// or set all bools back to false

	////////////////////////////////
	////////////////////////////////
	////////////////////////////////

	// Game Number 2 - User Guesses



	system("pause");

	return 0;
}

// Easy quiz with fourteen guesses for the computer
void easyQuiz(AnimalTree animals)
{
	int counter = 0;
	const int NUM_OF_GUESSES = 14;
	
	compQuestion(animals, counter, animals.root(), NUM_OF_GUESSES);
}

// Medium quiz with ten guesses for the computer
void mediumQuiz(AnimalTree animals)
{
	int counter = 0;
	const int NUM_OF_GUESSES = 10;

	compQuestion(animals, counter, animals.root(), NUM_OF_GUESSES);
}

// Hard quiz with seven guesses for the computer
void hardQuiz(AnimalTree animals)
{
	int counter = 0;
	const int NUM_OF_GUESSES = 7;

	compQuestion(animals, counter, animals.root(), NUM_OF_GUESSES);
}

// 
void compQuestion(AnimalTree animals, int counter, string computerGuess, int numOfGuesses)
{
	string userAnswer;

	if (computerGuess == "Empty")			// If the user runs out of node siblings, end the game
	{
		cout << "There are no other categories to choose from.\n\n"
			 << "There's no possible way to guess your answer.\n\n";
	}
	else if (counter == numOfGuesses)		// If the computer runs out of guesses, end the game
	{
		cout << "The computer has run out of guesses "
			 << " and lost the game. You win!\n\n";
	}
	else
	{
		// Ask the user yes or no on the computer quess
		do {
			cout << "Is it a " << computerGuess << "?\n\n";
			cin >> userAnswer;
		} while (userAnswer != "Yes" || userAnswer != "yes" ||
			userAnswer != "No" || userAnswer != "no");

		// If the computer guesses right and it's the final answer then it wins
		if (userAnswer == "Yes" || userAnswer == "yes" && animals.isLeaf(computerGuess) == true)
		{
			cout << "The computer has guessed your answer and it won!\n\n";
		}
		// Else if it's right continue to the children of that node
		else if (userAnswer == "Yes" || userAnswer == "yes")
		{
			counter++;
			compQuestion(animals, counter, animals.randomChild(computerGuess), numOfGuesses);
		}
		else  // Else if the user says no then check a sibling of the guess
		{
			animals.checkBool(computerGuess);
			counter++;
			compQuestion(animals, counter, animals.checkSiblings(computerGuess), numOfGuesses);
		}
	}
}
