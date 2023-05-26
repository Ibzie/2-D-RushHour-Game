//============================================================================
/*
This was my first semester project that wanted us to create a very basic rush hour game uing the skeleton code they provided us with.
Its quite an old program that i made in 2021, during my Programming Fundamentals course.
It was full of constraints which took a lot of fun out of it so i just made it good enough for me to get just enough marks
*/
//============================================================================
/////////////////////////
//Muhammad Ibrahim Akhtar
//Roll Number redacted 
//BS(Ds) N

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include<fstream>
#include "util.h"
#include <iostream>
#include <ctime>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void DrawObs(int x, int y)//draws obstacle at x,y
{
	DrawSquare(x, y, 20, colors[BROWN]);
}
void Passenger(int x, int y)//draws passenger at x,y
{
	DrawRectangle(x, y, 20, 30, colors[DARK_GOLDEN_ROD]);
}
//GLOBALS
int score;
int xI = 20, yI = 580;
long long int timer;
//dummycars
int X1 = 320, Y1 = 580;
int X2 = 0, Y2 = 250;
int X3 = 575, Y3 = 20;
//passenger
int PX;
int PX2;
int PX3;
//drop_offs
int DX1, DX2, DX3;
//obstacles
int ox1, ox2,oy1;

void draw_dummycar(int x,int y)//draws an NPC car at x,y
{	

	DrawSquare(x, y, 20, colors[CYAN]);
	glutPostRedisplay();
}
//draws main car
void drawCar() {
	DrawSquare(xI, yI, 20, colors[GREEN]);
	glutPostRedisplay();
}
//draws the drop off location
void DrawDropOff(int x,int y)
{
	DrawSquare(x, y, 30, colors[DARK_GREEN]);
}
//functionality of automatic moving npc cars
bool flag = true;
void moveCar1() {
	if (Y1 < 581 && flag)
	{
		Y1 -= 20;
		if (Y1 < 300)
			flag = false;
	}
	else if (Y1 < 600 && !flag)
	{
		Y1 += 20;
		if (Y1 > 560)
			flag = true;
	}
}
bool flag_2 = true;
void moveCar2() {
	if (X2 < 251 && flag_2)
	{
		X2 += 20;
		if (X2 >250)
			flag_2 = false;
	}
	else if (X2 < 300 && !flag_2)
	{
		X2 -= 20;
		if (X2 < 10)
			flag_2 = true;
	}
}
bool flag_3 = true;
void moveCar3() {
	if (Y3 < 370 && flag_3)
	{
		Y3 += 20;
		if (Y3 > 360)
			flag_3 = false;
	}
	else if (Y3 > 0 && !flag_3)
	{
		Y3 -= 20;
		if (Y3 < 20)
			flag_3 = true;
	}
}

/*
 * Main Canvas drawing function.
 * */
