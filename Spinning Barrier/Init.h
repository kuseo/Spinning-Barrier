#ifndef __INIT_H__
#define __INIT_H__

#include "gl_helper.h"
#define DIM 800

void Initialize(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(DIM, DIM);
	glutCreateWindow("Spinning Barrier");

	glClearColor(0, 0, 0, 1.0);
}

#endif //__INIT_H__