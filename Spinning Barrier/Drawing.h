#ifndef __DRAWING_H__
#define __DRAWING_H__

#include "gl_helper.h"
#define radian(degree) ((degree)*(3.141592)/180.0f)

void drawBarrier(float radius, int angle)
{
	float temp = radius;
	float x, y;

	glPointSize(3.0);
	glBegin(GL_POINTS);
	for (int degree = 0; degree <= (angle*2); degree++)
	{
		x = radius * cos(radian(degree/2));
		y = radius * sin(radian(degree/2));
		glVertex2f(x, y);
	}
	glEnd();
}

void drawEnemy()
{
	float w = 1/(float)glutGet(GLUT_WINDOW_WIDTH);
	float h = 1/(float)glutGet(GLUT_WINDOW_HEIGHT);

	glPointSize(1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i <= 20; i++)
	{
		float y = (float)i * h;
		glVertex2f(0.0, y);
		for (int j = i; j != 0; j--)
		{
			glVertex2f((float)j*w, y);
			glVertex2f((-1)*(float)j*w, y);
		}
	}
	glEnd();
}

void drawPrincess()
{

}

#endif // ! __DRAWING_H__
