#include <iostream>
#include "Monster.h"
#include "Player.h"
using namespace std;

Monster::Monster(string name)
{
    this->name = name;
    this->HP = 10;
    this->power = 30;
    this->defence = 10;
    this->speed = 10;
}

void Monster::attack(Player* player)
{
    int damage = power - player->getDefence();

    if (damage <= 0)
    {
        damage = 1;
    }

    cout << name << "의 공격!" << endl;
    cout << damage << "의 데미지를 입혔다!" << endl;

    int playerHP = player->getHP() - damage;
    player->setHP(playerHP);

    if (playerHP > 0)
    {
        cout << "플레이어 남은 HP: " << playerHP << endl;
    }
    else
    {
        cout << "플레이어가 쓰러졌다!" << endl;
    }
}

string Monster::getName()
{
    return name;
}

int Monster::getHP()
{
    return HP;
}

int Monster::getPower()
{
    return power;
}

int Monster::getDefence()
{
    return defence;
}

int Monster::getSpeed()
{
    return speed;
}

void Monster::setName(string name)
{
    this->name = name;
}

void Monster::setHP(int HP)
{
    this->HP = HP;
}

void Monster::setPower(int power)
{
    this->power = power;
}

void Monster::setDefence(int defence)
{
    this->defence = defence;
}

void Monster::setSpeed(int speed)
{
    this->speed = speed;
}