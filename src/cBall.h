/*
 * cBall.h
 *
 *  Created on: 11 mrt. 2021
 *      Author: ASEBASTI
 */

#define CBALL_H_
using namespace std;
#include <iostream>
#include <time.h>
#include <conio.h>
enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall
{
private:
	int x,y;
	int originalX,originalY;
	eDir direction;
public:
	cBall(int posX, int posY){
		originalX = posX;
		originalY = posY;
		x = posX;y = posY;
		direction = STOP;
	} /*Custom constructor*/

	cBall() {} /*Default constructor for practicing friend*/

	void Reset(){
		x = originalX;
		y = originalY;
		direction = STOP;
	}

	void changeDirection(eDir d)
	{
		direction = d;
	}

	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}

	inline int getX() {return x;}
	inline int getY() {return y;}
	inline eDir getDirection() {return direction;}

	void Move()
	    {
	        switch (direction)
	        {
	        case STOP:
	            break;
	        case LEFT:
	            x--;
	            break;
	        case RIGHT:
	            x++;
	            break;
	        case UPLEFT:
	            x--; y--;
	            break;
	        case DOWNLEFT:
	            x--; y++;
	            break;
	        case UPRIGHT:
	            x++; y--;
	            break;
	        case DOWNRIGHT:
	            x++; y++;
	            break;
	        default:
	            break;
	        }
	    }
	friend ostream & operator<<(ostream & o, cBall c) /*By defining friend, now the operator<< function can access the private variables of cBall*/
	    {
	        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
	        return o;
	    }
	/*friend cBall operator+ (const cBall ball_1, const cBall ball_2){
		cBall ball_new(ball_1.x+ball_2.x, ball_1.x+ball_2.y);
		ball_new.direction = LEFT;
		return ball_new;
		THIS IS JUST TO PRACTICE FRIEND FUNCTION AND OPERATOR
	}*/
};
