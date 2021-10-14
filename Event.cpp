#include "Event.h"



int Event::nrOfEvents = 3;

Event::Event()
{

}

void Event::generateEvent(Character &character, Enemy& enemy, Boss& boss)
{
	//Randomly chooses between Enemy encounter and Boss encounter
	
	srand(time(NULL));

	int i = rand() % Event::nrOfEvents + 1 ;

	switch (i)
	{
	case 1:
		//Enemy encounter
		this->enemyEncounter(character, enemy);
		break;

	case 2:
		//Boss
		cout << "You have encountered a boss\n\n";
		cout << "Press ENTER to continue...\n\n";
		cin.get();
		this->bossEncounter(character, boss);
		break;

	case 3:
		//Enemy encounter
		this->enemyEncounter(character, enemy);
		break;

	default:
		break;

	}
}


void Event::enemyEncounter(Character& character, Enemy& enemies)
{
	//Encounter with enemy

	srand(time(NULL));

	Game game;

	bool playerTurn = false;
	int choice = 0;

	//Coin toss for turn
	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
		playerTurn = true;
	else
		playerTurn = false;

	//End conditions
	bool runAway = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;

	Enemy enemy(character.getLevel());

	//Battle variables
	int damage = 0;
	int totalDamage = 0;
	int finalDamage = 0;
	int gainExp = 0;
	int gainGold = 0;
	int playerDice = 0;
	int enemyDice = 0;
	

	while (!runAway && !playerDefeated && !enemyDefeated)
	{
		
		bool playerDefeated = false;
		bool enemyDefeated = false;

		if (playerTurn && !playerDefeated)
			{
				//Menu
				

				cout << "= PLAYER TURN =" << "\n\n";
				cout << "Press enter to continue..." << "\n\n";
				cin.get();
				system("CLS");

				cout << "= ATTACK MENU =" << "\n\n";
				cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

				cout << "1. Attack" << endl;
				cout << "2. Defend" << endl;
				cout << "3. Run" << endl;

				cout << endl;

				cout << "Choice: ";

				cin >> choice;

				//Error message
				while (cin.fail() || choice > 3 || choice < 0)
				{
					system("CLS");

					cout << "That is not one of the choices" << endl;
					cin.clear();
					cin.ignore();

					cout << "= ATTACK MENU =" << "\n\n";
					cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

					cout << "1. Attack" << endl;
					cout << "2. Defend" << endl;
					cout << "3. Run" << endl;

					cout << endl;

					cout << "Choice: ";

					cin >> choice;
				}
				cin.ignore();
				cout << endl;

				switch (choice)
				{
				case 1:
					//ATTACK
					cout << "Level: " << enemy.getLevel() << endl;
					cout << "HP: " << enemy.getHp() << "/" << enemy.getHpMax() << endl;
					cout << "Defence: " << enemy.getDefence() << endl;

					//Attack roll

					enemyDice = rand() % enemy.getDexterity() + 1;
					playerDice = rand() % character.getAccuracy() + 1;


					cout << "Enemy rolled: " << enemyDice << " on Dexterity" << endl;
					cout << "Player rolled: " << playerDice << " on Accuracy" << endl;

					//Player attack successful
					if (playerDice > enemyDice)
					{
						cout << "The attack HIT!" << "\n\n";

						damage = rand() % character.getDamageMax() + character.getDamageMin();
						totalDamage = (damage * character.getIntelligence()) / enemy.getDefence();
						finalDamage = totalDamage / 1000000;

						enemy.takeDamage(finalDamage);
						
						cout << "Damage: " << finalDamage << "!" << "\n\n";

						//Enemy Defeated
						if (!enemy.isAlive())
						{
							cout << "ENEMY DEFEATED!" << "\n\n";
							gainExp = enemy.getExp();
							character.gainExp(gainExp);
							gainGold = rand() % enemy.getLevel() * 10 + 1;
							character.gainGold(gainGold);
							cout << "EXP GAINED: " << gainExp << endl;
							cout << "GOLD GAINED: " << gainGold << "\n\n";

							if (character.getExp() >= character.getExpNext())
							{
								cout << "YOU HAVE LEVELLED UP!\n\n";
								character.levelUp();
								character.updateStats();
							}

							enemyDefeated = true;
							

						}

					}
					else
						//MISSED
					{
						cout << "The enemy DODGED!" << "\n\n";
						break;

					}
					break;
				case 2:
					cout << "You DEFENDED the attack!\n\n";
					playerTurn = true;
					continue;

				case 3:
					//RUN
					runAway = true;
					cout << "You escaped successfully!" << "\n\n";
					break;

				}
				//End player turn
				playerTurn = false;
			}
		else if (!playerTurn && !playerDefeated && !runAway && !enemyDefeated)
			{
				cout << "= ENEMY TURN =" << endl;

				cout << "Press Enter to continue..." << "\n\n";
				cin.get();
				system("CLS");

				playerDice = rand() % character.getDexterity() + 1;
				enemyDice = rand() % enemy.getAccuracy() + 1;


				cout << "Player rolled: " << playerDice << " on Dexterity" << endl;
				cout << "Enemy rolled: " << enemyDice << " on Accuracy" << endl;

				if (playerDice < enemyDice)
				{
					cout << "You got HIT!" << "\n\n";

					damage = rand() % enemy.getDamageMax() + enemy.getDamageMin();
					
					totalDamage = (damage * enemy.getIntelligence()) / character.getDefence();
					finalDamage = damage / 1000000;

					character.takeDamage(finalDamage);

					cout << "Damage: " << finalDamage << "!" << "\n\n";
					cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

					if (!character.isAlive())
					{
						cout << "YOU HAVE BEEN DEFEATED!" << "\n\n";
						playerDefeated = true;
						game.startGame();
						break;
					}
					
				}
				else
				{
					cout << "You DODGED!" << "\n\n";

				}
				//End enemy turn
				playerTurn = true;
			}
		if (!character.isAlive())
			{
				playerDefeated = true;
				
			}
		else if (!enemy.isAlive())
		{
			enemyDefeated = true;
		}
		
	}
}

