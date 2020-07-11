#include "player.h"
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




Player::Player(string aName, int aHitPoints, int aPlayerEXP) {
	name = aName;
	hitPoints = aHitPoints;
	playerEXP = aPlayerEXP;
}
string Player::getName() {
		return name;
	}
int Player::getHitPoints() {
	return hitPoints;
}
int Player::getEXP() {
	return playerEXP;
}
void Player::changeName(string bName) {
	name = bName;
	
}
int Player::changeEXP(int bPlayerEXP) {
	playerEXP += bPlayerEXP;
	return playerEXP;
}
void Player::playerChoiceClass(int cH) {
	playerClassChoice = cH;
	
}
int Player::playerChoice() {
	return playerClassChoice;
}
void Player::hitPointsChange(int attacked){
	hitPoints -= attacked;
}
void Monster::ifMonsterKilled() {
	monsterskilled += 1;
}
int Monster::getAmountOfMonstersKilled() {
	return monsterskilled;
}
void Monster::getOutMaze(){
	monsterskilled = 10;
}
void Player::hitPointsReset() {
	hitPoints = 45;
}

void transition() {

	for (int j = 0; j < 3; j++) {

		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "           O              " << endl;
		cout << "         O   O            " << endl;
		cout << "           O              " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		Sleep(50);
		system("cls");

		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "            O             " << endl;
		cout << "                          " << endl;
		cout << "        O       O         " << endl;
		cout << "                          " << endl;
		cout << "            O             " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		Sleep(50);
		system("cls");

		cout << "                          " << endl;
		cout << "             O            " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "     O       +       O    " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		cout << "             O            " << endl;
		cout << "                          " << endl;
		cout << "                          " << endl;
		Sleep(50);
		system("cls");
	}
	
}

void levelTransition() {




	system("cls");
		int a;
		string matrixEffect = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*|}{][<>"; //letters for matrix
		int y = 0;
		
		while (y < 200) {            //rows for matrix

			for (int i = 0; i < 20; i++)  //colums for it 20 = amount of colums
			{
				Sleep(1);
				a = rand() % 49;                   //calls random number to be printed.
				cout << " " << matrixEffect[a];
				cout << "  ";
				
			}
			y++;
			cout << endl;
		}
		system("cls");
	

}