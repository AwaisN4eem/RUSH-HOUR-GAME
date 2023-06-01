//============================================================================
// Name        : Awais.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

//Project
#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <fstream>
#include<iostream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
	int num=3;
	int Dis=10; // For Distance of windows from outer screen
	float val=800/(2*num);
	int color_choice;
	float mx_i=Dis;
	float my_i=Dis;
	float xcar[21]={0,40,80,120,160,200,240,280,320,360,400,440,480,520,560,600,640,680,720,760,800};
	int indx=0;
	float ycar[21]={0,40,80,120,160,200,240,280,320,360,400,440,480,520,560,600,640,680,720,760,800};
	int indy=20;
	int score_ded;
	int mytime=0;
	int picked=-1;
	int drop_x=-1;
	int drop_y=-1;
	int obstracle;
	int droped=0;
	
	int pass_x[5]={3,5,7,19,14};
	int pass_y[5]={11,14,2,8,19};
	
	int buildings_x[15]={11,12,13,14,14,12,13,14,14,14,5,5,5,5,5};
	int buildings_y[15]={3,3,3,5,7,11,11,11,12,13,5,6,7,8,9};
	int n_buildings=15;
	
	int other_cars=0;
	int other_cars_x[5]={0,1,2,4,10};
	int other_cars_y[5]={0,1,2,3,4};
	
	int tree_x[7]={3,6,8,9,10,12,15};
	int tree_y[7]={10,15,3,17,6,14,8};
	int other_cars_x_line[5][2]={0,20,
					1,19,
					2,18,
					4,17,
					10,16
					};
					
	int other_cars_y_line[5][2]={0,20,
					1,19,
					2,18,
					3,17,
					4,16};
	enum directions{UP,RIGHT,LEFT,DOWN};
	int direction_cars[5]={DOWN,DOWN,DOWN,DOWN,DOWN};
	
	float mx = 400; 
	float my = 765-my_i;
	float ox_i=Dis;
	float oy_i=Dis;
	float ox = 30; 
	float oy = Dis;
	int food=2*num;
	bool condition[200][200];
	int start_menu=0;// An Arbitrary Variable For Menu Display
	bool play=false;
	bool start=false;
	bool lost=false;
	int level=1;
	int life=3;
	int score=0;
	int loading=100;
	
	int ospeed=5;
	int p_score=0;
	bool color_selection;



// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) 
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.6/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
			0.706/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
