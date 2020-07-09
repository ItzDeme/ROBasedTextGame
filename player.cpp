#include "player.h"
#include <locale.h>
#include <Windows.h>
#include <time.h>




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
string Player::changeName(string bName) {
	name = bName;
	return name;
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

