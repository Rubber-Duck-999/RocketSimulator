#include "Ball.h"
#include <windows.h>  // for MS Windows
#include <iostream>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <Math.h>     // Needed for sin, cos

/* Called back when the timer expired */
void timer(int value)
{
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, timer, 0); // subsequent timer call at milliseconds
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);            // Initialize GLUT
   Ball myBall;
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(myBall.getWindowWidth(), myBall.getWindowHeight());  // Initial window width and height
   int* array;
   myBall.getCurrentWindowPositions(array);
   glutInitWindowPosition(array[0], array[1]); // Initial window top-left corner (x, y)
   char* title = myBall.getTitle();
   glutCreateWindow(title);      // Create window with given title
   glutDisplayFunc(myBall.display);     // Register callback handler for window re-paint
   glutReshapeFunc(myBall.reshape);     // Register callback handler for window re-shape
   glutTimerFunc(0, timer, 0);   // First timer call immediately
   myBall.initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}
