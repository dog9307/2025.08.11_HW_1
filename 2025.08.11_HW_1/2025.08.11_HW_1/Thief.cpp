#include "Thief.h"

#include "Monster.h"

Thief::Thief(string nickname)
{
	_job_name = "도적";
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
	cout << _nickname << "은(는) 단검으로 찔렀다." << endl;
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
			cout << _nickname << "은(는) 단검으로 찔러 " << monster->getName() << "에게 " << realDamage << "만큼 피해를 입혔다..!" << endl;
			damageSum += realDamage;
		}
		else
			cout << _nickname << "의 단검은 빗나갔다..!" << endl;
	}

	if (monster->setHP(monster->getHP() - damageSum))
		cout << monster->getName() << "은(는) " << monster->getHP() << "만큼 체력이 남았다." << endl;
	else
	{
		cout << monster->getName() << "을(를) 쓰러뜨렸다..!" << endl;
		cout << _nickname << "이(가) 승리했다!" << endl;
	}
}
