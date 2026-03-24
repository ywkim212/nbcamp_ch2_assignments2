#include "Thief.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
	setJobName("도둑");

	setLevel(1);
	setHP(70);
	setMP(40);
	setPower(11);
	setDefence(5);
	setAccuracy(90);
	setSpeed(90);
}

void Thief::attack()
{
	cout << "검을 찌릅니다!" << endl;
}

void Thief::attack(Monster* monster)
{
    cout << nickname << "의 연속 공격!" << endl;

    int totalDamage = 0;

    for (int i = 0; i < 5; i++)
    {
        int hitDamage = (power / 5) - monster->getDefence();

        if (hitDamage <= 0)
            hitDamage = 1;

        cout << monster->getName()
            << "에게 "
            << hitDamage
            << "의 피해를 입혔다!" << endl;

        totalDamage += hitDamage;
    }

    int monsterHP = monster->getHP() - totalDamage;
    monster->setHP(monsterHP);

    if (monsterHP > 0)
        cout << monster->getName() << " 남은 HP: " << monsterHP << endl;
    else
        cout << nickname << "의 승리!" << endl;
}