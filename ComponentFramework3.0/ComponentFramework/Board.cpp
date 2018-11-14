#include "Board.h"
#include <iostream>


Board::Board()
{
	float x = -3.10f; float y = 1.55f; float z = 0.0f;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//x and y are tile coordinates, z determines current owner of the tile (player, enemy, or empty)
			board.at(i).at(j) = Vec3(x, y ,z);
			x += 1.55f;
		}
		x = -3.10f;
		y -= 1.55f;
	}
}

Vec3 Board::SetPosition(int i_, int j_, float value_) {
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board.at(i).at(j).z == value_) {
				board.at(i).at(j).z = 0.0f;
			}
		}
	}
	board.at(i_).at(j_).z = value_;
	
	return board.at(i_).at(j_);
}

Board::~Board()
{
}
