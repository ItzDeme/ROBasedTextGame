#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <cctype>
#include <locale.h>
#include "player.h"

Player player1("Empty", 30, 1);
Swordsman playerClass1;
Mage playerClass2;
Archer playerClass3;
Monster monsters;

using namespace std;
int textSpeed = 65; //global variable for sleep function "speed of text"
void orb_of_choosing();
void doneChoosing();
void transition();
void maze_of_uny();
void rngMaze();
void damageCalc(int playerHP, int enemyATK);
void guessGame();
void levelTransition();
void classLevelUp();

void introduction() {
	string longIntro = "Greetings Fallen, I sense a strong aura coming from you. It's nothing I have ever felt before.";
	string longIntro2 = "You are nothing like the other Fallen I have seen before.";
	string longIntro3 = "We should take you to the orb of choosing! There you can see what powers you have.";
	string longIntro4 = "Let's go Fallen!!! ........Huh? Why do I call you Fallen?";
	string longIntro5 = "That's because you fell from the sky!.... What is your name, Fallen? ";
	for (int i = 0; i < longIntro.length(); i++) {						//loops through the string to create "slow" text
		cout << longIntro[i];
		 Sleep(textSpeed);
	}
	cout << endl;

	for (int i = 0; i < longIntro2.length(); i++) {
		cout << longIntro2[i];
		Sleep(textSpeed);
	}
	system("cls");
	for (int i = 0; i < longIntro3.length(); i++) {
		cout << longIntro3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < longIntro4.length(); i++) {
		cout << longIntro4[i];
		Sleep(textSpeed);
	}
	system("cls");
	for (int i = 0; i < longIntro5.length(); i++) {
		cout << longIntro5[i];
		Sleep(textSpeed);
	}
	
}


int main() {
	cout << "Please set your desired text speed! 1 to 2000. (1 = too fast to read, 2000 = extremely slow) 60 Recommended: ";
	cin >> textSpeed;
	system("pause");
	system("cls");
	

	//introduction();
	//string playerName;
	//cout << endl << "Type your name: ";
	//cin.ignore();
	//getline(cin, playerName);
	//player1.changeName(playerName); //creates a class of player1.
	//cout << " Come " << player1.getName() << " Let us venture to the Orb choosing! " << endl;
	//system("pause");
	//orb_of_choosing();
	//doneChoosing();
	//transition();
	
	if (player1.getHitPoints() > 0) {
		//maze_of_uny();
		classLevelUp();
	}
	else {
		cout << "Game Over" << endl;
	}
	return 0;
}




