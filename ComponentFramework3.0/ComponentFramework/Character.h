#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character {
public:
	bool isAttack = false;
	int currentHealth;
	int attack;
	int defense;
	int speed;
	int move;
	int physicalStatus;

	inline void changeHealth(int point_) {
		if (currentHealth + point_ <= 0) {
			currentHealth = 0;
		}
		else if (currentHealth + point_ >= maxHealth) {
			currentHealth = maxHealth;
		}
		else {
			currentHealth += point_;
		}
	}

	inline int getHealth() {
		return maxHealth;
	}

	inline int getMoveStat() {
		return moveStat;
	}

	inline int getAttack() {
		return -attack;
	}

	inline void resetTurn() {
		isAttack = false;
		move = moveStat;
	}

	inline void printStats() {
		std::cout << "Health: " << maxHealth << " \n" <<
			"Attack: " << attackStat << "\n" <<
			"Defense: " << defenseStat << "\n" <<
			"Speed: " << speedStat << "\n" <<
			"Move: " << moveStat << "\n" << std::endl;
	}

protected:

	int maxHealth;
	int attackStat;
	int defenseStat;
	int speedStat;
	int moveStat;

	inline void setHealth(int point_) {
		maxHealth = point_;
	}

	inline void setAttack(int point_) {
		attackStat = point_;
	}

	inline void setDefense(int point_) {
		defenseStat = point_;
	}

	inline void setSpeed(int point_) {
		speedStat = point_;
	}

	inline void setMove(int point_) {
		moveStat = point_;
	}

	inline void setStatus(int point_) {
		physicalStatus = point_;
	}

};

#endif

