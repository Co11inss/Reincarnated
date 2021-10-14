#pragma once
#include <string>
#include "Character.h"

using namespace std;

class Enemy
{
public:

	Enemy(int level = 1);
	

	inline bool isAlive() { return this->hp > 0; }
	void takeDamage(int damage);

	inline int getLevel()const { return this->level; };
	inline int getAttack()const { return this->attack; };
	inline int getDamageMax()const { return this->damageMax; };
	inline int getDamageMin()const { return this->damageMin; };

	inline int getExp()const { return this->level * 100; }
	inline int getHp()const { return this->hp; }
	inline int getHpMax()const { return this->hpMax; }
	inline int getDefence()const { return this->defence; }
	inline int getAccuracy()const { return this->accuracy; }
	inline int getDexterity()const { return this->dexterity; }
	inline int getIntelligence()const { return this->intelligence; };
	inline int getDamage()const { return this->damage; };

private:

	int level;
	int hp;
	int hpMax;

	int attack; 
	int damageMax;
	int damageMin;
	int damage;

	float dropChance;
	int defence;
	int accuracy;
	int dexterity;
	int intelligence;
};

