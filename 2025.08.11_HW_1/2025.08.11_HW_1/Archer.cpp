#include "Archer.h"

#include "Monster.h"

Archer::Archer(string nickname)
{
	_job_name = "궁수";
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
	cout << _nickname << "은(는) 활을 쐈다." << endl;
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
			cout << _nickname << "은(는) 활을 쏴 " << monster->getName() << "에게 " << realDamage << "만큼 피해를 입혔다..!" << endl;
			damageSum += realDamage;
		}
		else
			cout << _nickname << "의 화살은 빗나갔다..!" << endl;
	}

	if (monster->setHP(monster->getHP() - damageSum))
		cout << monster->getName() << "은(는) " << monster->getHP() << "만큼 체력이 남았다." << endl;
	else
	{
		cout << monster->getName() << "을(를) 쓰러뜨렸다..!" << endl;
		cout << _nickname << "이(가) 승리했다!" << endl;
	}
}
