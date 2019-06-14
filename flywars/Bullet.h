#ifndef BULLET_H
#define BULLET_H

class Bullet
{
	public:
		Bullet(int x, int y);
		~Bullet();
		void moveBullet();
		void draw();
		void collision();
		//void erase(Bullet b);
		//void erase(std::vector <Bullet*> & a );
		void Animate(int x, int y, int y1, int y2);
		
		int x;
		int y; 
		int speed;
		
		
};

#endif
