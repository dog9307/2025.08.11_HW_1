#pragma once
#include "Player.h"

class Magician : public Player
{
public:
	Magician(string nickname);

	// Player��(��) ���� ��ӵ�
	void Attack() override;

	// Player��(��) ���� ��ӵ�
	void Attack(Monster* monster) override;
};

