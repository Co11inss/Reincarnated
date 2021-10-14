#pragma once

#include <cmath>
#include <vector>
#include"Character.h"
#include"Enemy.h"
#include"Boss.h"
#include"Game.h"

using namespace std;

class Event
{

public:
	Event();
	
	//Creates one of two encounters
	void generateEvent(Character &character, Enemy& enemy, Boss& boss);

	//Encounters
	void enemyEncounter(Character &character, Enemy& enemy);
	void bossEncounter(Character &character, Boss& bosses);

	//statics
	static int nrOfEvents;

	

private:
	
};

