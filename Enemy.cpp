#include "Enemy.h"

Enemy::Enemy(int level)
{
	//Enemy stats change according to level of player
	srand(time(NULL));

	this->level = level;
	this->hpMax = rand() % 12 * sqrt(level) + 1;
	this->hp = this->hpMax;
	this->attack = this->level * 3;
	this->dropChance = rand() % 100 + 1;
	this->defence = rand() % level * 10 + 1;
	this->accuracy = rand() % level * 10 + 1;
	this->dexterity = rand() % level * 10 + 1;
	this->intelligence = rand() % level * 10 + 1;

	this->damageMax = rand() * attack * 3 + 2;
	this->damageMin = damageMax / 2;
}



void Enemy::takeDamage(int damage)
{
	//Hp changes in accordance to damage
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}