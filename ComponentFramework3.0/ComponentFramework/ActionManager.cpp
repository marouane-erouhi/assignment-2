#include "ActionManager.h"
#include <iostream>

using namespace std;

ActionManager::ActionManager()
{
	OnCreate();
}

void ActionManager::OnCreate() {
	
	turn = 0;
	chara.reset(new Character01(100, 20, 5, 5, 3));
	enemy.reset(new Character01(80, 10, 5, 5, 3));
}

void ActionManager::Damage() {

	if (!chara->isAttack) {
		enemy->changeHealth(chara->getAttack());
		actionQ.push_back(ActionBlock(1, 2, chara->getAttack() * -1));
		
		chara->changeHealth(enemy->getAttack());
		actionQ.push_back(ActionBlock(0, 2, enemy->getAttack() * -1));

		chara->isAttack = true;
		cout << "Attacked!" << endl;
	}
}

void ActionManager::MoveObject(int direction_) {
	int tmp;

	if (chara->move > 0) {
		pos = pMove->Move(direction_);
		chara->move--;
		actionQ.push_back(ActionBlock(0, 1, (direction_ * -1))); //Owner, Action, Value
	}
}

void ActionManager::Undo() {

	//Call the list and revert to the previous action
	if (!actionQ.empty()) {
		switch (actionQ.back().action) {
		case 1://Moving
			pos = pMove->Move(actionQ.back().value);
			chara->move++;
			actionQ.pop_back();
			break;
		case 2://Attacking
			chara->changeHealth(actionQ.back().value);
			chara->isAttack = false;
			actionQ.pop_back();

			enemy->changeHealth(actionQ.back().value);
			actionQ.pop_back();
			break;
		}
		cout << "Undo" << endl;
	}
}

void ActionManager::EndTurn() {
	
	chara->resetTurn();//Reset move counter and attack bool
	actionQ.clear();//Empty the List
	turn++;//Increment turn
	cout << "End Turn" << endl;
}

void ActionManager::PrintInfo() {

	cout << "Turn: " << turn << endl;
	cout << "Player => Health: " << chara->currentHealth << "/" << chara->getHealth() << " " <<
	"Move left: " << chara->move << endl;
	cout << "Enemy => Health: " << enemy->currentHealth << "/" << enemy->getHealth() << " " <<
	"Move left: " << enemy->move << "\n" << endl;
}

void ActionManager::OnDestroy() {
	
}

ActionManager::~ActionManager()
{
	OnDestroy();
}
