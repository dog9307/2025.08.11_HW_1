#pragma once
#include "Player.h"

class Thief :public Player
{
public:
	Thief(string nickname);

	// Player��(��) ���� ��ӵ�
	void Attack() override;

	// Player��(��) ���� ��ӵ�
	void Attack(Monster* monster) override;
};

