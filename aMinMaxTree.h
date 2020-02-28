#include <iostream>
#include <vector>
#include "aBoard.h"

using namespace std;

#ifndef MINMAXTREE_H
#define MINMAXTREE_H

struct TreeNode{
	aBoard* board;
	int val;
	vector<TreeNode*> states;

	TreeNode();
	TreeNode(aBoard* b);
	
	void DeleteTree(TreeNode *n);

	void ChildBoard(aBoard* b);

};
#endif
