// Dueling Game

#include <iostream>

#include "Player.h"
#include "Enemy.h"

// Utility function to print round information
void PrintRoundInformation(int RoundNumber, std::string HeroName, std::string EnemyName ){
	// Starting the round
	std::cout << "///////////////////////////////////\n";
	std::cout << "///// Round No. " << RoundNumber << " /////////////////\n";
	std::cout << "///// " << HeroName << " vs " << EnemyName <<" ";
	
	// Get the enemy name length and calculate how many characters to fill out
	int AmountOfCharsToFill = 20 - EnemyName.length();
	std::cout<< std::string(AmountOfCharsToFill, '/');
	std::cout << std::endl;

	std::cout << "///////////////////////////////////\n";
	
}

int main() {
	
	Player MainPlayer(5, 2, 2, "Hero");
	Enemy MainEnemy(1, 1, 0, "Goblin");

	// BUG: By initializing the round number inside the while loop we reset the round number to 1
	// This cause the loop to get stuck on round 2 and never exit.
	int RoundNumber= 1;
	
	// Starting the round print first round information 
	PrintRoundInformation(RoundNumber, MainPlayer.GetName(), MainEnemy.GetName());

	while (MainPlayer.GetIsAlive())
	{	
		
		std::string PlayerAction = MainPlayer.ChooseAction();
		std::string EnemyAction = MainEnemy.ChooseAction();

		std::cout << "\n<--------> ";
		std::cout << "Player " << PlayerAction << "s";
		std::cout << "  X  ";
		std::cout << "Enemy " << EnemyAction << "s";
		std::cout << " <-------->\n";

		// Process round logic based on actions

		if (PlayerAction == "Attack" && EnemyAction == "Attack") {
			std::cout << "Its a clash! The weapons ring as they hit each other!\n";
		}
		else if (PlayerAction == "Attack" && EnemyAction == "Parry") {
			std::cout << MainEnemy.GetName() << " Parries the attack! Oh no our hero is struck!\n";
			MainPlayer.UpdateHealth(-(MainEnemy.GetAttackPower()*2));
		}
		else if (PlayerAction == "Attack" && EnemyAction == "Defend") {
			std::cout << MainEnemy.GetName() << " Is defending! The attack is less successful!\n";
			MainEnemy.UpdateHealth(-(MainPlayer.GetAttackPower()/2));
		}
		else if (PlayerAction == "Defend" && EnemyAction == "Attack") {
			std::cout << MainPlayer.GetName() << " Is defending! The "<< MainEnemy.GetName() <<"'s attack is less successful!\n";
			MainPlayer.UpdateHealth(-(MainEnemy.GetAttackPower() / 2));
		}
		else if (PlayerAction == "Defend" && EnemyAction == "Parry") {
			std::cout << "Our hero is defending! and the enemy parries, No damage happens!\n";
		}
		else if (PlayerAction == "Defend" && EnemyAction == "Defend") {
			std::cout << "Both are defending! No damage happens! \n";
		}
		else if (PlayerAction == "Parry" && EnemyAction == "Attack") {
			std::cout << MainPlayer.GetName() << " masterfully Parries the attack! "<< MainEnemy.GetName() <<" Takes double damage!\n";
			MainEnemy.UpdateHealth(-(MainPlayer.GetAttackPower() * 2));
		}
		else if (PlayerAction == "Parry" && EnemyAction == "Defend") {
			std::cout << "Our hero parries! and the enemy defending, No damage happens!\n"; 
		}
		else if (PlayerAction == "Parry" && EnemyAction == "Parry") {
			std::cout << "Both Parries! No damage happens!\n";
		}

		// Output characters stats after a duel
		std::cout << "\n";
		MainPlayer.PrintStats();
		MainEnemy.PrintStats();
		std::cout << "\n";


		if (!MainEnemy.GetIsAlive()) {
			std::cout << MainEnemy.GetName() << " has been defeated by our Hero! A new stronger enemy appears\n";

			RoundNumber++;
			
			if (RoundNumber > 5) {

				std::cout << "Our Hero has defeated all his opponents and is now champion of the arena !!!\n";
				break;
			}
			// BUG: When we increase the difficulties the health value is not restore to its original value.
			// Can be solve by renew or restore health option. For simplicity a new character class variable
			// is introduce that maintains the initial Health value, and restore health method to make that
			// the enemy health value.
			MainEnemy.RestoreHealth();
			MainEnemy.IncreaseDifficulty(RoundNumber);

			// Print new round information
			PrintRoundInformation(RoundNumber, MainPlayer.GetName(), MainEnemy.GetName());
		}
	}

	if (!MainPlayer.GetIsAlive()) {
		std::cout << "Our Hero has perished! You must try again!\n";
	}

	std::cout << "Thanks for playing!\n";
	return 0;
}