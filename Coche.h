#pragma once
#include "Vector2D.h"
#include "Mueve.h"
#include <stdlib.h>
#include <math.h>
#include "glut.h"
#include "Mueve.h"
class Coche : public Mueve
{
	friend class Interaccion;

private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	int lives;
	float radio;


public:
	Coche();
	~Coche();
	void Dibuja();
	bool indicador;
	bool Puntos(int v);
};

