#include "Bullet.h"
#include <graphics.h>

Bullet::Bullet(int shipx, int shipy)
{
	x = shipx;
	y = shipy;
}

Bullet::~Bullet()
{
}
/*
void Bullet::erase(Bullet b){
	cleardevice();
}
*/
//void Bullet::erase(Bullet &b){
//	cleardevice();/
//}

void Bullet::draw(){
	
	 circle(x,y,3);

	
}
void Bullet::moveBullet(){
	Bullet::speed =3;
	
	y = y - speed;
}



