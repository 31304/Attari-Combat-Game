//============================================================================
// Name        : SAMI Irshad
// id          : 21I-1103
// Author      : FAST SE Department
// Final project
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "Player.h"
#include "Vehicle.h"
#include "MENUE.h"
#include "util.h"
#include <iostream>
#include<string>
#include <windows.h>
#include <mmsystem.h>
#include<cmath>
using namespace std;

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
// Our main Function
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Combat Attari"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	//In main We make one class
	Menue m;

	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
