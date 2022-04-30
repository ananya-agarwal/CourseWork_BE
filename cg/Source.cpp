#include <GL/glut.h>
#include<iostream>
using namespace std;




void init()
{
	//OpenGL Initilization Routines
	glClearColor(1.0, 1.0, 1.0, 0.0);//set background colour of the window as white
	glColor3d(1, 0, 0);//point ka colour red
	//glColor3d only sets RGB while glColor3f sets RGB and A
	glPointSize(50);//size of the point



	//OpenGL Coordinate Systems
	glMatrixMode(GL_PROJECTION);
	//mode-> Specifies which matrix stack is the target for subsequent matrix operations.Four values are accepted.
	//Projection-> Applies subsequent matrix operations to the projection matrix stack.
	glLoadIdentity();//Load the display image
	//The glLoadIdentity function replaces the current matrix with the identity matrix.
	//It is semantically equivalent to calling glLoadMatrix with the following identity matrix.
	gluOrtho2D(0, 640, 480, 0);
	//define a 2D orthographic projection matrix. left, right, top, bottom specify the coordinates for the clipping planes.



}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the screen before drawing
	glBegin(GL_POINTS);
	glVertex2i(100, 30);//X and Y position at which the point is to be drawn
	//taking top left as 0,0
	glEnd();
	glFlush();
}




int main(int argc, char* argv[])
{
	//Initilization
	glutInit(&argc, argv);// Initilize GLUT library
	glutInitWindowSize(680, 480);//Initilize window/screen size
	glutInitWindowPosition(20, 20);//Initilize winodow/screen position
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);//Initilize mode of display
	glutCreateWindow("Point");//Create Window/screen title



	//Callback Function
	init();// initilization of display image attribute and coordinate system
	glutDisplayFunc(display);//set callback function



	//Event Loop
	glutMainLoop();// start the event loop
	return EXIT_SUCCESS;
}
