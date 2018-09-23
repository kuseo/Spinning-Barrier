#ifndef __ENEMY_H__
#define __ENEMY_H__

class Enemy
{
public:
	/*
	member variables
	*/
	float Distance = 1.0f;
	float Speed;
	float Rotate;
	bool collide = false;

	/*
	constructor
	*/
	Enemy() : Speed(1.0f), Rotate(0.0f) {}
	Enemy(float speed, float rotate) : Speed(speed), Rotate(rotate) {}

	/*
	member function
	*/
	void updateDistance(float deltaTime) { Distance -= deltaTime * Speed; }
};

#endif // ! __ENEMY_H__

