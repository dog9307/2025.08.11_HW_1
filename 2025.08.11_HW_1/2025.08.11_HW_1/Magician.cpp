#include "Magician.h"

#include "Monster.h"

Magician::Magician(string nickname)
{
	_job_name = "마법사";
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
	cout << _nickname << "은(는) 마법을 사용했다." << endl;
}

void Magician::Attack(Monster* monster)
{
	Attack();
	if (!IsAttackSuccess())
	{
		cout << _nickname << "의 마법은 빗나갔다..!" << endl;
		return;
	}

	int damage = _power - monster->getDefence();
	if (damage <= 0) damage = 1;

	cout << _nickname << "은(는) 마법을 사용해 " << monster->getName() << "에게 " << damage << "만큼 피해를 입혔다..!" << endl;

	if (monster->setHP(monster->getHP() - damage))
		cout << monster->getName() << "은(는) " << monster->getHP() << "만큼 체력이 남았다." << endl;
	else
	{
		cout << monster->getName() << "을(를) 쓰러뜨렸다..!" << endl;
		cout << _nickname << "이(가) 승리했다!" << endl;
	}
}
