#pragma once
#include "Mundo.h"




class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void tecla(unsigned char key);
	void Untecla(unsigned char key);
	void mueve();
	void dibuja();
	void accion();
	enum Estado {INICIO, MENU, JUEGO, GAME_OVER};
	Estado estado;
	Mundo mundo;
};

