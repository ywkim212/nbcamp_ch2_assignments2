#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname)
{
	setJobName("궁수");

	setLevel(1);
	setHP(80);
	setMP(60);
	setPower(12);
	setDefence(6);
	setAccuracy(85);
	setSpeed(75);
}

void Archer::attack()
{
	cout << "화살을 쏩니다!" << endl;
}

void Archer::attack(Monster* monster)
{
    cout << nickname << "의 화살 공격!" << endl;

    int totalDamage = 0;

    for (int i = 0; i < 3; i++)
    {
        int hitDamage = (power / 3) - monster->getDefence();

        if (hitDamage <= 0)
            hitDamage = 1;

        cout << monster->getName()
            << "에게 화살로 "
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