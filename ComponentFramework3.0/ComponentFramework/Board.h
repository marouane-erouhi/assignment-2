#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "Vector.h"

using namespace std;
using namespace MATH;

class Board
{
public:
	Board();
	~Board();

	static const int size = 4;
	array<array<Vec3, size>, size> board;
	Vec3 SetPosition(int i_, int j_, float value_);

};

#endif