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

#endif // ! __DRAWING_H__
