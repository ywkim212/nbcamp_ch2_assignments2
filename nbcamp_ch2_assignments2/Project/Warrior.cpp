#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname)
{
	setJobName("전사");

	setLevel(1);
	setHP(120);
	setMP(30);
	setPower(15);
	setDefence(14);
	setAccuracy(75);
	setSpeed(50);
}

void Warrior::attack()
{
	cout << "검을 휘두릅니다!" << endl;
}

void Warrior::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << nickname << "의 공격!" << endl;
    cout << monster->getName() << "에게 " << damage << "의 피해를 입혔다!" << endl;

    int monsterHP = monster->getHP() - damage;
    monster->setHP(monsterHP);

    if (monsterHP > 0)
        cout << monster->getName() << " 남은 HP: " << monsterHP << endl;
    else
        cout << nickname << "의 승리!" << endl;
}