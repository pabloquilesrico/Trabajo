#pragma once
#include "ETSIDI.h"
#include "ListaElementos.h"
#include "Disparo.h"
#include "Elemento.h"
#include "Vector2D.h"
#include "Coche.h"
#include "Mueve.h"
#include "Circuito.h"
#include <math.h>
#include "glut.h"

class Mundo
{
	Circuito circuito;
	Disparo disparo;
	Coche jugador;
	ListaElementos Lista;
public: 
	Mundo();
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void UnTecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void SigueCam();
	void Accion();
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool wp;
	bool ap;
	bool sp;
	bool dp;
};
