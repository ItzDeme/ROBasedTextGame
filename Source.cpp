#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <cctype>
#include <locale.h>
#include "player.h"

using namespace std;
int textSpeed = 65;	//global variable for sleep function "speed of text"
void orb_of_choosing();
void doneChoosing();

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
	

	introduction();
	string playerName;
	cout << endl << "Type your name: ";
	cin.ignore();
	getline(cin, playerName);
	Player player1(playerName, 30, 1); //creates a class of player1.
	cout << " Come " << player1.getName() << " Let us venture to the Orb choosing! " << endl;
	system("pause");
	orb_of_choosing();
	
	
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
		Swordsman player;
		system("cls");
		string swordsmanText = "You are a swordsman!";
		string swordsmanText2 = "Your grit and will power will take you far!";

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
		Mage player;
		system("cls");
		string mageText = "You are a mage!";
		string mageText2 = "With great power comes great responsibility!";

		for (int i = 0; i < mageText.length(); i++) {
			cout << mageText[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < mageText2.length(); i++) {
			cout << mageText2[i];
			Sleep(textSpeed);
		}
	}
	 else if(aOrbChoice == "3" || aOrbChoice == "archer") {
		Archer player;
		system("cls");
		string archerText = "You are an Archer!";
		string archerText2 = "Diligence and patience are your greatest attributes!";

		for (int i = 0; i < archerText.length(); i++) {
			cout << archerText[i];
			Sleep(textSpeed);
		}
		cout << endl;
		for (int i = 0; i < archerText2.length(); i++) {
			cout << archerText2[i];
			Sleep(textSpeed);
		}

	}
	 else {
		cout << "Please choose and actual class!!!!" << endl;
		cout << aOrbChoice << endl;
		system("pause");
		orb_of_choosing();
	}
	void doneChoosing();
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
		cout << done_choosing[i];
		Sleep(textSpeed);
	}
	cout << endl;
}