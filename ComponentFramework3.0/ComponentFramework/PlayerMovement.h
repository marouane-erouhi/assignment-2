#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include "Board.h"
#include <memory>

class PlayerMovement
{
public:
	PlayerMovement(Vec3 &pos_, Board &board_);
	~PlayerMovement();

	Vec3 pos;
	Vec3 posTile;
	
	std::unique_ptr<Board> board;
	Vec3 Move(int direction_);
};

#endif