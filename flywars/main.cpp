#include <iostream>
#include<graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <time.h>

#include "SpaceShip.h"
#include "Bullet.h"
#include "Enemy.h"


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bgstart();
void prnt_scr(int);
void setlife(int);
void menu();
void gameover(int);

struct timer{
	double startTime;
	double currentTime;
};

int main(int argc, char** argv) {
	
	srand((unsigned int)time(NULL));
	int xpos;
	int ypos;
	int grErrCode;
	
	initwindow(650,500, "Fly Wars");
	grErrCode = graphresult();
	
	if(grErrCode != grOk){
		cout <<" Graphics System Error: " << grapherrormsg(grErrCode)<<endl;
		exit(1);
	}
  	//character variables
	int C_x=0,M_Speed=5;   
	int C_y=0; 	
	int bulletspeed=3;
	timer update;
	double updateNow = 3000; //3 seconds
	
	int exitCondition = 0;
	
	update.startTime = GetTickCount(); //get the current system time as the start time
	
	
    int page=0,t_y=-300;
    int i, x=0, y;
    int scorecounter=0, life=5;
    int title=1;
    
    //bullets 
  	vector<Bullet*> bullets;
    vector<Bullet*>::const_iterator bulletI;
    
    //enemy 
    vector<Enemy*> enemies;
    vector<Enemy*>::const_iterator enemiesI;
    
	//ship    
    SpaceShip s;
    //Bullet b;
	
	//menu
	while(1){
		setactivepage(title);
		setvisualpage(title);
		menu();
		break;
	}
	
	//game loop
	while(1){
	
		s.draw(C_x,C_y);    

	
		setactivepage(page);
    	setvisualpage(1-page);
   		cleardevice();


		prnt_scr(scorecounter);
		setlife(life);
	
	    gameover(life);
		
		
    update.currentTime = GetTickCount() - update.startTime; // update the current time each loop
    	
    	if(update.currentTime> updateNow){
			xpos = rand()%275+1;
			ypos = 0;
    		enemies.push_back(new Enemy(xpos,ypos));

			
			++exitCondition; //increment. just so we can 
    		update.startTime = GetTickCount();
    		
    		
	
		}
		bgstart();
		
	for(enemiesI=enemies.begin(); enemiesI!=enemies.end();enemiesI++){
			(*enemiesI)->draw();
			} 
	
	for(enemiesI=enemies.begin(); enemiesI!=enemies.end();enemiesI++){
		(*enemiesI)->moveEnemy();
	}
	  
	 
	//movement  	  
    if(GetAsyncKeyState(VK_LEFT)){
		if(s.leftx>10 )	
	    	C_x-=M_Speed;
	
	}
	else if(GetAsyncKeyState(VK_RIGHT)){
        if(s.rightx<630){
			C_x+=M_Speed;
    	}
    }
	else if(GetAsyncKeyState(VK_SPACE)){
	//	b.draw(C_x,C_y);
		bullets.push_back(new Bullet(305 + C_x, 340 + C_y));
		
	}

	setcolor(CYAN);
	for(bulletI=bullets.begin(); bulletI!= bullets.end();bulletI++){
		(*bulletI)->draw();
	}
	for(bulletI=bullets.begin(); bulletI!= bullets.end();bulletI++){
		(*bulletI)->moveBullet();
	}

	int currentBx;
	int currentBy;
	int currentEx;
	int currentEy;
	
	//check for collision
	
	
	for(bulletI=bullets.begin(); bulletI!=bullets.end(); ){
        
        bool bErased = false;
        
        //insert here get the x and y of the current bullet
        currentBx = (*bulletI)->x;
        currentBy = (*bulletI)->y;
        
        for (enemiesI = enemies.begin(); enemiesI!=enemies.end();++enemiesI){
			currentEx = (*enemiesI)->x;
			currentEy = (*enemiesI)->y;
			// insert here get the x and y of the current enemy
			int currentleftx = (*enemiesI)->leftx;
			int currentrightx = (*enemiesI)->rightx;
			
			
			if(currentEy+40>=s.topy){
			if(currentleftx>=s.leftx && currentrightx<=s.rightx){
					enemiesI = enemies.erase(enemiesI);
					life--;
					break;
			}
		}
			
			//cout<<currentleftx<<endl;
			//cout<<currentrightx<<endl;
			if (currentBy <= currentEy /* check if 'y' of the current bullet coincides the current enemy*/){ 
				if ( currentBx >= currentleftx && currentBx <= currentrightx /* check if 'x' of the current bullet coincides the current enemy */){
					
					//bulletI = bullets.erase(bulletI);
					//bulletI = bullets.erase();
					bulletI = bullets.erase(bulletI);
					bErased = true;
					//enemiesI = enemies.erase(enemiesI);	
					enemiesI = enemies.erase(enemiesI);
					scorecounter++;
					break;				
				}
			}
			
			
			
		}
		
		if (!bErased){
			++bulletI;
		}
		
    }
    	
    	page=1-page;
 		delay(50);
 		
    }    
 
    getch();
    closegraph();	
	
	return 0;
}
void bgstart(){
	int x, y;
	for(int i=0; i<=50; i++) {
    	x=rand()%getmaxx();
        y=rand()%getmaxy();
        putpixel(x,y,15);
    }
      //delay(100);
}

void prnt_scr(int scorecount){
	char str[20];
	settextstyle(0,0,2);
	sprintf(str,"SCORE: %ld", scorecount);
	setcolor(RED);
	outtextxy(10,445, str);
	sprintf(str,"SCORE: %ld", scorecount);
	setcolor(RED);
	outtextxy(10,445, str);
	
}

void setlife(int life){
	char str[20];
	settextstyle(0,0,2);
	sprintf(str,"Life: %ld", life);
	setcolor(RED);
	outtextxy(10,15, str);
	sprintf(str,"Life: %ld", life);
	setcolor(RED);
	outtextxy(10,15, str);
}

void gameover(int life){
	
	if(life<=0){
	
	char str[20];
		settextstyle(0,0,3);
		outtextxy(220,200, "Game over!");
		
		getch();
	}
	
}

void menu()/* To print the Title of the game */   
{   
 	 int i,j;   
 	 
	 settextstyle(0,0,1);      

for(i=0,j=500;i<=250;i+=5,j-=5)   
{   
 	settextstyle(0,0,6);   
 	setcolor(BLUE);   
 	outtextxy(i,150,"F L Y");   
 	outtextxy(j,150," W A R S ");   
 	setcolor(BLUE);   
   
 	delay(20);   
 	outtextxy(i,150,"F L Y");   
 	outtextxy(j,150," W A R S ");   
 }
    
	setcolor(BLUE);   
	settextstyle(0,0,6);   

	outtextxy(j,150,"FLY WARS");   
	settextstyle(1,0,2);   

for(i=340,j=340;i<=440;i+=5,j-=5)   
{   
	outtextxy(i,210,"*");   
 	outtextxy(j,210,"*");   
 	delay(200);   
}   

	setcolor(1); 
	settextstyle(0,0,2);   
	outtextxy(100,450,"Press any key to continue");     
	settextstyle(0,0,1);   
	setcolor(BLUE);   


	getch();   
	cleardevice();   
	settextstyle(0,0,1);   
	setbkcolor(0);   
 }   
