#pragma once

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Monster;

class Player
{
protected:
	string	_job_name;
	string	_nickname;
	int		_level;
	int		_HP;
	int		_MP;
	int		_power;
	int		_defence;
	int		_accuracy;
	int		_speed;

public:
	Player() {}
	Player(string nickname);

	virtual void Attack() = 0;
	virtual void Attack(Monster* monster) = 0;
	void printPlayerStatus();

	bool IsAttackSuccess();

	// getter 함수
	string getJobName()	{ return _job_name; }
	string getNickname(){ return _nickname; }
	int getLevel()		{ return _level; }
	int getHP()			{ return _HP; }
	int getMP()			{ return _MP; }
	int getPower()		{ return _power; }
	int getDefence()	{ return _defence; }
	int getAccuracy()	{ return _accuracy; }
	int getSpeed()		{ return _speed; }

	// setter 함수
	void setNickname(string nickname)	{ _nickname = nickname; }
	bool setHP(int HP)					{ if (HP >= 1) _HP = HP; else _HP = 0; return (_HP >= 1); }
	bool setMP(int MP)					{ if (MP >= 1) _MP = MP; else _MP = 0; return (_MP >= 1); }
	void setPower(int power)			{ _power = power; }
	void setDefence(int defence)		{ _defence = defence; }
	void setAccuracy(int accuracy)		{ _accuracy = accuracy; }
	void setSpeed(int speed)			{ _speed = speed; }
};

