#pragma once
#include <stdlib.h>
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Mueve.h"


class Disparo : public Mueve
{
	friend class Interaccion;
private:
	ColorRGB Color;
	float radio;
	Vector2D origen;

public:
	Disparo(float x = 0.0f, float y = 0.0f);
	virtual ~Disparo();
	void Dibuja();
	Vector2D getOrigen();
	float getRadio();
	void setColor(Byte r, Byte v, Byte a);
};

