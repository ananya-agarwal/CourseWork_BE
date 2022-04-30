#include <GL/glut.h>
#include<iostream>
using namespace std;


void init()
{
	//OpenGL Initilization Routines
	glClearColor(0.0, 1.0, 0.0, 1.0);//set background colour of the window as white
	//buffr clear krke new background clor daal rha h
	// Values specified by glClearColor are clamped to the range [0,1].
	// The alpha is opacity, not transparency. This means that when it is 0, you can't see it at all. When it is 1, you can see it completely.
	//Specify the red, green, blue, and alpha values used when the color buffers are cleared. The initial values are all 0.
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the screen before drawing
	glFlush();//to draw any primitves now to the frame buffer
	//empties all commands in these buffers and forces all pending commands will to be executed immediately without waiting buffers are full. 
	//Therefore glFlush() guarantees that all OpenGL commands made up to that point will complete executions 
	//in a finite amount time after calling glFlush().
}



int main(int argc, char* argv[])// argc used for the no of arguments   argv[] is a vector used to input the data
{
	//Initilization
	glutInit(&argc, argv);// Initilize GLUT library
	glutInitWindowSize(1024, 768);// Initilize window/screen size
	glutInitWindowPosition(50, 50);// Initilize window/screen position
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);// Initilize mode of display
	//Bit mask to select an RGBA mode window. This is the default 
	//An alias for GLUT_RGBA.
	// Glut_single se koi buffer pe code store nhi hota, display pe show hota hai directly, lekin glut_double se eak copy buffer pe bhi store rehti hai
	glutCreateWindow("Red Colour Display");// Create Window/screen title

	//Callback Function
	init();// initilization of display image attribute and coordinate system
	glutDisplayFunc(display);//set callback function
	//glutDisplayFunc sets the display callback for the current window.
	//Whenever GLUT determines that the contents of the window need to be redisplayed, 
	//the callback function registered by glutDisplayFunc() is executed.

	//Event Loop
	glutMainLoop();// start the event loop
	//This routine should be called at most once in a GLUT program. Once called, this routine will never return. It will call as necessary any callbacks that have been registered.
	//glutMainLoop never exits, so it should always be the last line of the main program.
	return EXIT_SUCCESS;
}