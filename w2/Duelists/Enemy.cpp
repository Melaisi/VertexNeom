#include "Enemy.h"

// Passes all argument to parent constructor
Enemy::Enemy(int Health, int AttackPower, int Armor, std::string Name) : 
	Character(Health, AttackPower, Armor, Name),
	RandomNumberGenerator(std::random_device{}()),Distribution(0,2)
{
}

std::string Enemy::ChooseAction()
{
	// Pass random generator to Distribution
	// Distribution return int between 0 and 2
	int Input = Distribution(RandomNumberGenerator);

	return GetActionFromInput(Input);
}

void Enemy::IncreaseDifficulty(int RoundNumber)
{
	// Increase difficulty based on current round number
	// BUG: Without Break statment we all the cases will be executed resulting on having 
	// a Knight Champion type. With break statement we limit the execution to the spacific case.

	switch (RoundNumber)
	{
	case 1:
		break;
	case 2:
		Health += RoundNumber;
		Name = "Goblin Warrior";
		break;
	case 3:
		Health += RoundNumber;
		AttackPower += RoundNumber;
		Name = "Gladiator";
		break;
	case 4:
		Health += RoundNumber;
		AttackPower += RoundNumber;
		Name = "Berserker";
		break;
	case 5:
		Health += RoundNumber;
		AttackPower += RoundNumber;
		Armor += RoundNumber/2;
		Name = "Knight Champion";
		break;
	}
}
