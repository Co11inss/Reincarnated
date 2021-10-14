#include <iomanip>
#include "Character.h"

Character::Character()
{
	distanceTravelled = 0;

	name = "None";
	level = 1;
	exp = 0;
	expNext = 0;
	hp = 0;
	hpMax = 0;
	damageMin = 0;
	damageMax = 0;

	defence = 0;
	attack = 0;
	intelligence = 0;
	vitality = 0;
	dexterity = 0;
	accuracy = 0;
}

Character::Character(int distanceTravelled, int gold, string name, int level,
	int exp, int vitality,
	int defence, int attack, int intelligence,
	int dexterity, int accuracy, int hp, int hpMax)
{
	//Creates character
	srand(time(NULL));
	this->distanceTravelled = distanceTravelled;
	this->gold = gold;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->vitality = vitality;
	this->defence = defence;
	this->attack = attack;
	this->intelligence = intelligence;
	this->dexterity = dexterity;
	this->accuracy = accuracy;
	this->hp = hp;
	this->hpMax = hpMax;

	this->damageMax = rand() * attack * 15 + 1;
	this->damageMin = damageMax / 2;
	
}

void Character::load(int distanceTravelled, int gold, string name, int level,
	int exp, int vitality,
	int defence, int attack, int intelligence,
	int dexterity, int accuracy, int hp, int hpMax)
{
	//Used to load character
	srand(time(NULL));

	this->distanceTravelled = distanceTravelled;
	this->gold = gold;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->vitality = vitality;
	this->defence = defence;
	this->attack = attack;
	this->intelligence = intelligence;
	this->dexterity = dexterity;
	this->accuracy = accuracy;
	this->hp = hp;
	this->hpMax = hpMax;

	this->damageMax = rand() * attack * 15 + 1;
	this->damageMin = damageMax / 2;
	
}


void Character::initial(string name)
{
	//Initialises character
	srand(time(NULL));

	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 50 * (level ^ 2) - (50 * level);
	this->hp = 20;
	this->hpMax = 20;
	
	this->defence = rand() % 15 + 5;
	this->attack = rand() % 15 + 5;
	this->intelligence = rand() % 15 + 5;
	this->vitality = rand() % 15 + 5;
	this->dexterity = rand() % 15 + 5;
	this->accuracy = rand() % 15 + 5;

	this->damageMax = rand() * attack * 15 + 1;
	this->damageMin = damageMax / 2;
	

}


void Character::characterSheet()
{
	//Character stats are shown
	cout << "= Character Sheet = " << endl;
	cout << "= Name: " << name << endl;
	cout << "= Level: " << level << endl;
	cout << "= Distance Travelled: " << distanceTravelled << " km" << endl;
	cout << "= Exp: " << exp << endl;
	cout << "= Exp to next level: " << expNext << endl;
	cout << setw(10) << setfill('=') << endl;
	cout << "= Attack: " << attack << endl;
	cout << "= Vitality: " << vitality << endl;
	cout << "= Dexterity: " << dexterity << endl;
	cout << "= Intelligence: " << intelligence << endl;
	cout << "= Defence: " << defence << endl;
	cout << "= Accuracy: " << accuracy << endl;
	cout << setw(10) << setfill('=') << endl;
	cout << "= HP " << hp << "/" << hpMax << endl;
	cout << endl;


}

void Character::levelUp()
{
	//Level goes up by 1
	if (this->exp >= this->expNext)
	{
		level++;
		this->exp = 0;
		this->expNext = 50 * (level ^ 2) - (50 * level);

		cout << "YOU ARE NOW LEVEL: " << this->level << "!" << endl;
	}
	else
	{
	cout << "NOT ENOUGH EXP!" << endl;
	}
}
	
void Character::updateStats()
{
	//Character stats are updates
	this->expNext = 50 * (level ^ 2) - (50 * level);

	this->hpMax = this->vitality + this->attack + this->level;

	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2) + this->intelligence;
	this->dexterity = this->dexterity + 5;
	this->intelligence = this->intelligence + 5;
	this->accuracy = this->accuracy + 5;
	this->attack = this->attack + 5;
	this->vitality = this->vitality + 5;


	this->hp = this->hpMax;
}


void Character::takeDamage(const int damage)
{
	//Changes Hp in accordance to damage
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

string Character::getAsString()
{
	return (this->name) + "\n" +
		to_string(this->level) + "\n" +
		to_string(this->distanceTravelled) + "\n" +
		to_string(this->exp) + "\n" +
		to_string(this->attack) + "\n" +
		to_string(this->vitality) + "\n" +
		to_string(this->dexterity) + "\n" +
		to_string(this->intelligence) + "\n" +
		to_string(this->defence) + "\n" +
		to_string(this->accuracy) + "\n" +
		to_string(this->hp) + "\n" +
		to_string(this->hpMax) + "\n" +
		to_string(this->gold) + "\n";
}