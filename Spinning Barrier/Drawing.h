#ifndef __DRAWING_H__
#define __DRAWING_H__

#include "gl_helper.h"
#define radian(degree) ((degree)*(3.141592)/180.0f)

void drawBarrier(float radius, float angle)
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

	glBegin(GL_TRIANGLES);
	glVertex2f(w * 20.0f, 0.0f);
	glVertex2f(w * (-20.0f), 0.0f);
	glVertex2f(0.0f, h * (-20.0f));
	glEnd();

}

void drawPrincess()
{

}

#endif // ! __DRAWING_H__
