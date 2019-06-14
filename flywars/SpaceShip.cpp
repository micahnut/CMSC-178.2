#include "SpaceShip.h"
#include <graphics.h>
SpaceShip::SpaceShip()
{
}

SpaceShip::~SpaceShip()
{
}

int SpaceShip::getX(){
	return x;
}

int SpaceShip::getY(){
	return y;
}

//int SpaceShip::getMid(){
//	midx = 305 + getX();
//	midy = 350; 
//}


void SpaceShip::draw(int x, int y){
	
	setcolor(BLUE);
    line(300+x, 350, 310+x,350);
    line(300+x, 350, 290+x,380);
    line(310+x, 350, 320+x,380);
    curve(320,325,325,320,390,390,380,380,x);
    curve(290,285,285,290,390,390,380,380,x);
	line(320+x, 390, 324+x,395);
	line(290+x, 390, 286+x,395);
	line(324+x, 398, 339+x,413);
	line(286+x, 398, 271+x,413);
	line(324+x, 395, 324+x,430);
	line(286+x, 395, 286+x,430);
	line(324+x, 430, 320+x,435);
	line(286+x, 430, 290+x,435);
	line(290+x, 435, 320+x,435);//
	line(324+x, 430, 339+x,425);
	line(286+x, 430, 271+x,425);
	line(270+x, 435, 270+x,395);	
	line(340+x, 435, 340+x,395);
	line(265+x, 435, 265+x,395);
	line(345+x, 435, 345+x,395);		
	line(320+x, 405, 320+x,380);
	line(290+x, 405, 290+x,380);
	line(290+x, 405, 320+x,405);
	line(290+x, 405, 295+x,415);
	line(320+x, 405, 315+x,415);
	line(295+x, 415, 315+x,415);
	line(295+x, 435, 295+x,420);
	line(305+x, 435, 305+x,420);
	line(317+x, 435, 317+x,420);
	line(307+x, 435, 307+x,420);
	
	SpaceShip::leftx = 265+x;
	SpaceShip::rightx = 345+x;
	SpaceShip::topy = 350;
}

void SpaceShip::curve(int x0,int x1,int x2,int x3 ,int y0,int y1,int y2,int y3 ,int C_x){
	int x[4]={x0,x1,x2,x3},y[4]={y0,y1,y2,y3},px,py,i,n;
	double t;

//	for(i=0;i<4;i++)
//	{		
	//scanf("%d%d",&x[i],&y[i]);
//		putpixel(x[i],y[i],BLUE);
//	}	
	
	for(t=0.0;t<=1.0;t+=0.001){
		px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
		py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
		putpixel(px+C_x,py,RED);
	}
}
