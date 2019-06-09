#pragma once
#include <math.h>
class Vector2D
{
public:

	float x;
	float y;
public:
	Vector2D(float xv = 1.0f, float yv = 0.0f);
	virtual ~Vector2D();
	float Modulo();
	float Argumento(bool rad = true);
	Vector2D Unitario(); //Vector unitario
	Vector2D operator - (Vector2D &);
	Vector2D operator + (Vector2D &);
	float operator * (Vector2D &); //Producto escalar
	Vector2D operator * (float); //Producto por un escalar
	Vector2D& rotar(float th);
};

