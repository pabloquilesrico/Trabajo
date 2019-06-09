#pragma once
#include <stdlib.h>
#include "mueve.h"
#include "glut.h"


class Elemento :public Mueve
{
	friend class Interaccion;
public:
	Elemento(float x = 20.0f,float y = 20.0f);
	~Elemento();
	void Dibuja();
private:
	float radio;
};
