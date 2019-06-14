#include "Enemy.h"
#include <graphics.h>

Enemy::Enemy(int ex, int ey)
{
	x = ex;
	y = ey;
}

Enemy::~Enemy()
{
}



void Enemy::draw(){
	
	ellipse(300+x-100,30+y, 0, 360, 10, 15);
	ellipse(283+x-100,29+y,0,280,15,5);
    ellipse(315+x-100,29+y,280,170,15,5);
 	circle(305+x-100,40+y,3);
 	circle(295+x-100,40+y,3);	
 	
	Enemy::leftx = 283+x-100;
	Enemy::rightx = 315+x-100;
}

void Enemy::moveEnemy(){
	Enemy::speed =5;
	
	y = y + speed;
}


void Enemy::curve(int x0,int x1,int x2,int x3 ,int y0,int y1,int y2,int y3 ,int C_y){
	int x[4]={x0,x1,x2,x3},y[4]={y0,y1,y2,y3},px,py,i,n;
	double t;

	for(i=0;i<4;i++)
	{		
	//scanf("%d%d",&x[i],&y[i]);
		putpixel(x[i],y[i],BLUE);
	}	
	
	for(t=0.0;t<=1.0;t+=0.001){
		px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
		py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
		putpixel(px,py+C_y,RED);
	}
}


