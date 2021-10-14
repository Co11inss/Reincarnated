// Reincarnated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "Game.h"


using namespace std;

int main()
{
	srand(time(NULL));
	Game game;
	game.startGame();

	while (game.getPlaying())
	{
		game.mainMenu();

	}
	return 0;
}