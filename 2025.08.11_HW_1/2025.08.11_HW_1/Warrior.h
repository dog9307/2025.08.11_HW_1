#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string nickname);

	// Player을(를) 통해 상속됨
	void Attack() override;

	// Player을(를) 통해 상속됨
	void Attack(Monster* monster) override;
};

