#include "aMinMaxTree.h"

TreeNode::TreeNode(){
	board = NULL;	
	val = 0;
}

TreeNode::TreeNode(aBoard* b){
	board = b;
	val = 0;
}

void TreeNode::DeleteTree(TreeNode *n){
	cout<<endl<<"Deleting Tree"<<endl;
	int size = n->states.size();
	
	if(size == 0){
		delete board;
		board = nullptr;
		delete n;
		n = nullptr;
		cout<<"\tMinMaxTree Done"<<endl;
		return;
	}
	else{
		for(int i = 0; i < size; ++i){
			DeleteTree(n->states[i]);
		}
		delete board;
		board = nullptr;
		delete n;
		n = nullptr;
		cout<<"\tMinMaxTree Done"<<endl;
		return;
	}
}

void TreeNode::ChildBoard(aBoard* b){
	TreeNode* t = new TreeNode(b);
	states.push_back(t);
}
