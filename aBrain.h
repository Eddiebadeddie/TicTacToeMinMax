#include <iostream>
#include "aMinMaxTree.h"
#include "aBoard.h"

using namespace std;

#ifndef ABRAIN_H
#define ABRAIN_H

class aBrain{
	private:
		vector<aBoard*> history;
		int layers_deep;

	public:
		aBrain(aBoard* board);
		~aBrain();

		void LookForward();
};

#endif
