#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(string nickname);

	// Player��(��) ���� ��ӵ�
	void Attack() override;

	// Player��(��) ���� ��ӵ�
	void Attack(Monster* monster) override;
};

