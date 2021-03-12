/*
 * cPaddle.h
 *
 *  Created on: 11 mrt. 2021
 *      Author: ASEBASTI
 */


class cPaddle
{
private:
	int x,y;
	int originalX,originalY;
public:
	cPaddle(){
		x = y = 0;
	}
	cPaddle(int posX, int posY) : cPaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() {fflush(stdin); x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
	friend ostream & operator<<(ostream & o, cPaddle c)
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}
};
