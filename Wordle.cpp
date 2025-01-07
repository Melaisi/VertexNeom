// Wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cctype> //std::tolower
#include <algorithm> //std::equal
#include <Windows.h> // colored output

// Return comparison between two character case insenstive. Used by std::equal
bool CharComparison(char a, char b) {
	return std::tolower(a) == std::tolower(b);
}

// Return 
bool CheckInput(std::string Input, std::string TodayWord) {
	if (Input.size() != TodayWord.size()) {
		return false;
	}
	return std::equal(Input.begin(), Input.end(), TodayWord.begin(), TodayWord.end(), CharComparison);
}

void PrintCharactersComparison(std::string InputAttempt, std::string TodayWord) {
	
	if (InputAttempt.size() != TodayWord.size()) {
		std::cout << "The word must have "<< TodayWord.size() <<" letters!\n";
		return;
	}
	for (int i = 0; i < TodayWord.size(); i++) {
		if (CharComparison(InputAttempt.at(i), TodayWord.at(i))) {
			// Green output
			std::cout << "\x1B[032m" << InputAttempt.at(i) << "\033[0m";
		}
		else {
			// Check if the letter exist in the wrong spot
			if (TodayWord.find(InputAttempt.at(i)) != std::string::npos) {
				// The letter is in another location
				std::cout << "\x1B[033m" << InputAttempt.at(i) << "\033[0m";
			}
			else {
				std::cout << "_";
			}
		}
	}
}

int main()
{
	std::cout << "Welcome to MoRdle .. You have 5 tryies to guess a 5 letters word. Goodluck!\n\n";
	std::cout << "\n-------------------------------------\n";
	std::vector<std::string> WordsList = { "plans" };

	std::string TodayWord = WordsList.at(0);

	int AttemptCounter = 1;
	int MaxAttempt = 5;
	
	std::string InputAttempt;

	for (AttemptCounter = 1; AttemptCounter <= MaxAttempt; AttemptCounter++) {
		std::cout << AttemptCounter << ".\n";
		//TODO: Make sure the letters of the words match 5
		std::cin >> InputAttempt;

		// Check Input
		if (CheckInput(InputAttempt, TodayWord)) {

			std::cout <<"\n You Got it right! You Won! \n";
			break;
		}
		else {
			//TODO: Flag the correct alphapet and if in correct order or not
			//TODO: Flag the avaliable alphabet to choose from.
			PrintCharactersComparison(InputAttempt,TodayWord);
			std::cout << "\n";
		}
		
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
