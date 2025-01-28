#pragma once
#include <string>
class Character
{
public:
	Character(int Health, int AttackPower, int Armor, std::string Name);

	int GetHealth() const { return Health; }
	std::string GetName() const { return Name; }
	bool GetIsAlive() const { return (Health > 0); }
	int GetAttackPower() const { return AttackPower; }
	void UpdateHealth(int Amount);

	virtual std::string ChooseAction() = 0;// This mean the base class doesn't need implementation if assign a method to zero.
	std::string GetActionFromInput(int Input);
	void RestoreHealth() { Health = InitialHealth; }
	void PrintStats(); // Utility method to pring health, attack power, and Armor

protected: //Allows child class access
	std::string Name;
	int Health;
	int AttackPower;
	int Armor;
	int InitialHealth;

};