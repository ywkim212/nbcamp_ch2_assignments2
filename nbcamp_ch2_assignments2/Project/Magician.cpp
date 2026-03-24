#include "Magician.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname)
{
	setJobName("마법사");

	setLevel(1);
	setHP(60);
	setMP(120);
	setPower(18);
	setDefence(4);
	setAccuracy(80);
	setSpeed(55);
}

void Magician::attack()
{
	cout << "파이어볼을 날립니다!" << endl;
};

void Magician::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << nickname << "의 마법 공격!" << endl;
    cout << monster->getName() << "에게 " << damage << "의 피해를 입혔다!" << endl;

    int monsterHP = monster->getHP() - damage;
    monster->setHP(monsterHP);

    if (monsterHP > 0)
        cout << monster->getName() << " 남은 HP: " << monsterHP << endl;
    else
        cout << nickname << "의 승리!" << endl;
}