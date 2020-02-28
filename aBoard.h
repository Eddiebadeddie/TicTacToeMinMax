#include <iostream>

using namespace std;

#ifndef A_BOARD
#define A_BOARD

class aBoard{
	private:
		int size;
		int CheckSurroundings(int num, int i, int j);

	public:
		int** board;

		aBoard();
		aBoard(const aBoard& other);
		~aBoard();
		void Initialize();
		void Display();
		void Place(int num, int x, int y);
		bool Check(int *win);

		int Analyze();
};

#endif
