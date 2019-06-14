#ifndef SPACESHIP_H
#define SPACESHIP_H

class SpaceShip
{
	public:
		SpaceShip();
		~SpaceShip();
		int getX();
		int getY();
		//int getMid();
		
		void draw(int x, int y);
		void curve(int x0,int x1,int x2,int x3 ,int y0,int y1,int y2,int y3 ,int x);
		
		int x;
		int y;
		int leftx;
		int rightx;
		int topy;
		
		//int mid;
		
};

#endif
