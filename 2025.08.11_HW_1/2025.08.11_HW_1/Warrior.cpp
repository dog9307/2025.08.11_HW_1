#include "Warrior.h"

#include "Monster.h"

Warrior::Warrior(string nickname)
{
	_job_name = "전사";
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
	cout << _nickname << "은(는) 검을 휘둘렀다." << endl;
}

void Warrior::Attack(Monster* monster)
{
	Attack();
	if (!IsAttackSuccess())
	{
		cout << _nickname << "의 검은 빗나갔다..!" << endl;
		return;
	}

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	cout << _nickname << "은(는) 검을 휘둘러 " << monster->getName() << "에게 " << damage << "만큼 피해를 입혔다..!" << endl;

	if (monster->setHP(monster->getHP() - damage))
		cout << monster->getName() << "은(는) " << monster->getHP() << "만큼 체력이 남았다." << endl;
	else
	{
		cout << monster->getName() << "을(를) 쓰러뜨렸다..!" << endl;
		cout << _nickname << "이(가) 승리했다!" << endl;
	}
}
