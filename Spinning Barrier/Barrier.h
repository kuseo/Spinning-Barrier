#ifndef __BARRIER_H__
#define __BARRIER_H__

#include "Enemy.h"

class Barrier
{
public:
	/*
	member variables
	*/
	float Speed;
	float Rotate;
	float AngleBetween;

	/*
	constructor
	*/
	Barrier() : Speed(300.0f), Rotate(0.0f), AngleBetween(90) {}
	Barrier(float speed, float rotate, float AngleBetween) :
		Speed(speed), Rotate(rotate), AngleBetween(AngleBetween) {}

	/*
	member function
	*/
	void updateRotate(float deltaTime) { Rotate += deltaTime * Speed; }
	bool enemyCollide(Enemy enemy)
	{
		/*
		casting float type into int to handle the precision error
		*/
		int rotate_begin = (int)Rotate % 360;
		if (enemy.Rotate >= AngleBetween &&  rotate_begin < 0)
			rotate_begin += 360;
		int rotate_end = rotate_begin + (int)AngleBetween;

		if (!enemy.collide && 25 < (int)(enemy.Distance * 100) && (int)(enemy.Distance * 100) < 30
			&& rotate_begin < (int)enemy.Rotate && int(enemy.Rotate) < rotate_end)
			return true;
		return false;
	}

};
#endif // !__BARRIER_H__
