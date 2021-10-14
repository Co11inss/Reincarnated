#include "Boss.h"
#include <stdlib.h>

Boss::Boss()
{
	//Pre-determined stats for boss

	this->level = 100;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->attack = 100;
	this->defence = 100;
	this->accuracy = 100;
	this->dexterity = 100;
	this->intelligence = 100;

	this->damageMax = rand() * attack * 15 + 5;
	this->damageMin = damageMax / 2;
}

void Boss::takeDamage(int damage)
{
	//Hp changes according to damage
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}