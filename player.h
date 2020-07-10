#pragma once
#include <iostream>
#include <string>
using namespace std;
class Player {
	int hitPoints = 30;
	string name;
	int playerEXP = 0;
	int playerClassChoice;

public:
	
	Player(string aName, int aHitPoints, int aPlayerEXP);
		string changeName(string bName);
		string getName();
		int changeEXP(int bPlayerEXP);
		int getHitPoints();
		int getEXP();
		void playerChoiceClass(int cH);
		int playerChoice();
		void hitPointsChange(int attacked);
		void hitPointsReset();

};

class Swordsman {
	int swordmanDef = 3;
	int swordmanAttack = 5;

public:
	int swordAttack() {
		return swordmanAttack;
	}
	int swordDef() {
		
		return swordmanDef;
	}
	void swordSkill() {
		cout << "You grit your teeth and your tenacity rises!" << endl;
		swordmanDef += 3;
		system("pause");
	}
	void swordmanBuffReset() {
		swordmanDef = 3;
	}
};

class Knight : public Swordsman {
	int swordAttack = 8;
	int beenUsed = 0;
public:
	int knightAttack() {
		return swordAttack;
		if (beenUsed <= 0) {
			beenUsed = 0;
		}
		else {
			beenUsed--;
		}
	}
	int BowlingBash() {
		if (beenUsed < 2) {
			return swordAttack * 2;
			beenUsed++;
		}
		else {
			cout << "You attempt to Bowling Bash, but you can't exert enough strength." << endl;
			return 0;
		}
	}
};


class Mage {
	

public:
	int mageSkillUsed = 0;
	int mageAmp = 0;
	int mageAttack() {
		int mageAttack = 3;
		return mageAttack;
	}
	int mageFireBolt() {
		int firebolt = mageAmp + 7 ;
		cout << "Mana courses through your veins! and out of your hand you cast Fire Bolt!" << endl;
		mageSkillUsed++;
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

class Wizard : public Mage {
	
public:
	int mageMeteorStorm() {
		if (mageSkillUsed = 3) {
			cout << "You lift your hands to the sky and summon meteors to fall from the heavens above." << endl;
			mageSkillUsed = 0;
			return (6 + mageAmp) * 3;
		}
		else {
			cout << "You lift your hands to the sky, but nothing happens." << endl;
			mageSkillUsed++;
			return 0;
		}
	}
};

class Archer {
	
	bool ifFocused = false;

public:
	int archerAmp = 0;
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
	int archerSkill() {
		cout << "You pull pull out your knife and you shank your enemy." << endl;
		cout << "You backflip back into the shadows." << endl;
		int archerShank = 2;
		return archerShank;
	}
	void archerBuffReset() {
		ifFocused = false;
		archerAmp = 0;
	}
};

class Hunter : public Archer {

public:
	int archerAttack() {
		int archerAttack = 7 + archerAmp;
		return archerAttack;
	}
};

class Monster {
	int monsterskilled = 0;
public:
	void ifMonsterKilled();
	int getAmountOfMonstersKilled();
	void getOutMaze();
	void bearFight();
	void batFight();
	void goblinFight();

};