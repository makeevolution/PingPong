/*
 * cGameManger.h
 *
 *  Created on: 11 mrt. 2021
 *      Author: ASEBASTI
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
class cGameManger
{
private:
	int width,height;
	int score1,score2;
	char up1,down1,up2,down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle *player2;
public:
	cGameManger(int w, int h)
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		width = w;
		height = h;
		score1 = 0;
		score2 = 0;
		ball = new cBall(w/2,h/2); /* "new" reserves memory for player */
		player1 = new cPaddle(1,h/2 - 3);
		player2 = new cPaddle(w-2,h/2 - 3);
	}
	~cGameManger()/*deconstructor important to prevent memory leaks!*/
	{
		delete ball, player1, player2;
	}

	void ScoreUp(cPaddle * player)
	{
		if(player == player1)
			score1++;
		else if(player == player2)
			score2++;
		ball->Reset();/*Use -> since ball is a pointer to the ball object*/
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
		system("CLS");
		for(int i=0; i < width+2; i++){
			cout << "\xB2";
		}
		cout << endl;
		for(int i = 0; i< height ; i++)
		{
			for(int j=0; j< width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player1y = player1->getY();
				int player2x = player2->getX();
				int player2y = player2->getY();

				if (j==0)
					cout << "\xB2";

				if (ballx == j && bally == i)
					cout << "O"; //ball
				else if (player1x == j && player1y == i)
					cout << "\xDB"; //player1
				else if (player2x == j && player2y == i)
					cout << "\xDB"; //player2

				else if (player1x == j && player1y + 1 == i)
					cout << "\xDB"; //player1
				else if (player1x == j && player1y + 2 == i)
					cout << "\xDB"; //player1
				else if (player1x == j && player1y + 3 == i)
					cout << "\xDB"; //player1

				else if (player2x == j && player2y + 1 == i)
					cout << "\xDB"; //player2
				else if (player2x == j && player2y + 2 == i)
					cout << "\xDB"; //player2
				else if (player2x == j && player2y + 3 == i)
					cout << "\xDB"; //player2
				else
					cout << " ";

				if (j==width-1)
					cout << "\xB2";
			}
			cout << endl;
		}
		for(int i=0; i < width+2; i++)
			cout << "\xDB";
		cout << endl;
		cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
	}
	void Input(){
		ball->Move();

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player1y = player1->getY();
		int player2x = player2->getX();
		int player2y = player2->getY();

		if (_kbhit()){
			char current = _getch();
			if (current == up1)
				if(player1y > 0)
					player1->moveUp();
			if (current == down1)
				if(player1y + 4 < height)
					player1->moveDown();
			if (current == up2)
				if(player2y > 0)
					player2->moveUp();
			if (current == down2)
				if(player2y + 4 < height)
					player2->moveDown();

		if (ball->getDirection() == STOP)
			ball->randomDirection();

		if (current == 'q')
			quit=true;
		}
	}
	void Logic(){

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player1y = player1->getY();
		int player2x = player2->getX();
		int player2y = player2->getY();

		/* If the ball hits a paddle */
		for (int i=0;i<4;i++){ /* If the ball hits one of the 4 blocks that make up a paddle */
			if (ballx==player1x+1){
				if (bally==player1y+i){
					ball->changeDirection((eDir)((rand() % 3) + 4));
				}
			}
		}

		for (int i=0;i<4;i++){ /* If the ball hits one of the 4 blocks that make up a paddle */
			 if (ballx==player2x-1){
				if (bally==player2y+i){
					ball->changeDirection((eDir)((rand() % 3) + 1));
				}
			 }
		}

		/* If ball hits one of the horizontal walls*/
		if (bally == height-1)
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

		if (bally==1)
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

		/* If the ball passes a paddle */
		if (ballx==player1x)
			ScoreUp(player1);
		if (ballx==player2x)
			ScoreUp(player2);
	}
	void run()
	{
		while (!quit){
			Draw();
			Input();
			Logic();
		}
	}
};
