#pragma once

#include <string>
using namespace std;

class Player;

class Monster
{
protected:
    string _name;
    int    _HP;
    int    _power;
    int    _defence;
    int    _speed;

public:
    Monster() {}
    Monster(string name);

    void Attack(Player* player);

    string getName()    { return _name; }
    int getHP()         { return _HP; }
    int getPower()      { return _power; }
    int getDefence()    { return _defence; }
    int getSpeed()      { return _speed; }

    void setName(string name)       { _name = name;}
    bool setHP(int HP)              { if (HP >= 1) _HP = HP; else _HP = 0; return (_HP >= 1); }
    void setPower(int power)        { _power = power;}
    void setDefence(int defence)    { _defence = defence;}
    void setSpeed(int speed)        { _speed = speed;}
};

