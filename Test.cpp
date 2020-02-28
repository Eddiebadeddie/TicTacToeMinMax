#include <iostream>
#include "aGame.h"

using namespace std;

int main(){
	aGame game = aGame();
	
	TreeNode t = TreeNode(game.board);
	t.board->Display();

	t.board->Place(0,1,1);
	t.board->Place(1,2,1);
	t.board->Display();
	cout<<"Analysis :" <<t.board->Analyze()<<endl;

	t.board->Place(0,1,2);
	t.board->Place(1,3,1);
	t.board->Display();
	cout<<"Analysis :" <<t.board->Analyze()<<endl;

	return 0;
}
