#ifndef ACTIONBLOCK_H
#define ACTIONBLOCK_H

#include <string>
#include <memory>

using namespace std;

class ActionBlock
{
public:
	ActionBlock(int owner_, int action_, int value_);
	~ActionBlock();

	int owner;
	int value;
	int action;
};

#endif