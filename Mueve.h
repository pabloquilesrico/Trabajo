#pragma once
#include <stdlib.h>
#include <math.h>
#include "Vector2D.h"

class Mueve
{
public:
	Mueve(void);
	virtual ~Mueve(void);
	virtual void Movimiento(float t, Vector2D c);
	
	bool posValidaX(Vector2D pos);
	bool posValidaY(Vector2D pos);
	
	Vector2D getPos();
	Vector2D getVel();
	Vector2D getAcel();
	void setVel(float veloz = 0.0f);
	void setPos(Vector2D pos);
	void setAcel(float acel = 0.0f);
	void setRot(bool der, bool izq, bool *indicador);
protected:
	Vector2D p;
	Vector2D v;
	Vector2D a;
};