#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "Board.h" //has Vector.h
#include "Character01.h" //has <iostream>
#include "PlayerMovement.h"
#include "ActionBlock.h"
#include <memory>
#include <list>

using namespace MATH;

//Process actions and store or call them from list
class ActionManager
{
public:
	ActionManager();
	~ActionManager();
	void OnCreate();
	void OnDestroy();

	int turn;
	Vec3 pos;
	
	Board board;
	std::unique_ptr<PlayerMovement> pMove = std::make_unique<PlayerMovement>(pos, board);
	std::unique_ptr<Character01> chara;
	std::unique_ptr<Character01> enemy;
	std::list<ActionBlock> actionQ;

	void Damage();//takes input and do damage
	void MoveObject(int direction_);//movement only
	void Undo();
	void EndTurn();
	void PrintInfo();
	
};

#endif