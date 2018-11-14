#ifndef CHARACTER01_H
#define CHARACTER01_H

#include "Character.h"

class Character01 : public Character {
public:

	Character01();
	Character01(int health_, int atk_, int def_, int spd_, int mov_);

	~Character01();

};


#endif 