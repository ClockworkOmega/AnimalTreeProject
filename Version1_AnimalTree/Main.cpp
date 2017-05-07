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
Elem randomNode(AnimalTree animals);
void quizTwo(AnimalTree animals);

int main()
{
	srand((unsigned)time(NULL));

	
	AnimalTree tree;
	int difficulty;
	int counter = 0;
	tree.readIn();

	// Game Number 1 - Computer Guesses

	cout << "Quiz Game - Part One\n\n";

	cout << "Welcome to the tree guessing game!\n\n";

	cout << "For the first part of the game the computer \n"
		<< "will try to guess the node of your choice.\n\n";

	cout << "For easy mode type 1.\n"
		<< "(The computer has the most number of guesses)\n\n"
		<< "For intermediate mode type 2.\n"
		<< "(The computer has a moderate number of guesses)\n\n"
		<< "For hard mode type 3.\n"
		<< "(The computer has the least number of guesses)\n\n";

	do {
		cout << "Which difficulty do you want "
			<< "the game to be for the computer? ";
		cin >> difficulty;
	} while (difficulty != 1 && difficulty != 2 && difficulty != 3);

	cout << endl << endl;

	if (difficulty == 1)
		easyQuiz(tree);
	else if (difficulty == 2)
		mediumQuiz(tree);
	else
		hardQuiz(tree);

	cout << endl << endl;

	////////////////////////////////
	////////////////////////////////
	////////////////////////////////

	// Game Number 2 - User Guesses

	cout << "Quiz Game - Part Two\n\n";

	quizTwo(tree);

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

// Question function for the first quiz
void compQuestion(AnimalTree animals, int counter, string computerGuess, int numOfGuesses)
{
	string userAnswer;

	if (computerGuess == "Empty")			// If the user runs out of node siblings, end the game
	{
		cout << endl << endl;
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
			cout << "Is it a " << computerGuess << "? ";
			cin >> userAnswer;
		} while (userAnswer != "Yes" && userAnswer != "yes" &&
			userAnswer != "No" && userAnswer != "no");

		// If the computer guesses right and it's the final answer then it wins
		if ((userAnswer == "Yes" && animals.isLeaf(computerGuess) == true) ||
			(userAnswer == "yes" && animals.isLeaf(computerGuess) == true))
		{
			cout << endl << endl;
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

// Searches for a random node that's not the root or a leaf
Elem randomNode(AnimalTree animals)
{
	srand((unsigned)time(NULL));
	Elem compAnswer;

	
	do {
		animals.searchInt(rand() % animals.size());		// Sets current to a random node
		compAnswer = animals.currentVal();				// Create a holder for random node
	} while (animals.isRoot(compAnswer) != true && animals.isLeaf(compAnswer) != false);

	return compAnswer;
}

// Function for quiz two
void quizTwo(AnimalTree animals)
{ 
	srand((unsigned)time(NULL));					// Start the random number generator

	string userGuess;
	Elem compAnswer;
	Elem randomAnswer;
	compAnswer = randomNode(animals);

	cout << "Welcome to part two of the guessing game." << endl;
	cout << "The computer will pick an animal at random and ask you five \n"
		 << "questions about it. If you get all five questions \n"
		 << "right then you win. Let's begin.\n\n";

	// Question One //

	do { 
		cout << "Question #1: Is a " << compAnswer << " a subtype of " << animals.parentVal(compAnswer) << "? ";
		cin >> userGuess;
	} while (userGuess != "Yes" && userGuess != "yes" &&
					userGuess != "No" && userGuess != "no");


	if (userGuess == "No" || userGuess == "no")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}

	// Question Two //

	

	do {
		cout << "Question #2: Is a " << animals.randomChild(compAnswer) << " a subtype of " << compAnswer << "? ";
		cin >> userGuess;
	} while (userGuess != "Yes" && userGuess != "yes" &&
		userGuess != "No" && userGuess != "no");

	if (userGuess == "No" || userGuess == "no")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}

	// Question Three //
	randomAnswer = randomNode(animals);

	do {
		cout << "Question #3: Is a " << compAnswer << " a subtype of " << randomAnswer << "? ";
		cin >> userGuess;
	} while (userGuess != "Yes" && userGuess != "yes" &&
		userGuess != "No" && userGuess != "no");

	if (animals.parentVal(compAnswer) == randomAnswer && userGuess == "No" || 
			animals.parentVal(compAnswer) == randomAnswer && userGuess == "no")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}
	else if (animals.parentVal(compAnswer) != randomAnswer && userGuess == "yes" ||
		animals.parentVal(compAnswer) != randomAnswer && userGuess == "yes")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}

	// Question Four //

	randomAnswer = randomNode(animals);

	do {
		cout << "Question #4: Is a " << randomAnswer << " a subtype of " << compAnswer  << "? ";
		cin >> userGuess;
	} while (userGuess != "Yes" && userGuess != "yes" &&
		userGuess != "No" && userGuess != "no");

	if (animals.parentVal(randomAnswer) == compAnswer && userGuess == "No" ||
		animals.parentVal(randomAnswer) == compAnswer && userGuess == "no")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}
	else if (animals.parentVal(randomAnswer) != compAnswer && userGuess == "yes" ||
		animals.parentVal(randomAnswer) != compAnswer && userGuess == "yes")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}

	// Question Five //

	randomAnswer = randomNode(animals);

	do {
		cout << "Question #5: Is a " << randomAnswer << " a sibling of " << compAnswer << "? ";
		cin >> userGuess;
	} while (userGuess != "Yes" && userGuess != "yes" &&
		userGuess != "No" && userGuess != "no");

	if (animals.isSibling(randomAnswer, compAnswer) == true && userGuess == "No" ||
			animals.isSibling(randomAnswer, compAnswer) == true && userGuess == "no")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}
	else if (animals.isSibling(randomAnswer, compAnswer) == false && userGuess == "yes" ||
		animals.isSibling(randomAnswer, compAnswer) == false && userGuess == "yes")
	{
		cout << "Sorry your last answer was wrong. Try again.\n\n";
		return;
	}

	cout << endl << endl;

	cout << "Congrats you have won the game! Congratulations!\n\n";
}

