#pragma once

#include <iostream>
#include <string>
#include <time.h>



using namespace std;


class Character
{
	

public:
	Character();

	Character(int distanceTraveelled, int gold, string name, int level,
		int exp, int vitality,
		int defence, int attack, int intelligence,
		int dexterity, int accuracy, int hp, int hpMax);

	void load(int distanceTravelled, int gold, string name, int level,
		int exp, int vitality,
		int defence, int attack, int intelligence,
		int dexterity, int accuracy, int hp, int hpMax);

	//Encapsulators (get)
	int& getDistanceTravelled() { return distanceTravelled; };

	int& getGold() { return gold; };

	string& getName() { return this->name; };
	int& getLevel() { return this->level; };
	int& getExp() { return exp; };
	int& getExpNext() { return expNext; };
	int& getHp() { return hp; };
	int& getHpMax() { return hpMax; };
	int& getDamageMin() { return damageMin; };
	int& getDamageMax() { return damageMax; };
	int& getDefence() { return this->defence; };
	int& getAttack() { return attack; };
	int& getIntelligence() { return intelligence; };
	int& getDexterity() { return dexterity; };
	int& getVitality() { return vitality; };
	int& getAccuracy() { return this->accuracy; };
	int& getDamage() { return this->damage; };



	//Encapsulators (set)
	inline void setDistTravelled(const int& distance) { this->distanceTravelled = distance; }


	//Methods
	void initial(string name);
	void levelUp();
	void characterSheet();
	void updateStats();
	inline void resetHP() { this->hp = this->hpMax; }
	

	string getAsString();

	
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int exp) { this->exp += exp; }
	inline void gainGold(const int gold) { this->gold += gold; }
	inline void payGold(const int gold) { this->gold -= gold; }
	void takeDamage(const int damage);
	

	inline bool isAlive() { return this->hp > 0; }
private:

	int distanceTravelled;

	int gold;

	string name;
	int level;
	int exp;
	int expNext;
	int hp;
	int hpMax;

	int damageMin;
	int damageMax;
	int damage;

	int vitality;
	int defence;
	int attack;
	int intelligence;
	int dexterity;
	int accuracy;

};
