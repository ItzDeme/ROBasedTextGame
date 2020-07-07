#pragma once
#include <iostream>
#include <string>
using namespace std;
class Player {
	int hitPoints = 30;
	string name;
	int playerEXP = 0;

public:
	
	Player(string aName, int aHitPoints, int aPlayerEXP);
		string getName();
		int getHitPoints();
		int getEXP();
	

};

class Swordsman {
	int swordmanDef = 3;

public:
	int swordAttack() {
		int swordmanAttack = 5;
		return swordmanAttack;
	}
	int swordDef() {
		
		return swordmanDef;
	}
	void swordSkill() {
		cout << "You grit your teeth and your tenacity rises!" << endl;
		swordmanDef += 3;
	}
	void swordmanBuffReset() {
		swordmanDef = 3;
	}
};


class Mage {
	int mageAmp = 0;

public:
	int mageAttack() {
		int mageAttack = 3;
		return mageAttack;
	}
	int mageFireBolt() {
		int firebolt = mageAmp + 7 ;
		cout << "Mana courses through your veins! and out of your hand you cast Fire Bolt!" << endl;
		return firebolt;
	}
	void mageSkill() {
		if (mageAmp < 9) {
			cout << "You begin chanting, your magic level raises." << endl;
			mageAmp += 3;
		}
		else {
			cout << "You are already at your max power level." << endl;
		}
	}
	void mageBuffReset() {
		mageAmp = 0;
	}
};

class Archer {
	int archerAmp = 0;
	bool ifFocused = false;

public:
	int archerAttack() {
		int archerAttack = 4 + archerAmp;
		return archerAttack;
	}
	int archerFocus() {
		
		if (ifFocused == false) {
			cout << "You are now more focused! Your arrows will hit harder" << endl;
			archerAmp = 4;
			ifFocused = true;
		}
		else {
			cout << "You can only use this skill once per battle!" << endl;
		}
		return archerAmp;
	}
	void archerSkill() {
		cout << "You pull pull out your knife and you shank your enemy." << endl;
		int archerShank = 2;
	}
	void archerBuffReset() {
		ifFocused = false;
		archerAmp = 0;
	}
};
