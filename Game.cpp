#include "Game.h"



Game::Game()
{
	choice = 0;
	playing = true;
}

bool Game::getPlaying()
{
	return playing;
}

void Game::startGame()
{
	//Prompts to create a new character by asking for a name after
	//instructions are shown

	cout << "Welcome to Reincarnated." << endl;
	cout << "In this game, you have been reincarnated into a new world full of enemies and bosses" << endl;
	cout << "You will have to travel through this world and become stronger so you can take down the bosses" << endl;
	cout << "All bosses have all of their stats at 100 so don't think you can face one straight away." << "\n\n";
	
	cout << "NOTE: Due to errors, when you defeat an enemy, choose the 'Run' option in your next turn" << endl;
	cout << "You will still gain the exp!" << "\n\n";
	
	string name;
	cout << "Enter name for your character: ";
	getline(cin, name);
	cout << endl;

	character.push_back(Character());
	activeCharacter = character.size() - 1;
	character[activeCharacter].initial(name);

	
}



void Game::mainMenu()
{
	cout << "= MAIN MENU =" << "\n\n";
	cout << "0. Quit" << endl;
	cout << "1. Character Sheet" << endl;
	cout << "2. Travel" << endl;
	cout << "3. Save character" << endl;
	cout << "4. Load character" << endl;
	cout << "5. Rest" << endl;
	cout << endl;

	cout << "Choice: ";
	cin >> choice;
	cout << endl;


	switch (choice)
	{
	case 0:
		playing = false;
		break;

	case 1:
		character[activeCharacter].characterSheet();
		break;

	case 2:
		travel();
		break;

	case 3:
		saveCharacter();
		break;

	case 4:
		loadCharacter();
		break;

	case 5:
		character[activeCharacter].resetHP();
		cout << "Your HP has been fully healed!\n\n";
		break;


	}
}

void Game::travel()
{
	//Causes the distanceTravelled to increase by 1 and generates an enemy or boss encounter
	this->character[activeCharacter].travel();

	Event event;

	event.generateEvent(this->character[activeCharacter], this->enemy, this->boss);
}


void Game::saveCharacter()
{
	ofstream aFile("savedCharacter.txt");
	aFile << character[activeCharacter].getAsString();
	aFile.close();
	cout << "Your character has been saved!" << "\n\n";
}

Character Game::loadCharacter()
{
	ifstream inFile("savedCharacter.txt");
	if (!inFile)
	{
		cout << "The file does not exist";
	}
	else
	{
		string name;
		int level;
		int distanceTravelled;
		int exp;
		int attack;
		int vitality;
		int dexterity;
		int intelligence;
		int defence;
		int accuracy;
		int hp;
		int hpMax;
		int gold;

		
		inFile >> name
			>> level
			>> distanceTravelled
			>> exp
			>> attack
			>> vitality
			>> dexterity
			>> intelligence
			>> defence
			>> accuracy
			>> hp
			>> hpMax
			>> gold;

		character.push_back(Character());
		activeCharacter = character.size() - 1;

		//Create character
		character[activeCharacter].load(distanceTravelled, gold, name, level,
			exp, vitality,
			defence, attack, intelligence,
			dexterity, accuracy, hp, hpMax);
		
	

		cout << "Your character has been loaded\n\n";

		inFile.close();
	}
	return character[activeCharacter];
	
}