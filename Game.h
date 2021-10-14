#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Character.h"
#include "Event.h"

using namespace std;


class Game
{
public:
	Game();

	//Methods
	void startGame();
	void mainMenu();
	void travel();
	void saveCharacter();
	Character loadCharacter();

	//Encapsulators (get)
	bool getPlaying();

private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	vector<Character>character;

	//Enemies
	Enemy enemy;
	Boss boss;

};