#ifndef __BARRIER_H__
#define __BARRIER_H__

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


};
#endif // !__BARRIER_H__
