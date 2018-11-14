#include "Character01.h"

Character01::Character01() {

}

Character01::Character01(int health_, int atk_, int def_, int spd_, int mov_) {
	currentHealth = maxHealth = health_;
	attack = attackStat = atk_;
	defense = defenseStat = def_;
	speed = speedStat = spd_;
	move = moveStat = mov_;
}

Character01::~Character01() {
	
}

