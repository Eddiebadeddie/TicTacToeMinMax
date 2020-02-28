#include "aBrain.h"

aBrain::aBrain(aBoard* board){
	history.push_back(board);
	layers_deep = 3;
}

aBrain::~aBrain(){
	cout<<endl<<"Deleting the brain"<<endl;
	cout<<"\tBrain Done"<<endl;
}

void aBrain::LookForward(){
	TreeNode* t = new TreeNode(history.back());
	


	t->DeleteTree(t);
}
