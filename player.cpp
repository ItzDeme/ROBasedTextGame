#include "player.h"

Player::Player(string aName, int aHitPoints, int aPlayerEXP) {
	name = aName;
	hitPoints = hitPoints;
	aPlayerEXP = playerEXP;
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