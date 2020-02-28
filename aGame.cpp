#include "aGame.h"

aGame::aGame(){
	winner = -1;
	player = false;
	gameOver = false;
	
	cout << "creating board"<<endl;
	board = new aBoard();

	cout<< "creating brain"<<endl;
	brain = new aBrain(board);

}

aGame::~aGame(){
	cout<<endl<<"Deleting Game"<<endl;
	delete brain;

	brain = NULL;
	cout<<"\tGame Done"<<endl;
}
