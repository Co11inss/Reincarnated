#pragma once
#include <string>
#include "Character.h"

using namespace std;

class Boss
{
public:
	Boss();

	//Encapsulators (get)
	inline int getLevel()const { return this->level; };
	inline int getAttack()const { return this->attack; };
	inline int getDamageMax()const { return this->damageMax; };
	inline int getDamageMin()const { return this->damageMin; };
	inline int getDamage()const { return this->damage; };

	inline int getExp()const { return this->level * 97; }
	inline int getHp()const { return this->hp; }
	inline int getHpMax()const { return this->hpMax; }
	inline int getDefence()const { return this->defence; }
	inline int getAccuracy()const { return this->accuracy; }
	inline int getDexterity()const { return this->dexterity; }
	inline int getIntelligence()const { return this->intelligence; };

	//Methods
	inline bool isAlive() { return this->hp > 0; }
	void takeDamage(int damage); 

private:
	int hp;
	int hpMax;

	int attack;
	int defence;
	int intelligence;
	int dexterity;
	int accuracy;

	int damageMax;
	int damageMin;
	int damage;

	int level;
	int exp;



};

