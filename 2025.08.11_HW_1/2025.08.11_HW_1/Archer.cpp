#include "Archer.h"

#include "Monster.h"

Archer::Archer(string nickname)
{
	_job_name = "�ü�";
	_nickname = nickname;
	_level = 1;
	_HP = 80;
	_MP = 50;
	_power = 20;
	_defence = 8;
	_accuracy = 60;
	_speed = 10;
}

void Archer::Attack()
{
	cout << _nickname << "��(��) Ȱ�� ����." << endl;
}

void Archer::Attack(Monster* monster)
{
	Attack();

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	int damageSum = 0;
	int atkCount = 3;
	for (int i = 0; i < atkCount; ++i)
	{
		int realDamage = damage / atkCount;
		if (realDamage <= 0) realDamage = 1;

		if (IsAttackSuccess())
		{
			cout << _nickname << "��(��) Ȱ�� �� " << monster->getName() << "���� " << realDamage << "��ŭ ���ظ� ������..!" << endl;
			damageSum += realDamage;
		}
		else
			cout << _nickname << "�� ȭ���� ��������..!" << endl;
	}

	if (monster->setHP(monster->getHP() - damageSum))
		cout << monster->getName() << "��(��) " << monster->getHP() << "��ŭ ü���� ���Ҵ�." << endl;
	else
	{
		cout << monster->getName() << "��(��) �����߷ȴ�..!" << endl;
		cout << _nickname << "��(��) �¸��ߴ�!" << endl;
	}
}
