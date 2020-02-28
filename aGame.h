#include <iostream>
#include "aBrain.h"
#include "aBoard.h"

using namespace std;

#ifndef AGAME_H
#define AGAME_H

class aGame{
	public:
		int winner;

		bool player;
		bool gameOver;

		aBoard* board;
		aBrain* brain;

		aGame();
		~aGame();
};

#endif
