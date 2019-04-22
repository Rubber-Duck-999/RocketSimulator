#include "Ball.h"


/* Initialize OpenGL Graphics */
void Ball::initGL()
{
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}


/* Callback handler for window re-paint event */
void Ball::display()
{
   glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
   glLoadIdentity();              // Reset model-view matrix

   glTranslatef(ballX, ballY, 0.0f);  // Translate to (xPos, yPos)
   // Use triangular segments to form a circle
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0f, 0.0f, 1.0f);  // Blue
   glVertex2f(0.0f, 0.0f);       // Center of circle
   int numSegments = 100;
   GLfloat angle;
   for (int i = 0; i <= numSegments; i++)
   {
	   // Last vertex same as first vertex
       angle = i * 2.0f * 3.14f / numSegments;  // 360 deg for all segments
       glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
   }
   glEnd();

   glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)

   // Animation Control - compute the location for the next refresh
   ballX += xSpeed;
   ballY += ySpeed;
   // Check if the ball exceeds the edges
   if (ballX > ballXMax)
   {
      ballX = ballXMax;
      xSpeed = -xSpeed;
   }
   else if (ballX < ballXMin)
   {
      ballX = ballXMin;
      xSpeed = -xSpeed;
   }
   if (ballY > ballYMax)
   {
      ballY = ballYMax;
      ySpeed = -ySpeed;
   }
   else if (ballY < ballYMin)
   {
      ballY = ballYMin;
      ySpeed = -ySpeed;
   }
}


/* Call back when the windows is re-sized */
void Ball::reshape(GLsizei width, GLsizei height)
{
   // Compute aspect ratio of the new window
   if (height == 0)
   {
	   height = 1;
	   // To prevent divide by 0
   }
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);
   // To operate on the Projection matrix
   glLoadIdentity();
   // Reset the projection matrix
   if (width >= height)
   {
      _clipAreaXLeft   = -1.0 * aspect;
      _clipAreaXRight  = 1.0 * aspect;
      _clipAreaYBottom = -1.0;
      _clipAreaYTop    = 1.0;
   }
   else
   {
      _clipAreaXLeft   = -1.0;
      _clipAreaXRight  = 1.0;
      _clipAreaYBottom = -1.0 / aspect;
      _clipAreaYTop    = 1.0 / aspect;
   }
   gluOrtho2D(_clipAreaXLeft, _clipAreaXRight, _clipAreaYBottom, _clipAreaYTop);
   ballXMin = _clipAreaXLeft + ballRadius;
   ballXMax = _clipAreaXRight - ballRadius;
   ballYMin = _clipAreaYBottom + ballRadius;
   ballYMax = _clipAreaYTop - ballRadius;
}

