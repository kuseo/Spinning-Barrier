// Spinning Barrier.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <stdio.h>
#include <cmath>
#include <ctime>
#include <map>
#include "gl_helper.h"
#include "Drawing.h"
#include "Init.h"
#include "Barrier.h"
#include "Enemy.h"



/*
key mapping
*/
enum {LEFT, RIGHT, UP, DOWN};
bool arrow[4] = { false, };
std::map<int, bool> keys;

Barrier barrier;
Enemy enemy;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool first = true;
float lastX = 0.0f;

void updateBarrier()
{
	float _deltaTime = deltaTime / CLOCKS_PER_SEC;

	/*
	update barrier position
	*/
	if (arrow[LEFT]) { barrier.updateRotate(_deltaTime); }
	if (arrow[RIGHT]) { barrier.updateRotate(-_deltaTime); }
}

void updateEnemy()
{
	float _deltaTime = deltaTime / CLOCKS_PER_SEC;

	/*
	update enemy position
	*/
	enemy.updateDistance(_deltaTime);
}

void display()
{
	float currentFrame = clock();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	updateBarrier();
	updateEnemy();

	/* draw */
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*
	Outer Barrier
	*/
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	drawBarrier(1.0f, 360);
	glPopMatrix();

	/*
	Inner Barrier
	*/
	glPushMatrix();
	glRotatef(barrier.Rotate, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	drawBarrier(0.3, barrier.AngleBetween);
	glPopMatrix();
	
	/*
	Protect her!
	*/


	/*
	Enemy attacks
	*/
	glPushMatrix();
	//glRotatef(e.degree, 0.0, 0.0, 1.0);
	//glTranslatef(0.0, e.radius, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	drawEnemy();
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}

void arrowkey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		arrow[LEFT] = true;
		break;

	case GLUT_KEY_RIGHT:
		arrow[RIGHT] = true;
		break;
	}
	glutPostRedisplay();
}

void arrowkeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		arrow[LEFT] = false;
		break;

	case GLUT_KEY_RIGHT:
		arrow[RIGHT] = false;
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	keys[key] = true;
	glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y)
{
	keys[key] = false;
	glutPostRedisplay();
}

void Passivemouse(int x, int y)
{
	if (first)
	{
		lastX = x;
		first = false;
	}

	float offsetX = x - lastX;
	lastX = x;

	float _deltaTime = deltaTime / CLOCKS_PER_SEC;
	//rotate -= offsetX * _deltaTime * 1000;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	GLdouble wfactor = (GLdouble)w / (GLdouble)DIM;
	GLdouble hfactor = (GLdouble)h / (GLdouble)DIM;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * wfactor, 1.0 * wfactor, -1.0 * hfactor, 1.0 * hfactor, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	Initialize(argc, argv);


	glutDisplayFunc(display);
	glutSpecialFunc(arrowkey);
	glutSpecialUpFunc(arrowkeyUp);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	//glutPassiveMotionFunc(Passivemouse);
	glutMainLoop();

    return 0;
}