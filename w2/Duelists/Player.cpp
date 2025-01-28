#include "Player.h"
#include <iostream>

// Passes all argument to parent constructor
Player::Player(int Health, int AttackPower, int Armor, std::string Name) : Character(Health, AttackPower, Armor, Name)
{
}

std::string Player::ChooseAction()
{
	int Input;

	while (true) {
		std::cout << "______________________________________________________\n";
		std::cout << "Choose an action - (1- Attack, 2: Parry, 3: Defend) : \n";
		std::cin >> Input;

		// Input validation
		if (std::cin.fail() || Input < 1 || Input >3) { // std::cin.fail() flag will be true if input is not int.
			
			std::cin.clear(); // clear cin error state which is badbit to be goodbit
			// Ignore is needed as the input can contain new lines or spaces 
			// which might cause errors when using cin again
			// therefore we ignore all the character in the stream until we find a newline  
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //ignore characters in the input stream, typically to clear out the buffer
			std::cout << "Invalid Input you must enter 1,2 or 3 (Attack, Parry, Defend)\n";
		}
		else { // Input pass the validation, break while loop and continue the logic
			break;
		}

	}
	// Process input
	Input--; // re-map input to [0 to 1]
	return GetActionFromInput(Input);
}
