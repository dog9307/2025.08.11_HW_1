#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string nickname);

	// Player��(��) ���� ��ӵ�
	void Attack() override;

	// Player��(��) ���� ��ӵ�
	void Attack(Monster* monster) override;
};

