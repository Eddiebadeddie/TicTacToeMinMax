#include "aBoard.h"
//Constructor
aBoard::aBoard(){
	size = 3;

	//Creates a 3x3 matrix and initializes the cells to -1
	board = new int*[size];
	for(int i = 0; i < size; ++i){
		board[i] = new int[size];
		for(int j = 0; j < size; ++j){
			board[i][j] = -1;
		}
	}

	cout<<"Board has been created"<<endl;
}

//Copy Constructor
aBoard::aBoard(const aBoard& other){	
	size = 3;

	//Copies a board's values
	board = new int*[size];
	for(int i = 0; i < size; ++i){
		board[i] = new int[size];
		for(int j = 0; j < size; ++j){
			board[i][j] = other.board[i][j];
		}
	}
}

//Destructor
aBoard::~aBoard(){
	cout<<endl<<"Deleting the board"<<endl;
	for(int i = 0; i < size; ++i){
		delete [] board[i];
	}
	delete [] board;
	size = 0;
	cout<<"\tBoard Done"<<endl;
}



//Initializes board
void aBoard::Initialize(){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			board[i][j] = -1;
		}
	}
}

//Displays board
void aBoard::Display(){
	cout<<"-------------------------------"<<endl;
	for(int i = 0; i < size; ++i){
		cout<<"| ";
		for(int j = 0; j < size; ++j){
			if(board[i][j] != -1)
				cout<<board[i][j];
			else
			{
				cout<<" ";
			}
			
			cout<< " | ";
		}
		cout<<endl<<endl;
	}
}

//Places a 1 or 0 on the board
void aBoard::Place(int num, int x, int y){
	//Checks to see if spot is taken
	if(board[y-1][x-1] != -1){
		cout<<"This spot is taken"<<endl;
		return;
	}

	//Makes sure accurate number is being played
	if(num != 1 && num != 0){
		cout<<"Invalid Entry"<<endl;
		return;
	}

	//Makes sure that the value is within the bounds
	if( x < 1 || x > size || y < 1 || y > size){
		cout<<"Invalid Location"<<endl;
		return;
	}

	board[y-1][x-1] = num;
}

//Checks to see if the game has been won
bool aBoard::Check(int *win){
	//Checks to see if a diagonal was played
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != -1){
		*win = board[0][0];
		return true;
	}

	//Checks outer diagonal
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != -1){
		*win = board[2][0];
		return true;
	}

	//Checks to see if a row was won
	for(int i = 0; i < size; ++i){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != -1){
			*win = board[i][0];				
			return true;
		}
	}

	//Checks to see if a column was won
	for(int i = 0; i < size; ++i){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != -1){
			*win = board[0][i];
			return true;
		}
	}

	//If there is still a -1 on the board, return false
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(board[i][j] == -1)
				return false;
		}
	}

	//otherwise declare tie
	*win = 3;
	return true;
}

//Checks the board to get a value for each state
int aBoard::Analyze(){
	cout<<endl<<"Analyze::"<<endl;
	//Returning the sum of the state of the board
	int sum = 0;
	
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			cout<<"["<<i<<"," << j<<"]";
			//If the spot is empty, add 1
			if(board[i][j] == -1){
				cout<<"\tEmpty spot, +1"<<endl;
				++sum;
			}
			//If the current spot is the computer spot
			else if(board[i][j] == 0){
				//Find neighbors that are also 0
				cout<<"\tNeighbors for a better state: ";
				int num = CheckSurroundings(0,i,j);
				cout << num << " + 1" <<endl;
				//Add neighbors and 1 to sum
				sum += num + 1;
			}
			else if(board[i][j] == 1){
				cout<<"\tEnemy neighbors for enemy: -";
				int num = CheckSurroundings(1,i,j);
				cout<< num << endl;
				//Subtract neighbor of player's spots
				sum -= num;
			}
		}
	}

	cout<<endl;
	//Returns the value associated with the state of the board
	return sum;
}

//Checks the surroundings for a certain player
int aBoard::CheckSurroundings(int num, int i, int j){
	cout<<"Checking: ";
	int sum = 0;

	for(int a = i-1; a < i+1; ++a){
		for(int b = j-1; b < j+1; ++b){
			//If a or b are out of range, continue
			if(a < 0 || a >= size || b < 0 || b >= size)
				continue;
			//Increment number if neighbor is the same as num
			if(board[a][b] == num){
				cout<<num << " at [" << a << ", " << b << "]" << endl;
				++sum;
			}
		}
	}

	return sum;
}
