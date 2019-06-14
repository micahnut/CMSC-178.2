#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
	public:
		Enemy(int x, int y);
		~Enemy();
		void moveEnemy();
		//void erase(std::vector <Enemy*> & a );
		//void erase();
		void draw();
		void curve(int x0,int x1,int x2,int x3 ,int y0,int y1,int y2,int y3 ,int x);
		
		int x;
		int y;
		int speed;
		int leftx;
		int rightx;
};

#endif
