#include "Player.h"

Player::Player(string nickname)
{
}

void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << _nickname << endl;
    cout << "Lv. "     << _level << endl;
    cout << "HP: "     << _HP << endl;
    cout << "MP: "     << _MP << endl;
    cout << "공격력: " << _power << endl;
    cout << "방어력: " << _defence << endl;
    cout << "정확도: " << _accuracy << endl;
    cout << "속도: "   << _speed << endl;
    cout << "------------------------------------" << endl;
}

bool Player::IsAttackSuccess()
{
    int random = rand() % 100 + 1;

    return (_accuracy >= random);
}
