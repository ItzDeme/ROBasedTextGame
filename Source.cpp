#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <cctype>
#include <locale.h>
#include <limits>
#include "player.h"

Player player1("Empty", 30, 1);
Swordsman playerClass1;
Mage playerClass2;
Archer playerClass3;
Knight levelUpClass1;
Wizard levelUpClass2;
Hunter levelUpClass3;
Monster monsters;

using namespace std;
int textSpeed = 55; //global variable for sleep function "speed of text"
void orb_of_choosing();
void doneChoosing();
void transition();
void maze_of_uny();
void rngMaze();
void damageCalc(int playerHP, int enemyATK);
void guessGame();
void levelTransition();
void classLevelUp();
void mirrorDoppelganger();
void doppelgangerFight();
void knightDoppBattle();
void baphometLastFight();
void wizardDoppBattle();
void hunterDoppBattle();
void knightAshanDeeFight();
void mageAshanDeeFight();
void hunterAshanDeeFight();

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
	Sleep(1000);
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
	Sleep(1000);
	system("cls");
	for (int i = 0; i < longIntro5.length(); i++) {
		cout << longIntro5[i];
		Sleep(textSpeed);
	}
	Sleep(200);
}


int main() {

	system("pause");
	system("cls");
	

	introduction();
	string playerName;
	cout << endl << "Type your name: ";
	
	
	getline(cin, playerName);
	player1.changeName(playerName); //changes the already preset class name
	cout << " Come " << player1.getName() << " Let us venture to the Orb choosing! " << endl;
	system("pause");
	orb_of_choosing();
	doneChoosing();
	transition();
	
	if (player1.getHitPoints() > 0) {
		maze_of_uny();
		classLevelUp();
		mirrorDoppelganger();
		doppelgangerFight();
		transition();
		baphometLastFight();
		if (player1.getName() == "Ray") {
			system("cls");
			cout << "Thanks ray for playing my game!!! I appreciate homie. <3" << endl;
			cout << "Don't think I forgot!" << endl;
			cout << "OH SUGOIIIIIIIIIII ONIIIIIICHANNNNNNNNNNNNNNNNNNNNNNNNN" << endl;
		}
		else {
			system("cls");
			cout << "That is all folks! Thank you for playing my game! I enjoyed making it." << endl;
			cout << "I don't really know how to end a game." << endl;
		}
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
	Sleep(1000);
}

void doneChoosing() {
	cout << endl;
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
	Sleep(1000);
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
				
				cin >> mazeChoice;
				cin.sync();


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
			
			cin >> bearChoice;
			cin.sync();
			if (bearChoice == 1) {
				cout << "You lunge your sword at the bear dealing " << playerClass1.swordAttack() << " damage." << endl;
				bearHitPoints -= playerClass1.swordAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), (bearATK + 1));
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> bearChoice;
			cin.sync();
			if (bearChoice == 1) {
				cout << "You smack the bear with your staff " << playerClass2.mageAttack() << " damage." << endl;
				bearHitPoints -= playerClass2.mageAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> bearChoice;
			cin.sync();
			if (bearChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				bearHitPoints -= playerClass3.archerAttack();
				cout << "The bear has " << bearHitPoints << " HP remaining." << endl;
				if (bearHitPoints > 0) {
					cout << "The bear lashes his claws at you!" << endl;
					damageCalc(player1.getHitPoints(), bearATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> batChoice;
			cin.sync();
			if (batChoice == 1) {
				cout << "You lunge your sword at the bat dealing " << playerClass1.swordAttack() << " damage." << endl;
				batHitPoints -= playerClass1.swordAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), (batATK + 1));
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> batChoice;
			cin.sync();
			if (batChoice == 1) {
				cout << "You smack the bat with your staff " << playerClass2.mageAttack() << " damage." << endl;
				batHitPoints -= playerClass2.mageAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> batChoice;
			cin.sync();
			if (batChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				batHitPoints -= playerClass3.archerAttack();
				cout << "The bat has " << batHitPoints << " HP remaining." << endl;
				if (batHitPoints > 0) {
					cout << "The bat screeches! The sound pierces your ears." << endl;
					damageCalc(player1.getHitPoints(), batATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
					system("pause");
					system("cls");
				}
			}
			else if (batChoice == 2) {
				playerClass3.archerFocus();
				system("pause");
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
			
			cin >> goblinChoice;
			cin.sync();
			if (goblinChoice == 1) {
				cout << "You lunge your sword at the goblin dealing " << playerClass1.swordAttack() << " damage." << endl;
				goblinHitPoints -= playerClass1.swordAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "HEHEHE KEKEKE the goblin stabs you." << endl;
					damageCalc(player1.getHitPoints(), (goblinATK + 3));
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> goblinChoice;
			cin.sync();
			if (goblinChoice == 1) {
				cout << "You smack the goblin with your staff " << playerClass2.mageAttack() << " damage." << endl;
				goblinHitPoints -= playerClass2.mageAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "HEHEHE KEKEKE the goblin stabs you." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
			
			cin >> goblinChoice;
			cin.sync();
			if (goblinChoice == 1) {
				cout << "You load an arrow and shoot dealing  " << playerClass3.archerAttack() << " damage." << endl;
				goblinHitPoints -= playerClass3.archerAttack();
				cout << "The goblin has " << goblinHitPoints << " HP remaining." << endl;
				if (goblinHitPoints > 0) {
					cout << "The hurls a rock at you." << endl;
					damageCalc(player1.getHitPoints(), goblinATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					
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
	secretNum = (rand() % 10) + 1;


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
	system("cls");
	string levelUp1 = "Now that you have beaten the Maze of Unyielding, ";
	string levelUp2 = "It is time for you to grow. You can be so much more powerful.";
	string levelUp3 = "I will grant you the ability to unlock half of your power ";
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

	string moreLevelUpText1 = "You are now a ";
	string moreLevelUpText2 = "This is only half your power though. The rest you'll have to take back.";
	string moreLevelUpText3 = "Now make make haste!";
	string moreLevelUpText4 = "The Demon Lord can sense your prensence.";

	if (player1.playerChoice() == 1) {
		moreLevelUpText1 += "Knight";
	}
	else if (player1.playerChoice() == 2) {
		moreLevelUpText1 += "Wizard";
	}
	else if (player1.playerChoice() == 3) {
		moreLevelUpText1 += "Hunter";
	}
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

void mirrorDoppelganger() {
	system("cls");
	string mirrorText1 = "You notice a large mirror infront of you.";
	string mirrorText2 = "You walk closer. You notice your reflection is standing further back.";
	string mirrorText3 = "Then suddenly it starts sprinting towards you. Not mimicking your movements as a mirror should.";
	string mirrorText4 = "You step back, the reflection leaps, the mirror breaks.";
	string mirrorText5 = "All that is left is a Shadow ";

	for (int i = 0; i < mirrorText1.length(); i++) {		//another looping for text
		cout << mirrorText1[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < mirrorText2.length(); i++) {		//another looping for text
		cout << mirrorText2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < mirrorText3.length(); i++) {		//another looping for text
		cout << mirrorText3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	for (int i = 0; i < mirrorText4.length(); i++) {		//another looping for text
		cout << mirrorText4[i];
		Sleep(textSpeed);
	}
	cout << endl;
	mirrorText5 += player1.getName() + ".";
	for (int i = 0; i < mirrorText5.length(); i++) {		//another looping for text
		cout << mirrorText5[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(1000);
	system("cls");
	
}

void doppelgangerFight() {
	if (player1.playerChoice() == 1) {
		//knight battle
		knightDoppBattle();
	}
	else if (player1.playerChoice() == 2) {
		//Wizard Battle
		wizardDoppBattle();
	}
	else if (player1.playerChoice() == 3) {
		//Hunter Battle
		hunterDoppBattle();
	}
	if (player1.getHitPoints() < 0) {
		cout << "You have been bested...." << endl;
		system("pause");
	}
	else {
		system("cls");
		string afterDopFightText1 = "You have defeated the Reflection, your true power shall come to you!";
		string afterDopFightText2 = "With this power you can now stand toe to toe with the Demon lord!";
		string afterDopFightText3 = "I shall now teleport you to his throne room!";
		string afterDopFightText4 = "Godspeed ";

		for (int i = 0; i < afterDopFightText1.length(); i++) {		//another looping for text
			cout << afterDopFightText1[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < afterDopFightText2.length(); i++) {		//another looping for text
			cout << afterDopFightText2[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < afterDopFightText3.length(); i++) {		//another looping for text
			cout << afterDopFightText3[i];
			Sleep(textSpeed);
		}
		cout << endl;
		afterDopFightText4 += player1.getName() + "............";
		for (int i = 0; i < afterDopFightText4.length(); i++) {		//another looping for text
			cout << afterDopFightText4[i];
			Sleep(textSpeed);
		}
		cout << endl;
		system("pause");
	}
	
}

void knightDoppBattle() {
	cout << "You must defeat this reflection in order to regain your power." << endl;
	int evilKnightHP = 40;
	int evilKnightATK = 11;
	int evilKnightSkill = evilKnightATK * 2;
	int amountSkillUsed = 0;
	int rng_for_attack;
	int evilKnightChoice;
	
	while (evilKnightHP > 0 && player1.getHitPoints() > 0) {
		rng_for_attack = rand() % 2;
		cout << "What would you like to do? \n 1.Attack || 2.Buff up! || 3.Bowling Bash!" << endl;
		
		cin >> evilKnightChoice;
		cin.sync();
		if (evilKnightChoice == 1) {
			cout << "You slash your sword at the reflection dealing " << levelUpClass1.knightAttack() << " damage." << endl;
			evilKnightHP -= levelUpClass1.knightAttack();
			cout << "The Shadow Knight has " << evilKnightHP << " HP remaining." << endl;
			if (evilKnightHP > 0) {
				if (rng_for_attack == 2 || amountSkillUsed == 0) {
					cout << "The Shadow Knight winds his sword back and smashes it towards you.";
					damageCalc(player1.getHitPoints(), evilKnightSkill);
					amountSkillUsed = 2;
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					damageCalc(player1.getHitPoints(), evilKnightATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					amountSkillUsed--;
					if (amountSkillUsed < 0) {
						amountSkillUsed = 0;
					}
				}
				
				system("pause");
				system("cls");
			}
		}
		else if (evilKnightChoice == 2) {
			playerClass1.swordSkill();
			system("pause");
			system("cls");
		}
		if (evilKnightChoice == 3) {
			if (levelUpClass1.BowlingBash() == 0) {
				cout << "You attempt to Bowling Bash, but you can't exert enough strength." << endl;
			}
			else {
				cout << "You slash your sword at the reflection dealing " << levelUpClass1.BowlingBash() << " damage." << endl;
				evilKnightHP -= levelUpClass1.BowlingBash();
				cout << "The Shadow Knight has " << evilKnightHP << " HP remaining." << endl;
			}
			if (evilKnightHP > 0) {
				if (rng_for_attack == 2 || amountSkillUsed == 0) {
					cout << "The Shadow Knight winds his sword back and smashes it towards you.";
					damageCalc(player1.getHitPoints(), evilKnightSkill);
					amountSkillUsed = 2;
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					damageCalc(player1.getHitPoints(), evilKnightATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					amountSkillUsed--;
					if (amountSkillUsed < 0) {
						amountSkillUsed = 0;
					}
				}
				
				system("pause");
				system("cls");
			}
		}

	}
}

void wizardDoppBattle() {
	cout << "You must defeat this reflection in order to regain your power." << endl;
	int evilWizardHP = 40;
	int evilWizardATK = 7;
	int evilWizardSkill = evilWizardATK * 2;
	int amountSkillUsed1 = 0;
	int rng_for_attack1;
	int evilWizardChoice;
	while (evilWizardHP > 0 && player1.getHitPoints() > 0) {
		rng_for_attack1 = rand() % 2;
		
		cout << "What would you like to do? \n 1.Attack || 2.Fire Bolt || 3.Amp Up! || 4.Meteor Storm!" << endl;
		cin >> evilWizardChoice;
		cin.sync();

		if (evilWizardChoice == 1) {
			cout << "You smack the reflection with your wand. Dealing " << playerClass2.mageAttack() << " damage." << endl;
			evilWizardHP -= playerClass2.mageAttack();
			cout << "The Shadow Wizard has " << evilWizardHP << " HP remaining." << endl;
			if (evilWizardHP > 0) {
				if (rng_for_attack1 == 2 || amountSkillUsed1 == 0) {
					cout << "The Shadow Wizard holds their hand out, you feel pressure go through your chest.";
					damageCalc(player1.getHitPoints(), evilWizardSkill);
					amountSkillUsed1 = 2;
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					cout << "The Shadow Wizard sends a blast of wind at you." << endl;
					damageCalc(player1.getHitPoints(), evilWizardATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					amountSkillUsed1--;
					if (amountSkillUsed1 < 0) {
						amountSkillUsed1 = 0;
					}
				}
			
				system("pause");
				system("cls");
			}
		}
		else if (evilWizardChoice == 2) {
			evilWizardHP -= playerClass2.mageFireBolt();
			cout << "The reflection has " << evilWizardHP << " HP remaining." << endl;
			if (evilWizardHP > 0) {
				if (rng_for_attack1 == 2 || amountSkillUsed1 == 0) {
					cout << "The Shadow Wizard holds their hand out, you feel pressure go through your chest.";
					damageCalc(player1.getHitPoints(), evilWizardSkill);
					amountSkillUsed1 = 2;
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					cout << "The Shadow Wizard sends a blast of wind at you." << endl;
					damageCalc(player1.getHitPoints(), evilWizardATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					amountSkillUsed1--;
					if (amountSkillUsed1 < 0) {
						amountSkillUsed1 = 0;
					}
				}
				
				system("pause");
				system("cls");
			}
		}
		else if (evilWizardChoice == 3) {
			playerClass2.mageSkill();
			system("pause");
			system("cls");
		}
		else if (evilWizardChoice == 4) {
			if (playerClass2.mageMeteorStorm() == 0) {
				cout << "You lift your hands to the sky, but nothing happens." << endl;
			}
			else {
				cout << "You lift your hands to the sky and summon meteors to fall from the heavens above. Dealing" << playerClass2.mageMeteorStorm() << " damage." << endl;
				evilWizardHP -= playerClass2.mageMeteorStorm();
				cout << "The Shadow Knight has " << evilWizardHP << " HP remaining." << endl;
			}
			if (evilWizardHP > 0) {
				if (rng_for_attack1 == 2 || amountSkillUsed1 == 0) {
					cout << "The Shadow Wizard holds their hand out, you feel pressure go through your chest.";
					damageCalc(player1.getHitPoints(), evilWizardSkill);
					amountSkillUsed1 = 2;
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					cout << "The Shadow Wizard sends a blast of wind at you." << endl;
					damageCalc(player1.getHitPoints(), evilWizardATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
					amountSkillUsed1--;
					if (amountSkillUsed1 < 0) {
						amountSkillUsed1 = 0;
					}
				}
				
				
				system("pause");
				system("cls");
			}
		}

	}
}

void hunterDoppBattle() {
	cout << "You must defeat this reflection in order to regain your power." << endl;
	int evilHunterHP = 30;
	int evilHunterATK = 6;
	int rng_for_attack2 = 1;
	int evilHunterChoice;

	while (evilHunterHP > 0 && player1.getHitPoints() > 0) {
		
		cout << "What would you like to do? \n 1.Attack || 2.Focus! || 3.Pull a Shadow!" << endl;
		
		cin >> evilHunterChoice;
		cin.sync();
		if (evilHunterChoice == 1) {
			cout << "You shoot a piercing arrow at the reflection. Dealing " << levelUpClass3.archerAttack() << " damage." << endl;
			evilHunterHP -= levelUpClass3.archerAttack();
			cout << "The Shadow Hunter has " << evilHunterHP << " HP remaining." << endl;
			if (evilHunterHP > 0) {
				if (rng_for_attack2 == 1) {
					cout << "The Shadow Hunter didn't bring any arrows, so he punches you in the face." << endl;
					damageCalc(player1.getHitPoints(), evilHunterATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else if (rng_for_attack2 == 2) {
					cout << "Since the Shadow Hunter has no arrows he beats you with his bow." << endl;
					damageCalc(player1.getHitPoints(), evilHunterATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				else {
					cout << "The Shadow Hunter calls you some derogatory names. Dealing " << evilHunterATK << " mental damage.";
					damageCalc(player1.getHitPoints(), evilHunterATK);
					cout << "You have " << player1.getHitPoints() << " HP remaining." << endl;
				}
				rng_for_attack2 = rand() % 3;
				
				system("pause");
				system("cls");
			}
		}
		else if (evilHunterChoice == 2) {
			playerClass3.archerFocus();
			system("pause");
			system("cls");
		}
		if (evilHunterChoice == 3) {
			evilHunterHP -= playerClass3.archerSkill();
			cout << "The Reflection has " << evilHunterHP << " HP remaining." << endl;
			system("pause");
			system("cls");
		}

	}
}

void baphometLastFight() {
	system("cls");
	string lastFightText1 = "......Really?";
	string lastFightText2 = "This.. is it....?";
	string lastFightText3 = "Sigh... Alright then....";

	cout << "Demon Lord AshanDee: ";
	for (int i = 0; i < lastFightText1.length(); i++) {		//another looping for text
		cout << lastFightText1[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(300);
	cout << "Demon Lord AshanDee: ";
	for (int i = 0; i < lastFightText2.length(); i++) {		//another looping for text
		cout << lastFightText2[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(300);
	cout << "Demon Lord AshanDee: ";
	for (int i = 0; i < lastFightText3.length(); i++) {		//another looping for text
		cout << lastFightText3[i];
		Sleep(textSpeed);
	}
	cout << endl;
	Sleep(300);

	if (player1.playerChoice() == 1) {
		knightAshanDeeFight();
		player1.hitPointsChange(-100);
	}
	else if (player1.playerChoice() == 2) {
		mageAshanDeeFight();
		player1.hitPointsChange(-100);
	}
	else if (player1.playerChoice() == 3) {
		hunterAshanDeeFight();
		player1.hitPointsChange(-100);
	}
}

void knightAshanDeeFight() {
	system("cls");
	int ashanDeeChoice;
	int LORDASHANDEEHAPPYMETER = 8;
	cout << "Lord AshanDee stands before you. You must defeat them before returning home." << endl;
	while (player1.getHitPoints() > 0) {
		cout << "What would you like to do? \n 1.Attack || 2.Buff up! || 3.Bowling Bash!" << endl;
		cin >> ashanDeeChoice;
		if (ashanDeeChoice == 1) {
			string fightText1 = "You attempt to harm Lord AshanDee by swinging your twig around.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee doesn't seem too bothered...";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 2) {
			playerClass1.swordSkill();
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 3) {
			string fightText1 = "You attempt to harm Lord AshanDee by swinging your twig around.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee doesn't seem too bothered...";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			system("pause");
			system("cls");
		}
		else {
			cout << "Please Choose a correct option. " << endl;
			system("pause");
		}
		cin.clear();


	}
}

void mageAshanDeeFight() {
	system("cls");
	int ashanDeeChoice;
	int LORDASHANDEEHAPPYMETER = 8;
	cout << "Lord AshanDee stands before you. You must defeat them before returning home." << endl;
	while (player1.getHitPoints() > 0) {
		cout << "What would you like to do? \n 1.Attack || 2.Fire Bolt! || 3.Amp Up! || 4.Meteor Storm" << endl;
		cin >> ashanDeeChoice;
		if (ashanDeeChoice == 1) {
			string fightText1 = "You attempt to harm Lord AshanDee by swinging your twig around.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee doesn't seem too bothered...";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 2) {
			string fightText1 = "You attempt to harm Lord AshanDee by playing with fire.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee appears to be using your fire to cook.....";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 3) {
			playerClass2.mageSkill();
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 4) {
			string fightText1 = "You raise your hands and Summon 10 Meteors!";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee doesn't seem too bothered...";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			system("pause");
			system("cls");
		}
		else {
			cout << "Please Choose a correct option. " << endl;
			system("pause");
		}
		cin.clear();

	}
}

void hunterAshanDeeFight() {
	system("cls");
	int ashanDeeChoice;
	int LORDASHANDEEHAPPYMETER = 8;
	cout << "Lord AshanDee stands before you. You must defeat them before returning home." << endl;
	while (player1.getHitPoints() > 0) {
		cout << "What would you like to do? \n 1.Attack || 2.Focus! || 3.Pull a Shadow!" << endl;
		cin >> ashanDeeChoice;
		if (ashanDeeChoice == 1) {
			string fightText1 = "You attempt shoot Lord AshanDee in the head with your arrow. But you missed.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			if (LORDASHANDEEHAPPYMETER > 5) {
				string fightText2 = "Lord Ashandee doesn't seem too bothered...";
				for (int i = 0; i < fightText2.length(); i++) {		//another looping for text
					cout << fightText2[i];
					Sleep(textSpeed);
				}
				LORDASHANDEEHAPPYMETER--;
				cout << endl;
			}
			else if (LORDASHANDEEHAPPYMETER > 1) {
				string fightText3 = "Lord Ashandee is getting annoyed.....";
				for (int i = 0; i < fightText3.length(); i++) {		//another looping for text
					cout << fightText3[i];
					Sleep(textSpeed);
				}
				cout << endl;
				LORDASHANDEEHAPPYMETER--;
			}
			else {
				string fightText4 = "Power Word: ";
				string fightText5 = "DEATH....";
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(200);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}
			system("pause");
			system("cls");
		}
		else if (ashanDeeChoice == 2) {
			playerClass3.archerFocus();
			system("pause");
			system("cls");
		}
		 else if (ashanDeeChoice == 3) {
			string fightText1 = "You attempt to run up and shank Lord AshanDee.";
			for (int i = 0; i < fightText1.length(); i++) {		//another looping for text
				cout << fightText1[i];
				Sleep(textSpeed);
			}
			cout << endl;
			
				string fightText4 = "Lord Ashandee slaps the life out of you.";
				string fightText5 = "What the heck were you trying to do?!";
				
				for (int i = 0; i < fightText4.length(); i++) {		//another looping for text
					cout << fightText4[i];
					Sleep(textSpeed);
				}
				cout << endl;
				cout << "Lord AshanDee: ";
				for (int i = 0; i < fightText5.length(); i++) {		//another looping for text
					cout << fightText5[i];
					Sleep(textSpeed);
				}
				cout << endl;
				player1.hitPointsChange(60);
			}else {
			cout << "Please Choose a correct option. " << endl;
			system("pause");
		}
		
		cin.clear();
		}


	}