int opt=1;
void GameDisplay()/**/ {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
		1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

	//MENU
	 
		/*
		
		DrawRectangle(100, 400, 200, 100, colors[BLACK]);
		//DrawRectangle(sx,sy,width,height,color)
		DrawString(170, 450, "PLAY", colors[OLIVE]);

		DrawRectangle(250, 550, 200, 50, colors[BLACK]);
		DrawString(270, 570, "RUSH HOUR", colors[OLIVE]);

		DrawRectangle(100, 200, 200, 100, colors[BLACK]);
		DrawString(120, 250, "HIGHSCORES", colors[OLIVE]);
		*/
	

	if (opt == 1)
	{
		//drawing Lines
		for (int i = 0; i <= 900; i += 50)
			DrawLine(0 + i, 0, 0 + i, 600, 1, colors[OLIVE]);
		//Map1:
		//X-WALLS
		for (int i = 0; i < 150; i += 30)
		{
			int x = 100 + i;
			DrawSquare(x, 100, 30, colors[MAGENTA]);

		}
		for (int i = 0; i < 150; i += 30)
		{
			int x = 300 + i;
			DrawSquare(x, 200, 30, colors[BLACK]);

		}
		for (int i = 0; i < 150; i += 30)
		{
			int x = 100 + i;
			DrawSquare(x, 300, 30, colors[BLACK]);
		}
		for (int i = 0; i < 150; i += 30)
		{
			int x = 500 + i;
			DrawSquare(500 + i, 400, 30, colors[BLACK]);
			
		}
		for (int i = 0; i < 150; i += 30)
		{
			int x = 650 + i;
			DrawSquare(650 + i, 40, 30, colors[BLACK]);
			
		}
		//Y-WALLS
		for (int j = 0; j < 150; j += 30)
		{
			int y = 400 + j;
			DrawSquare(250, 400 + j, 30, colors[BLACK]);
			
		}
		for (int j = 0; j < 150; j += 30)
		{
			int y = 200 + j;
			DrawSquare(450, 200 + j, 30, colors[BLACK]);
			
		}
		for (int j = 0; j < 150; j += 30)
		{
			int y = 350 + j;
			DrawSquare(50, 350 + j, 30, colors[BLACK]);
			
		}
		for (int j = 0; j < 150; j += 30)
		{
			int y = 50 + j;
			DrawSquare(650, 50 + j, 30, colors[BLACK]);
		
		}
	
		drawCar();
		//calling obstacle func
		DrawObs(205, oy1);
		DrawObs(ox1, 400);
		DrawObs(ox2, 420);
		//calling passenger fun
		Passenger(PX, 10);
		Passenger(PX2, 430);
		Passenger(PX3, 70);
		//calling DropOff func
		DrawDropOff(DX1,250);
		DrawDropOff(DX2, 250);
		DrawDropOff(DX3, 10);
		//Drawing Dummy cars
		draw_dummycar(X1, Y1);
		draw_dummycar(X2, Y2);
		draw_dummycar(X3, Y3);
	}
	glutSwapBuffers(); // do not modify this line..
}



bool wall_collision()
{
	if (((xI - 20 <= 100 && xI-20>=220) || (yI != 100)))
		return true;
	if ((xI <= 100 && xI >= 220) || (yI + 20 != 100))
		return true;
}


void NonPrintableKeys(int key, int x, int y) 
{
	if ((key == GLUT_KEY_LEFT) && (xI>0) && ((xI - 10 != 100) || (yI - 10 != 100)) )
	{
		// what to do when left key is pressed...
			xI -= 20;
		/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/
	} 
	else if ((key == GLUT_KEY_RIGHT) && (xI<780)) //insert cords overlapping)
	{
			xI += 20;
	} 
	else if ((key == GLUT_KEY_UP)&&(yI<580) &&(wall_collision)) 
	{
			yI += 20;
	}

	else if ((key== GLUT_KEY_DOWN)&&(yI>0) && (wall_collision))
	{
			yI -= 20;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

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

	// implement your functionality here
	//moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	//calling funcs that move the NPC cars:
	moveCar1();
	moveCar2();
	moveCar3();
	timer += 100;
	glutTimerFunc(100, Timer, 0);
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
	//cout << x << " " << y << endl;
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
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
void drawperson(int x, int y)
{
	DrawSquare(x, y, 20, colors[GREEN]);
}
int main(int argc, char*argv[]) {

	int width = 800, height = 600; // i have set my window size to be 800 x 600
	srand(time(0));
	


	InitRandomizer(); // seed the random number generator...

	//initializing random coords:
	PX = GetRandInRange(10, 100);
	DX1 = GetRandInRange(260, 410);
	oy1 = GetRandInRange(360, 520);
	ox1 = GetRandInRange(680,780);
	ox2 = GetRandInRange(0, 140);
	DX2 = GetRandInRange(100, 250);
	DX3 = GetRandInRange(500, 700);
	PX2 = GetRandInRange(500, 650);
	PX3 = GetRandInRange(680, 780);

	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Ibz"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	if (timer == 180000)
		return 0;
	glutMainLoop();
	HERE:
	return 1;
}
#endif /* RushHour_CPP_ */
