#include "Warrior.h"

#include "Monster.h"

Warrior::Warrior(string nickname)
{
	_job_name = "����";
	_nickname = nickname;
	_level = 1;
	_HP = 100;
	_MP = 30;
	_power = 30;
	_defence = 10;
	_accuracy = 70;
	_speed = 3;
}

void Warrior::Attack()
{
	cout << _nickname << "��(��) ���� �ֵѷ���." << endl;
}

void Warrior::Attack(Monster* monster)
{
	Attack();
	if (!IsAttackSuccess())
	{
		cout << _nickname << "�� ���� ��������..!" << endl;
		return;
	}

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	cout << _nickname << "��(��) ���� �ֵѷ� " << monster->getName() << "���� " << damage << "��ŭ ���ظ� ������..!" << endl;

	if (monster->setHP(monster->getHP() - damage))
		cout << monster->getName() << "��(��) " << monster->getHP() << "��ŭ ü���� ���Ҵ�." << endl;
	else
	{
		cout << monster->getName() << "��(��) �����߷ȴ�..!" << endl;
		cout << _nickname << "��(��) �¸��ߴ�!" << endl;
	}
}
