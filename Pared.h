
#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Pared
{

	friend class Interaccion;

	Vector2D posicion1;
	Vector2D posicion2;


	Vector2D p1;
	Vector2D p2;
	Vector2D p3;
	Vector2D p4;
	ColorRGB color;

public:
	Pared();
	~Pared();
	//float distancia(Vector2D punto, Vector2D *direccion);
	void setPos(float x1, float z1, float x2, float z2);
	void setPos2(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4);
	void setColor(Byte r, Byte v, Byte a);
	float distancia(Vector2D punto, Vector2D *direccion = 0);
	//tramo curvo
	void dibuja();
	void dibuja2();

};

/*
#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void dibuja();
	void setColor(Byte r, Byte v, Byte a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D *direccion = 0);
private:
	Vector2D limite1;
	Vector2D limite2;
	ColorRGB color;
};
*/