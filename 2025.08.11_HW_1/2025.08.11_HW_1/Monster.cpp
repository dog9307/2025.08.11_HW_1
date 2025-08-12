#include "Monster.h"

#include "Player.h"

Monster::Monster(string name)
{
	_name = name;
	_HP = 10;
	_power = 30;
	_defence = 10;
	_speed = 10;
}

void Monster::Attack(Player* player)
{
	int damage = _power - player->getDefence();
	if (damage <= 0) damage = 1;

	cout << _name << "��(��) " << player->getNickname() << "���� " << damage << "��ŭ ���ظ� ������..!" << endl;

	if (player->setHP(player->getHP() - damage))
		cout << player->getNickname() << "��(��) " << player->getHP() << "��ŭ ü���� ���Ҵ�." << endl;
	else
	{
		cout << player->getNickname() << "��(��) �׾���ȴ�.." << endl;
		cout << _name << "��(��) �¸��ߴ�." << endl;
	}
}
