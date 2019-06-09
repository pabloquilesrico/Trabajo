#pragma once
#include "Vector2D.h"
#include "Pared.h"

class Circuito
{
	friend class Interaccion;
public:
	Circuito();
	virtual ~Circuito();
	void dibuja();

	Pared int_recta1;
	Pared int_recta2;
	Pared int_recta3;
	Pared int_recta4;
	Pared int_recta5;
	Pared int_recta6;
	Pared int_recta7;
	Pared int_recta8;
	Pared int_recta9;
	Pared int_recta10;
	Pared int_recta11;

	Pared ext_recta1;
	Pared ext_recta2;
	Pared ext_recta3;
	Pared ext_recta4;
	Pared ext_recta5;
	Pared ext_recta6;
	Pared ext_recta7;
	Pared ext_recta8;
	Pared ext_recta9;
	Pared ext_recta10;
	Pared ext_recta11;

	Pared suelo_recta1;
	Pared suelo_recta2;
	Pared suelo_recta3;
	Pared suelo_recta4;
	Pared suelo_recta5;
	Pared suelo_recta6;
	Pared suelo_recta7;
	Pared suelo_recta8;
	Pared suelo_recta9;
	Pared suelo_recta10;
	Pared suelo_recta11;
};
