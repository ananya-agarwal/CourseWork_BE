#include <GL/glut.h>
#include<iostream>
using namespace std;


void init()
{
	//OpenGL Initilization Routines
	glClearColor(0.0, 0.0, 0.0, 0.0);// set background colour of the window as white
	glColor3f(1, 0, 0);// set line colour
	//OpenGL Coordinate Systems
	glMatrixMode(GL_PROJECTION);//background of 3D to 2D imagepale
	gluOrtho2D(0.0, 300.0, 0.0, 200.0);//specify the coordinate
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the screen before drawing

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//to make rectangle non empty
	// select a polygon rasterization mode
	glBegin(GL_POLYGON);
		glVertex2i(50, 90);//vertex at which the point is to be drawn
		glVertex2i(100, 90);
		glVertex2i(100, 150);
		glVertex2i(50, 150);
	glEnd();

	glFlush();//to draw any primitves now to the frame buffer
}


int main(int argc, char* argv[])
{
	//Initilization
	glutInit(&argc, argv);// Initilize GLUT library
	glutInitWindowSize(680, 480);//Initilize window/screen size
	glutInitWindowPosition(20, 20);//Initilize winodow/screen position
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);//Initilize mode of display
	glutCreateWindow("Rectangle");//Create Window/screen title

	//Callback Function
	init();// initilization of display image attribute and coordinate system
	glutDisplayFunc(display);//set callback function

	//Event Loop
	glutMainLoop();// start the event loop
	return EXIT_SUCCESS;
}