//Boss encounter
void Event::bossEncounter(Character& character, Boss &bosses)
{
	srand(time(NULL));

	bool playerTurn = true;
	int choice = 0;

	Game game;
	
	//End conditions
	bool runAway = false;
	bool playerDefeated = false;
	bool bossDefeated = false;

	Boss boss;

	//Battle variables
	int damage = 0;
	int totalDamage = 0;
	int finalDamage = 0;
	int gainExp = 0;
	int gainGold = 0;
	int playerDice = 0;
	int bossDice = 0;


	while (!runAway && !playerDefeated && !bossDefeated)
	{
		
			
		bool playerDefeated = false;
		bool bossDefeated = false;

		if (playerTurn && !playerDefeated)
			{
				//Menu
				//Clear screen

				cout << "= PLAYER TURN =" << "\n\n";
				cout << "Press enter to continue..." << "\n\n";
				cin.get();
				system("CLS");

				cout << "= ATTACK MENU =" << "\n\n";
				cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

				cout << "1. Attack" << endl;
				cout << "2. Defend" << endl;
				cout << "3. Run" << endl;

				cout << endl;

				cout << "Choice: ";

				cin >> choice;

				while (cin.fail() || choice > 3 || choice < 0)
				{
					system("CLS");

					cout << "That is not one of the choices" << endl;
					cin.clear();
					cin.ignore();

					cout << "= ATTACK MENU =" << "\n\n";
					cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

					cout << "1. Attack" << endl;
					cout << "2. Defend" << endl;
					cout << "3. Run" << endl;

					cout << endl;

					cout << "Choice: ";

					cin >> choice;
				}
				cin.ignore();
				cout << endl;

				switch (choice)
				{
				case 1:
					//ATTACK
					cout << "Level: " << boss.getLevel() << endl;
					cout << "HP: " << boss.getHp() << "/" << boss.getHpMax() << endl;
					cout << "Defence: " << boss.getDefence() << endl;

					//Attack roll

					bossDice = rand() % boss.getDexterity() + 1;
					playerDice = rand() % character.getAccuracy() + 1;


					cout << "Enemy rolled: " << bossDice << " on Dexterity" << endl;
					cout << "Player rolled: " << playerDice << " on Accuracy" << endl;


					if (playerDice > bossDice)
					{
						cout << "The attack HIT!" << "\n\n";

						damage = rand() % character.getDamageMax() + character.getDamageMin();
						totalDamage = (damage * character.getIntelligence()) / boss.getDefence();
						finalDamage = totalDamage / 1000000;

						boss.takeDamage(finalDamage);
						
						cout << "Damage: " << finalDamage << "!" << "\n\n";


						if (!boss.isAlive())
						{
							cout << "ENEMY DEFEATED!" << "\n\n";
							gainExp = boss.getExp();
							character.gainExp(gainExp);
							gainGold = rand() % boss.getLevel() * 10 + 1;
							character.gainGold(gainGold);
							cout << "EXP GAINED: " << gainExp << endl;
							cout << "GOLD GAINED: " << gainGold << "\n\n";

		

							
							bossDefeated = true;
							
						}

					}
					else
						//MISSED
					{
						cout << "The boss DODGED!" << "\n\n";
						break;

					}
					break;
				case 2:
					cout << "You have DEFENDED the attack!\n\n";
					playerTurn = true;
					continue;

				case 3:
					//RUN
					runAway = true;
					cout << "You escaped successfully!" << "\n\n";
					break;

				}
				//End player turn
				playerTurn = false;
			}
		else if (!playerTurn && !playerDefeated && !runAway && !bossDefeated)
			{
				cout << "= ENEMY TURN =" << endl;

				cout << "Press Enter to continue..." << "\n\n";
				cin.get();
				system("CLS");

				playerDice = rand() % character.getDexterity() + 1;
				bossDice = rand() % boss.getAccuracy() + 1;


				cout << "Player rolled: " << playerDice << " on Dexterity" << endl;
				cout << "Enemy rolled: " << bossDice << " on Accuracy" << endl;

				if (playerDice < bossDice)
				{
					cout << "You got HIT!" << "\n\n";

					damage = rand() % boss.getDamageMax() + boss.getDamageMin();
					
					totalDamage = (damage * boss.getIntelligence()) / character.getDefence();
					finalDamage = damage / 1000000;

					character.takeDamage(finalDamage);

					cout << "Damage: " << finalDamage << "!" << "\n\n";
					cout << "HP: " << character.getHp() << "/" << character.getHpMax() << "\n\n";

					if (!character.isAlive())
					{
						cout << "YOU HAVE BEEN DEFEATED!" << "\n\n";
						playerDefeated = true;
						
						game.startGame();
						break;
					}
					//break;
				}
				else
				{
					cout << "You DODGED!" << "\n\n";

				}
				//End boss turn
				playerTurn = true;
			}
		if (!character.isAlive())
			{
				playerDefeated = true;
				

			}
		else if (!boss.isAlive())
			{
				bossDefeated = true;
			}
		
	}
}



