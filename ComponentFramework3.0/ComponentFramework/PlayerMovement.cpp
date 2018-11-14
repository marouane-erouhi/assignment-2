#include "PlayerMovement.h"



PlayerMovement::PlayerMovement(Vec3 &pos_, Board &board_)
{
	int startRow = 3; int startCol = 0;

	board.reset(&board_);
	pos_.x = board_.SetPosition(startRow, startCol, 1.0f).x;
	pos_.y = board_.SetPosition(startRow, startCol, 1.0f).y;
	pos_.z = 0.0f;
	posTile = Vec3(startRow, startCol, 0.0f);
}

Vec3 PlayerMovement::Move(int direction_) {
	switch (direction_) {

	case 1://Move Up
		if (posTile.x > 0) {
			posTile.x -= 1;
		}
		break;
	case -1://Move Down
		if (posTile.x < 3) {
			posTile.x += 1;
		}
		break;
	case -2://Move Left
		if (posTile.y > 0) {
			posTile.y -= 1;
		}
		break;
	case 2://Move Right
		if (posTile.y < 3) {
			posTile.y += 1;
		}
		break;
	}
	//std::cout << posTile.x << "," << posTile.y << std::endl;
	return board->SetPosition(posTile.x, posTile.y, 1.0f);
}

PlayerMovement::~PlayerMovement()
{
}
