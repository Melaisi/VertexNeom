#pragma once
#include "Character.h"

class Player : public Character {

public:
	Player(int Health, int AttackPower, int Armor, std::string Name);
	std::string ChooseAction() override;
};