void orb_of_choosing() {
	system("cls"); //clears the console log
	cout << "** YOU ARE NOW AT THE ORB OF CHOOSING **" << endl;
	string orbText = "Place your hands on the orb and choose a class. ";
	string orbText2 = "1.Swordsman || 2.Mage || 3.Archer ";
	string orbChoice;

	for (int i = 0; i < orbText.length(); i++) {		//another looping for text
		cout << orbText[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < orbText2.length(); i++) {
		cout << orbText2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	getline(cin, orbChoice);

	string aOrbChoice;
	for (int i = 0; i < orbChoice.length(); i++) {  //loops the players choice, to make their answer lower case.
		if (isupper(orbChoice[i])) {
			aOrbChoice += _tolower(orbChoice[i]);
		}											//then outputs everything to lower
		else {
			aOrbChoice += orbChoice[i];
		}
	}

	if(aOrbChoice == "1" || aOrbChoice == "swordsman") { 
		
		system("cls");
		string swordsmanText = "You are a swordsman!";
		string swordsmanText2 = "Your grit and will power will take you far!";
		player1.playerChoiceClass(1);

		for (int i = 0; i < swordsmanText.length(); i++) {
			cout << swordsmanText[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < swordsmanText2.length(); i++) {
			cout << swordsmanText2[i];
			Sleep(textSpeed);
		}

	}
	 else if(aOrbChoice == "2" || aOrbChoice == "mage") {
		
		system("cls");
		string mageText = "You are a mage!";
		string mageText2 = "With great power comes great responsibility!";
		player1.playerChoiceClass(2);

		for (int i = 0; i < mageText.length(); i++) {
			cout << mageText[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < mageText2.length(); i++) {
			cout << mageText2[i];
			Sleep(textSpeed);
		}
		cout << endl;
	}
	 else if(aOrbChoice == "3" || aOrbChoice == "archer") {
		
		system("cls");
		string archerText = "You are an Archer!";
		string archerText2 = "Diligence and patience are your greatest attributes!";
		player1.playerChoiceClass(3);

		for (int i = 0; i < archerText.length(); i++) {
			cout << archerText[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < archerText2.length(); i++) {
			cout << archerText2[i];
			Sleep(textSpeed);
		}
		cout << endl;
	}
	 else {
		cout << "Please choose and actual class!!!!" << endl;
		cout << aOrbChoice << endl;
		system("pause");
		orb_of_choosing();
	}
	
	
}

void doneChoosing() {
	
	string done_choosing = "Now that the orb has finished choosing what your class.";
	string done_choosing2 = "You mustn't waste anymore time!";
	string done_choosing3 = "I'm sending you to the maze of unyielding do your best to complete it!";
	string done_choosing4 = "See you Fallen!... I mean ";

	for (int i = 0; i < done_choosing.length(); i++) {
		cout << done_choosing[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < done_choosing2.length(); i++) {
		cout << done_choosing2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < done_choosing3.length(); i++) {
		cout << done_choosing3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	done_choosing4 += player1.getName();
	for (int i = 0; i < done_choosing4.length(); i++) {
		cout << done_choosing4[i];
		Sleep(textSpeed);
	}
	cout << endl;
}

void rngMaze() {
	srand(time(NULL));
	int rngChoice;

	rngChoice = (rand() % 7) + 1;

	switch (rngChoice) {
	case 1:
		cout << "You've encountered a Bat!" << endl;
		monsters.batFight();
		playerClass1.swordmanBuffReset();
		playerClass2.mageBuffReset();
		playerClass3.archerBuffReset();
		monsters.ifMonsterKilled();
		system("pause");
		break;

	case 2:
		cout << "You've encountered a Goblin!" << endl;
		monsters.goblinFight();
		playerClass1.swordmanBuffReset();
		playerClass2.mageBuffReset();
		playerClass3.archerBuffReset();
		monsters.ifMonsterKilled();
		system("pause");
		break;
	case 3:
		cout << "You've encountered a Bear" << endl;
		monsters.bearFight();
		playerClass1.swordmanBuffReset();
		playerClass2.mageBuffReset();
		playerClass3.archerBuffReset();
		monsters.ifMonsterKilled();
		system("pause");
		break;
	case 4:
		cout << "You've encountered a board full of numbers." << endl;
		guessGame();
		system("pause");
		break;
	case 5:
		if (monsters.getAmountOfMonstersKilled() >= 3) {
			cout << "You've reached the exit!" << endl;
			monsters.getOutMaze();
		}
		else {
			cout << "You've stumbled across a pile of rocks." << endl;
		}
		system("pause");
		break;
	case 6:
		cout << "There's an empty space here." << endl;
		system("pause");
		break;
	case 7:
		cout << "You've come across a a statue of Freya, you have been healed." << endl;
		if (player1.getHitPoints() < 30) {
			player1.hitPointsReset();
		}
		else {
			cout << "There is not much she can do for you, you are already full HP." << endl;
		}
		system("pause");
		break;
	default:
		cout << "There is no possible way for you to be here." << endl;
		break;
	}
}

void maze_of_uny() {
	int amountMobsKilled = 0;
	string mazeChoice;
	bool outOfMaze = false;
	
	while (outOfMaze == false) {
		if (player1.getHitPoints() > 0) {
			if (amountMobsKilled > 5) {
				outOfMaze = true;
			}
			else
			{
				cout << "****************************************************" << endl;
				cout << "   *                                            *   " << endl;
				cout << "  **                                            **  " << endl;
				cout << " ***                                            *** " << endl;
				cout << "*********                                  *********" << endl;
				cout << " ***                                            *** " << endl;
				cout << "  **                                            **  " << endl;
				cout << "   *  1.Left                            2.Right *   " << endl;
				cout << "You come across two directions. which way do you go?" << endl;
				cin.ignore(2, '\n');
				cin >> mazeChoice;


				string aMazeChoice;
				for (int i = 0; i < mazeChoice.length(); i++) {  //loops the players choice, to make their answer lower case.
					if (isupper(mazeChoice[i])) {
						aMazeChoice += _tolower(mazeChoice[i]);
					}											//then outputs everything to lower
					else {
						aMazeChoice += mazeChoice[i];
					}
				}


				if (aMazeChoice == "1" || aMazeChoice == "left") {
					rngMaze();
					amountMobsKilled = monsters.getAmountOfMonstersKilled();

				}
				else if (aMazeChoice == "2" || aMazeChoice == "right") {
					rngMaze();
					amountMobsKilled = monsters.getAmountOfMonstersKilled();

				}
				else {
					cout << "Please choose a correct option." << endl;
					cout << mazeChoice << endl;
					system("pause");
				}

			}
			system("cls");

		}
		else {
			outOfMaze = true;
		}
	}
	if (player1.getHitPoints() > 0) {
		cout << "You have reached the exit of the Maze." << endl;
	}
	else {
		cout << "You have been vanquished..." << endl;
	}
	}
	


void Monster::bearFight() {
	int bearChoice;
	int bearHitPoints = 20;
	int bearATK = 4;

	cout << "You have encountered a bear! You have no choice but to fight! " << endl;

	while (bearHitPoints > 0 && player1.getHitPoints() > 0) {
		if (player1.playerChoice() == 1) {
			cout << "What would you like to do? \n 1.Attack || 2.Buff up!" << endl;
			cin.ignore(2, '\n');
			cin >> bearChoice;
			if (bearChoice == 1) {
				cout << "You lunge your sword at the bear dealing " << playerClass1.swordAttack() << " damage." << endl;
				bearHitPoints -= playerClass1.swordAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(2, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (bearChoice == 2) {
				playerClass1.swordSkill();
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}
				
			
		}
		if (player1.playerChoice() == 2) {
			cout << "What would you like to do? \n 1.Melee Attack || 2.Fire Bolt! || 3. Amp Up!" << endl;
			cin.ignore(1, '\n');
			cin >> bearChoice;
			if (bearChoice == 1) {
				cout << "You smack the bear with your staff " << playerClass2.mageAttack() << " damage." << endl;
				bearHitPoints -= playerClass2.mageAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (bearChoice == 2) {
				bearHitPoints -= playerClass2.mageFireBolt();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (bearChoice == 3) {
				playerClass2.mageSkill();
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}


		}
		if (player1.playerChoice() == 3) {
			cout << "What would you like to do? \n 1.Shoot || 2.Focus! || 3.Pull a Shadow!" << endl;
			cin.ignore(1, '\n');
			cin >> bearChoice;
			if (bearChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				bearHitPoints -= playerClass3.archerAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (bearChoice == 2) {
				playerClass3.archerFocus();
				system("pause");
				system("cls");
			}
			else if (bearChoice == 3) {
				bearHitPoints -= playerClass3.archerSkill();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void Monster::batFight() {
	int batChoice;
	int batHitPoints = 10;
	int batATK = 2;

	cout << "You have encountered a bat! You have no choice but to fight! " << endl;

	while (batHitPoints > 0 && player1.getHitPoints() > 0) {
		if (player1.playerChoice() == 1) {
			cout << "What would you like to do? \n 1.Attack || 2.Buff up!" << endl;
			cin.ignore(1, '\n');
			cin >> batChoice;
			if (batChoice == 1) {
				cout << "You lunge your sword at the bat dealing " << playerClass1.swordAttack() << " damage." << endl;
				batHitPoints -= playerClass1.swordAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (batChoice == 2) {
				playerClass1.swordSkill();
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}


		}
		if (player1.playerChoice() == 2) {
			cout << "What would you like to do? \n 1.Melee Attack || 2.Fire Bolt! || 3. Amp Up!" << endl;
			cin.ignore(1, '\n');
			cin >> batChoice;
			if (batChoice == 1) {
				cout << "You smack the bat with your staff " << playerClass2.mageAttack() << " damage." << endl;
				batHitPoints -= playerClass2.mageAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (batChoice == 2) {
				batHitPoints -= playerClass2.mageFireBolt();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat uses its wings to conjure wind slashes directed at you!" << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (batChoice == 3) {
				playerClass2.mageSkill();
				system("pause");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}

		}
		if (player1.playerChoice() == 3) {
			cout << "What would you like to do? \n 1.Shoot || 2.Focus! || 3.Pull a Shadow!" << endl;
			cin.ignore(1, '\n');
			cin >> batChoice;
			if (batChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				batHitPoints -= playerClass3.archerAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (batChoice == 2) {
				playerClass3.archerFocus();
				system("pause");
				cout << batChoice << endl;
			}
			else if (batChoice == 3) {
				batHitPoints -= playerClass3.archerSkill();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void Monster::goblinFight() {
	int goblinChoice;
	int goblinHitPoints = 18;
	int goblinATK = 5;

	cout << "You have encountered a goblin! You have no choice but to fight! " << endl;

	while (goblinHitPoints > 0 && player1.getHitPoints() > 0) {
		if (player1.playerChoice() == 1) {
			cout << "What would you like to do? \n 1.Attack || 2.Buff up!" << endl;
			cin.ignore(1, '\n');
			cin >> goblinChoice;
			if (goblinChoice == 1) {
				cout << "You lunge your sword at the goblin dealing " << playerClass1.swordAttack() << " damage." << endl;
				goblinHitPoints -= playerClass1.swordAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "HEHEHE KEKEKE the goblin stabs you." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (goblinChoice == 2) {
				playerClass1.swordSkill();
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}


		}
		if (player1.playerChoice() == 2) {
			cout << "What would you like to do? \n 1.Melee Attack || 2.Fire Bolt! || 3. Amp Up!" << endl;
			cin.ignore(1, '\n');
			cin >> goblinChoice;
			if (goblinChoice == 1) {
				cout << "You smack the goblin with your staff " << playerClass2.mageAttack() << " damage." << endl;
				goblinHitPoints -= playerClass2.mageAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "HEHEHE KEKEKE the goblin stabs you." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (goblinChoice == 2) {
				goblinHitPoints -= playerClass2.mageFireBolt();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "The goblin dances, you feel your life draining away." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (goblinChoice == 3) {
				playerClass2.mageSkill();
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}

		}
		if (player1.playerChoice() == 3) {
			cout << "What would you like to do? \n 1.Shoot || 2.Focus! || 3.Pull a Shadow!" << endl;
			cin.ignore(1, '\n');
			cin >> goblinChoice;
			if (goblinChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				goblinHitPoints -= playerClass3.archerAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "The hurls a rock at you." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					cin.ignore(1, '\n');
					system("pause");
					system("cls");
				}
			}
			else if (goblinChoice == 2) {
				playerClass3.archerFocus();
				system("pause");
				system("cls");
			}
			else if (goblinChoice == 3) {
				goblinHitPoints -= playerClass3.archerSkill();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "Please pick an actual option." << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void damageCalc(int playerHP, int enemyATK) {
	int damageOUT;
	if (player1.playerChoice() == 1) {
		damageOUT = enemyATK - playerClass1.swordDef();
		if (damageOUT <= 0) {
			cout << "You take 0 damage." << endl;
		}
		else {
			damageOUT = enemyATK - playerClass1.swordDef();
			cout << "You take " << damageOUT << " damage." << endl;
			player1.hitPointsChange(damageOUT);
		}
	}
	else {
		damageOUT = enemyATK;
		cout << "You take " << damageOUT << " damage." << endl;
		player1.hitPointsChange(damageOUT);
	}

}

void guessGame() {
	srand(time(NULL));
	int secretNum;
	int guess;
	bool rightNumber = false;
	int guessCount = 0;
	secretNum = rand() % 10;


	while (rightNumber == false && guessCount < 3) {
		//cout << secretNum << endl; For debugging making sure the secret number worked.
		cout << "Guess a number between 1 and 10: ";
		cin >> guess;
		if (guess > secretNum) {
			cout << "That number is too high!" << endl;
		}
		else if (guess < secretNum) {
			cout << "That number is too low!" << endl;
		}
		else if (guess = secretNum) {
			rightNumber = true;
		}

		guessCount++;
	}
	if (guess == secretNum) {
		cout << "You feel healthier" << endl;
		player1.hitPointsChange(-5);
		//cout << player1.getHitPoints() << endl; For debugging.
		
	}
	else {
		cout << "You feel drained..." << endl;
		player1.hitPointsChange(3);
		//cout << player1.getHitPoints() << endl;
		
	}
	
}

void classLevelUp() {
	string levelUp1 = "Now that you have beaten the Maze of Unyielding, ";
	string levelUp2 = "It is time for you to grow. You can be so much more powerful.";
	string levelUp3 = "I will grant you the ability to unlock the rest of your power ";
	string levelUp4 = "Embrace it, feel it, BELIEVE IT!";
	cout << "Mystic voice: ";
	for (int i = 0; i < levelUp1.length(); i++) {		//another looping for text
		cout << levelUp1[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < levelUp2.length(); i++) {		//another looping for text
		cout << levelUp2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	levelUp3 += player1.getName();
	cout << "Mystic voice: ";
	for (int i = 0; i < levelUp3.length(); i++) {		//another looping for text
		cout << levelUp3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < levelUp1.length(); i++) {		//another looping for text
		cout << levelUp1[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < levelUp4.length(); i++) {		//another looping for text
		cout << levelUp4[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(250);
	levelTransition();

	string moreLevelUpText1 = "You are now much stronger.";
	string moreLevelUpText2 = "You have more vitality.";
	string moreLevelUpText3 = "Now make make haste!";
	string moreLevelUpText4 = "The Demon Lord can sense your prensence.";

	cout << "Mystic voice: ";
	for (int i = 0; i < moreLevelUpText1.length(); i++) {		//another looping for text
		cout << moreLevelUpText1[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < moreLevelUpText2.length(); i++) {		//another looping for text
		cout << moreLevelUpText2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < moreLevelUpText3.length(); i++) {		//another looping for text
		cout << moreLevelUpText3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	cout << "Mystic voice: ";
	for (int i = 0; i < moreLevelUpText4.length(); i++) {		//another looping for text
		cout << moreLevelUpText4[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(250);
}