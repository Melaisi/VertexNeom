#include "Character.h"
#include <iostream>

Character::Character(int Health, int AttackPower, int Armor, std::string Name) :
	Health(Health), AttackPower(AttackPower), Armor(Armor), Name(Name), InitialHealth(Health)
{
}

void Character::UpdateHealth(int Amount)
{
	Health += Amount;
	if (Health < 0) {
		Health = 0;
	}
}

std::string Character::GetActionFromInput(int Input)
{
	switch (Input)
	{
	case 0:
		return "Attack";
	case 1:
		return "Parry";
	case 2:
		return "Defend";
	}
}

void Character::PrintStats()
{
	std::cout << "|>----\t"<<Name<<" Stats : ";
	std::cout << "\tAtk: " << AttackPower << "\tH: " << Health << "\tArmor: " << Armor << "\t|\n";
	
}
