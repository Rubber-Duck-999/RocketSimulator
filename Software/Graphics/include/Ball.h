#include <windows.h>
// for MS Windows
#include <iostream>
#include <GL/glut.h>
// GLUT, includes glu.h and gl.h
#include <Math.h>

#ifndef BALL_H_
#define BALL_H_

const int refreshMillis = 30;
// Refresh period in milliseconds

class Ball
{
private:
	static GLfloat ballRadius;
	// Radius of the bouncing ball
	static GLfloat ballX;
	// Ball's center (x, y) position
	static GLfloat ballY;
	static GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
	// Ball's center (x, y) bounds
	static GLfloat xSpeed;
	// Ball's speed in x and y directions
	static GLfloat ySpeed;
	char _title[9] = "Graphics";
    int  _windowWidth;
	int  _windowHeight;
	int  _windowPosX;
	int  _windowPosY;
	static GLdouble _clipAreaXLeft;
	static GLdouble _clipAreaXRight;
	static GLdouble _clipAreaYBottom;
	static GLdouble _clipAreaYTop;

public:
    Ball()
	{
    	ballRadius = 0.5f;
    	ballX = 0.0f;
    	ballY = 0.0f;
    	xSpeed = 0.02f;
    	ySpeed = 0.007f;
	};
    Ball(int windowWidth, int windowHeight) { };
    void initGL();
    int getWindowWidth() { return _windowWidth; };
    int getWindowHeight() { return _windowHeight; };
    char* getTitle() { return _title; };
    void getCurrentWindowPositions(int* windowPositionArray)
    {
    	for(int i=0; i<2; i++)
    	{
            windowPositionArray[i] = 0;
    		std::cout << "Array Index is " << i << " value is " << windowPositionArray[i] << std::endl;
    	}
    }
    static void display();
    static void reshape(GLsizei width, GLsizei height);
};


#endif /* BALL_H_ */
