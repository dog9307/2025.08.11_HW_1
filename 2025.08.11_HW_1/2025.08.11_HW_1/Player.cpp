#include "Player.h"

Player::Player(string nickname)
{
}

void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* ���� �ɷ�ġ" << endl;
    cout << "�г���: " << _nickname << endl;
    cout << "Lv. "     << _level << endl;
    cout << "HP: "     << _HP << endl;
    cout << "MP: "     << _MP << endl;
    cout << "���ݷ�: " << _power << endl;
    cout << "����: " << _defence << endl;
    cout << "��Ȯ��: " << _accuracy << endl;
    cout << "�ӵ�: "   << _speed << endl;
    cout << "------------------------------------" << endl;
}

bool Player::IsAttackSuccess()
{
    int random = rand() % 100 + 1;

    return (_accuracy >= random);
}
