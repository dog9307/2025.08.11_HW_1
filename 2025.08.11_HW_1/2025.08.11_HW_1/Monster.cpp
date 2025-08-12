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

	cout << _name << "은(는) " << player->getNickname() << "에게 " << damage << "만큼 피해를 입혔다..!" << endl;

	if (player->setHP(player->getHP() - damage))
		cout << player->getNickname() << "은(는) " << player->getHP() << "만큼 체력이 남았다." << endl;
	else
	{
		cout << player->getNickname() << "은(는) 죽어버렸다.." << endl;
		cout << _name << "이(가) 승리했다." << endl;
	}
}
