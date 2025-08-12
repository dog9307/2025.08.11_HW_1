#include "Thief.h"

#include "Monster.h"

Thief::Thief(string nickname)
{
	_job_name = "����";
	_nickname = nickname;
	_level = 1;
	_HP = 60;
	_MP = 80;
	_power = 15;
	_defence = 5;
	_accuracy = 100;
	_speed = 12;
}

void Thief::Attack()
{
	cout << _nickname << "��(��) �ܰ����� �񷶴�." << endl;
}

void Thief::Attack(Monster* monster)
{
	Attack();

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	int damageSum = 0;
	int atkCount = 5;
	for (int i = 0; i < atkCount; ++i)
	{
		int realDamage = damage / atkCount;
		if (realDamage <= 0) realDamage = 1;

		if (IsAttackSuccess())
		{
			cout << _nickname << "��(��) �ܰ����� �� " << monster->getName() << "���� " << realDamage << "��ŭ ���ظ� ������..!" << endl;
			damageSum += realDamage;
		}
		else
			cout << _nickname << "�� �ܰ��� ��������..!" << endl;
	}

	if (monster->setHP(monster->getHP() - damageSum))
		cout << monster->getName() << "��(��) " << monster->getHP() << "��ŭ ü���� ���Ҵ�." << endl;
	else
	{
		cout << monster->getName() << "��(��) �����߷ȴ�..!" << endl;
		cout << _nickname << "��(��) �¸��ߴ�!" << endl;
	}
}
