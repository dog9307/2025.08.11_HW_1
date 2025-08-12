#include "Magician.h"

#include "Monster.h"

Magician::Magician(string nickname)
{
	_job_name = "������";
	_nickname = nickname;
	_level = 1;
	_HP = 50;
	_MP = 100;
	_power = 60;
	_defence = 3;
	_accuracy = 40;
	_speed = 2;
}

void Magician::Attack()
{
	cout << _nickname << "��(��) ������ ����ߴ�." << endl;
}

void Magician::Attack(Monster* monster)
{
	Attack();
	if (!IsAttackSuccess())
	{
		cout << _nickname << "�� ������ ��������..!" << endl;
		return;
	}

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	cout << _nickname << "��(��) ������ ����� " << monster->getName() << "���� " << damage << "��ŭ ���ظ� ������..!" << endl;

	if (monster->setHP(monster->getHP() - damage))
		cout << monster->getName() << "��(��) " << monster->getHP() << "��ŭ ü���� ���Ҵ�." << endl;
	else
	{
		cout << monster->getName() << "��(��) �����߷ȴ�..!" << endl;
		cout << _nickname << "��(��) �¸��ߴ�!" << endl;
	}
}
