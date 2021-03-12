/*
//============================================================================

https://www.youtube.com/watch?v=y8QL62SDlcQ&list=PLrjEQvEart7faAurUFBS0zHyxktPUuyEI

//============================================================================
*/

#include <iostream>
#include <time.h>
#include <conio.h>
#include "cBall.h"
#include "cPaddle.h"
#include "cGameManger.h"
using namespace std;

int main() {
	cGameManger game(20,20);
	game.run();
	return 0;
}