// Drawing My car
if(loading<=600)
{
	DrawRectangle(250,600,400,50,colors[DARK_MAGENTA]);
	DrawString(270,620,"RUSH HOUR BY AWAIS NAEEM",colors[BLACK]);
	DrawString(370,350,"LOADING",colors[RED]);
	for(int i=0;i<=loading;i+=50)
	{
	DrawCircle(150+i,400,10,colors[BLUE]);
	}
}
else
{

if(start_menu==3)
{
	DrawString(100,600,"THIS IS YOUR CAR  !!!!",colors[MISTY_ROSE]);
	{
	int x=100,y=700;
	float width = 20; 
	float height = 15;
	float* color = colors[RED]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
	}


	DrawString(100,300,"THIS IS THE PASSENGER !!!!",colors[MISTY_ROSE]);
	{
	int x=100,y=400;
	float width = 20; 
	float height = 15;
	float* color = colors[BLUE_VIOLET]; 
	float* color_legs=colors[BLUE];
	float radius = 5.0;
	DrawRoundRect(x+width*2+2,y+height*2,width/2,height*2,color,radius); // right arm
	DrawRoundRect(x+width/2-2,y+height*2,width/2,height*2,color,radius); // left arm

	DrawRoundRect(x+width, y+height, width, height*3, color, radius/2); // body 
	
	DrawRoundRect(x+width+4, y+height*4, width-8, height, color, radius); 

	DrawRoundRect(x+width,y,width/2-1,height*2,color,radius); // left leg
	DrawRoundRect(x+width+width/2+1,y,width/2-1,height*2,color,radius); //right leg
	
	}

	DrawString(100,250,"PRESS UP, DOWN , LEFT AND RIGHT ",colors[DARK_MAGENTA]);
	DrawString(100,200,"BUTTONS FOR RESPECTIVE MOVEMENT ",colors[DARK_MAGENTA]);
	DrawString(100,150,"PRESS SPACE TO PICK A PASSENGER",colors[DARK_MAGENTA]);
}




if(start_menu==2)// When V is Pressed
{

int high_scores[10]={100,120,130,135,137,140,150,164,172,191};

int position=500;

int i=0;
	for(int j=0;j<10;j++)
	{
		if(score>high_scores[j])
		{
			high_scores[j]=score;
			break;
		}
	
	}

	for(int j=0;j<10;j++)
	{
	if(high_scores[j]>high_scores[j]);
	{
	int temp=0;
	temp=high_scores[j];
	high_scores[j]=high_scores[j+1];
	high_scores[j+1]=temp;
	}
	}

ofstream fout;
	fout.open ("high_score.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << high_scores[i] << endl;
	}
		
	fout.close();





	DrawString(350,700,"----High Scores----",colors[RED]);
	
	//reading from a file
	string h_score;
	ifstream fin ("high_score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, h_score) ) //this loop will run depending on the number of lines in the file
		{
			DrawString(450,position,h_score,colors[MISTY_ROSE]);			
			high_scores[i]=stoi(h_score);
		  position-=50;
		  //HINT: use stoi() to convert string into Integer
		  
		}
		fin.close();
	}
	
	else 
	DrawString(350,500,"Unable to open file",colors[AQUA_MARINE]); 



}


if(start_menu==0)//Start Menu
{

	DrawCircle(30,30,300,colors[DARK_MAGENTA]);
	DrawCircle(720,650,150,colors[DARK_MAGENTA]);

	DrawCircle(520,150,100,colors[DARK_MAGENTA]);
	DrawCircle(600,270,50,colors[DARK_MAGENTA]);
	DrawCircle(612,348,30,colors[DARK_MAGENTA]);
	DrawCircle(612,388,10,colors[DARK_MAGENTA]);

	DrawCircle(180,520,100,colors[DARK_MAGENTA]);
	DrawCircle(270,630,50,colors[DARK_MAGENTA]);
	DrawCircle(338,670,30,colors[DARK_MAGENTA]);
	DrawCircle(376,680,10,colors[DARK_MAGENTA]);
	if(lost)
	{
	
	if(score>=100)
		DrawString(350,650,"You WON The Game !!!!!!",colors[RED]);
	else	
		DrawString(350,650,"You Lost !!!!!!",colors[RED]);
	DrawString(350,550,"You Score was"+Num2Str(score),colors[RED]);
	}

	DrawString(350,450,"N.  START A NEW GAME",colors[ALICE_BLUE]);
	DrawString(350,400,"V.  VIEW HIGH SCORES",colors[ALICE_BLUE]);
	DrawString(350,350,"H.  HELP",colors[ALICE_BLUE]);
	DrawString(350,300,"E.  EXIT",colors[ALICE_BLUE]);
	if(start)
	{
	DrawString(350,250,"5.  Continue",colors[RED]);
	}
}
else if(start_menu==1)// Game
{
if(!color_selection)
{
	DrawString(150,450,"Which Color you want to select? (R Red, Y Yellow, N Random)",colors[BLACK]);
}
else
{

if(!play)
{
	DrawString( 300, 800,"PRESS S TO START", colors[DARK_MAGENTA]);


}
else
{

	string lvl=to_string(level);
	DrawString( 50, 800,"SCORE :  "+ Num2Str(score), colors[DARK_MAGENTA]);
	DrawString( 350, 800,"LEVEL :  "+ lvl, colors[DARK_MAGENTA]);
	DrawString( 700, 800,"TIME :  "+ Num2Str(mytime/10), colors[DARK_MAGENTA]);
	
}


//Drawing Car
{
	float width = 10; 
	float height =5;
	float* color = colors[color_choice]; 
	float* coloro = colors[BLUE]; 
	float radius = 5.0;
	
	DrawRoundRect(xcar[indx],ycar[indy],width,height,color,radius); // bottom left tyre
	DrawRoundRect(xcar[indx]+width*3,ycar[indy],width,height,color,radius); // bottom right tyre
	DrawRoundRect(xcar[indx]+width*3,ycar[indy]+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(xcar[indx],ycar[indy]+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(xcar[indx], ycar[indy]+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(xcar[indx]+width, ycar[indy]+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(xcar[indx]+width*3, ycar[indy]+height*2, width, height, color, radius/2); // body right rect
	
		for(int i=0;i<other_cars;i++)
	{
	DrawRoundRect(xcar[other_cars_x[i]],ycar[other_cars_y[i]],width,height,coloro,radius); // bottom left tyre
	DrawRoundRect(xcar[other_cars_x[i]]+width*3,ycar[other_cars_y[i]],width,height,coloro,radius); // bottom right tyre
	DrawRoundRect(xcar[other_cars_x[i]]+width*3,ycar[other_cars_y[i]]+height*4,width,height,coloro,radius); // top right tyre
	DrawRoundRect(xcar[other_cars_x[i]],ycar[other_cars_y[i]]+height*4,width,height,coloro,radius); // top left tyre
	DrawRoundRect(xcar[other_cars_x[i]], ycar[other_cars_y[i]]+height*2, width, height, coloro, radius/2); // body left rect
	DrawRoundRect(xcar[other_cars_x[i]]+width, ycar[other_cars_y[i]]+height, width*2, height*3, coloro, radius/2); // body center rect
	DrawRoundRect(xcar[other_cars_x[i]]+width*3, ycar[other_cars_y[i]]+height*2, width, height, coloro, radius/2); // body right rect
	
	
	}
	
	
}
for(int i=0;i<n_buildings;i++)
	{
		DrawRectangle(xcar[buildings_x[i]], ycar[buildings_y[i]], 40, 41, colors[BLACK]);	
	}

	//Drawing Passenger
{
	float width =  15; 
	float height =  9;
	float* color = colors[DARK_MAGENTA]; 
	float radius = 5.0;
	for(int i=0;i<5;i++)
	{
		if(i!=picked)
		{
	
			DrawRoundRect(xcar[pass_x[i]]-3+width*2+2,ycar[pass_y[i]]+height*2,width/2,height*2,color,radius); // right arm
			DrawRoundRect(xcar[pass_x[i]]-3+width/2-2,ycar[pass_y[i]]+height*2,width/2,height*2,color,radius); // left arm

			DrawRoundRect(xcar[pass_x[i]]-3+width, ycar[pass_y[i]]+height, width, height*3, color, radius/2); // body 
		
			DrawRoundRect(xcar[pass_x[i]]-3+width+4, ycar[pass_y[i]]+height*4, width-8, height, color, radius); 

			DrawRoundRect(xcar[pass_x[i]]-3+width,ycar[pass_y[i]],width/2-1,height*2,color,radius); // left leg	
			DrawRoundRect(xcar[pass_x[i]]-3+width+width/2+1,ycar[pass_y[i]],width/2-1,height*2,color,radius); //right leg
		}
	}
	
	if(picked!=-1)
	{
		color=colors[GREEN];
			DrawRoundRect(xcar[drop_x]-3+width*2+2,ycar[drop_y]+height*2,width/2,height*2,color,radius); // right arm
			DrawRoundRect(xcar[drop_x]-3+width/2-2,ycar[drop_y]+height*2,width/2,height*2,color,radius); // left arm

			DrawRoundRect(xcar[drop_x]-3+width, ycar[drop_y]+height, width, height*3, color, radius/2); // body 
		
			DrawRoundRect(xcar[drop_x]-3+width+4, ycar[drop_y]+height*4, width-8, height, color, radius); 

			DrawRoundRect(xcar[drop_x]-3+width,ycar[drop_y],width/2-1,height*2,color,radius); // left leg	
			DrawRoundRect(xcar[drop_x]-3+width+width/2+1,ycar[drop_y],width/2-1,height*2,color,radius); //right leg
	
	
	}
	
	
	
		
}

val=1020;
	// Drawing Arena
for(int i=40;i<=val;i+=40)
{
  //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
   DrawLine(i  , 0 ,  i , 840 , 1 , colors[BLACK] );	
}

	
	for(int i=0;i<7;i++)
	{
		DrawRoundRect(xcar[tree_x[i]]+17,ycar[tree_y[i]],6,20,colors[BROWN],5); //right leg
		DrawCircle(xcar[tree_x[i]]+20,ycar[tree_y[i]]+20,10,colors[GREEN]);
	}



}
}
}


	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}





/*This Function is used for refilling the arena;
 *After Collision and Completion of a level
 *
 /




/*
 * This Function is uesd for Detecttion of Collision
 * If Both Cars are ahead or They come in a range of 50 pixels with other car, then a Collision is Detected
*/

void Collision_Detector(int axis,int dir) {


//Collision
 	for(int i=0;i<5;i++)
 	{
 		if(indx==pass_x[i] && indy==pass_y[i])
 			{
 				if(axis==0)
				{
					if(dir==0)
						indx++;
					else indx--;
				}
				else 
				{
					if(dir==0)
						indy++;
					else indy--;
				}
 			
 			}
 		
 	}
 	for(int i=0;i<n_buildings;i++)
 	{
 		if(indx==buildings_x[i] && indy==buildings_y[i])
 			{
 				if(axis==0)
				{
					if(dir==0)
						indx++;
					else indx--;
				}
				else 
				{
					if(dir==0)
						indy++;
					else indy--;
				}
 			
 			}
 		
 	}
 		
 		if(indx==drop_x && indy==drop_y)
 			{
 				if(axis==0)
				{
					if(dir==0)
						indx++;
					else indx--;
				}
				else 
				{
					if(dir==0)
						indy++;
					else indy--;
				}
 			
 			}
	


}


void pick_up()
{
	for(int i=0;i<5;i++)
	 	{
	 		if(  ((indx+1==pass_x[i] || indx-1==pass_x[i] ) && indy==pass_y[i] )  || ( indx==pass_x[i] && (indy+1==pass_y[i] || indy-1==pass_y[i])))
	 			{
					if(picked==-1)
					{
						picked=i;
						pass_x[i]=-1;
						pass_y[i]=-1;
						drop_x=GetRandInRange(0,19);
						drop_y=GetRandInRange(0,19);
					}	 			
	 			}
	 		
	 	}

}

void drop()
{
	if(picked!=-1)
	{
		if(  ((indx+1==drop_x || indx-1==drop_x ) && indy==drop_y )  || ( indx==drop_x && (indy+1==drop_y || indy-1==drop_y)))
	 	{
	 					drop_x=GetRandInRange(0,19);
						drop_y=GetRandInRange(0,19);
					pass_x[picked]=drop_x;
					pass_y[picked]=drop_y;
					//drop_x=GetRandInRange(0,19);
					//drop_y=GetRandInRange(0,19);
					picked=-1;
					drop_x=-1;
					drop_y=-1;
					score+=10;
					droped++;
					if(droped%2==0)
						if(other_cars<5)
							other_cars++;				
					 			
	 	}
	 			
		
	}


}




/*
 * This Function is used for life checking, means how many lives are remaining
 *
 **/


void Time_Checker()
{
	if(play)
	{

		if(mytime>=1800)
		{
			play=false;
			start_menu=0;
			start=false;
			lost=true;

		}
	}

}










/*
 *This Function is used for level detection
 *which Level is going on
 **/



void NonPrintableKeys(int key, int x, int y) {
if(play)
{
	if (key == GLUT_KEY_LEFT/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
	
		if(indx>0)
			indx--;
		Collision_Detector(0,0);
		
		// what to do when left key is pressed...

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(indx<20)
			indx++;
		Collision_Detector(0,1);


	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

		if(indy<20)
			indy++;
		Collision_Detector(1,1);
	}
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(indy>0)
			indy--;
		Collision_Detector(1,0);

	}
	
	
	for(int i=0;i<7;i++)
	{
		if(indx==tree_x[i] && indy==tree_y[i])
			score-=obstracle;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}



/*
 * When a new game is started, then these conditions are applied
 * 
 * */
	if (key == 'N'|| key=='n')
	{
	color_selection=false;
	start_menu=1;
	start=true;
	lost=false;
	
	indx=0;
	indy=20;
	mytime=0;
	picked=-1;
	drop_x=-1;
	drop_y=-1;
	
	droped=0;
	
	
	
	other_cars=0;
	
	}



	if(key == 'p' || key=='P')
	{
	start_menu=0;
	play=false;
	}



	if(key == 'C'|| key=='c')
	{
	start_menu=1;
	play=true;
	}



	
	if(key == 's' || key=='S')
	{
	if(!play)
		other_cars=1;
	start=true;
	play=true;
	
	}



	if(key=='h'|| key=='H')
	{

	start_menu=3;

	}



	if(key=='e' || key=='E')
	{
	exit(1);
	}
	
	if(key==' ')
	{
		if(picked==-1)
			pick_up();
		else
			drop();	
	}

if(!color_selection)
{

	switch(key)
	{
	case 'R':
	color_choice=RED;
	color_selection=true;
	score_ded=3;
	obstracle=2;
	break;
	case 'Y':
	color_choice=YELLOW;
	color_selection=true;
	score_ded=2;
	obstracle=4;
	break;
	case 'N':
	num=5;
	color_choice=RED;
	score_ded=3;
	obstracle=2;
	break;
	case 'r':
	color_choice=RED;
	color_selection=true;
	score_ded=3;
	obstracle=2;
	break;
	case 'y':
	color_choice=YELLOW;
	color_selection=true;
	score_ded=2;
	obstracle=4;
	break;
	case 'n':
	num=5;
	color_choice=RED;
	score_ded=3;
	obstracle=2;
	break;
	default:
	color_selection=false;
	}

	if(key=='v' || key=='V')
	{
	start_menu=2;

	}
	
	

}	

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
glutPostRedisplay();

loading+=25;// =5;
Time_Checker();

if(play)
{
mytime++;
	for(int i=0;i<other_cars;i++)
	{
		if(other_cars_y[i]==indy && other_cars_x[i]==indx)
			score-=score_ded;
		if(direction_cars[i]==DOWN)
		{
			if(other_cars_y[i]==other_cars_y_line[i][0])
				{
					direction_cars[i]=RIGHT;
				}
			else other_cars_y[i]--;
				
		}
		if(direction_cars[i]==UP)
		{
			if(other_cars_y[i]==other_cars_y_line[i][1])
				{
					direction_cars[i]=LEFT;
				}
			else other_cars_y[i]++;
				
		}
		if(direction_cars[i]==LEFT)
		{
			if(other_cars_x[i]==other_cars_x_line[i][0])
				{
					direction_cars[i]=DOWN;
				}
			else other_cars_x[i]--;
				
		}
		if(direction_cars[i]==RIGHT)
		{
			if(other_cars_x[i]==other_cars_x_line[i][1])
				{
					direction_cars[i]=UP;
				}
			else other_cars_x[i]++;
				
		}
		
	
	
	}
}
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("RUSH HOUR 2021"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.


	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(100.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
