#pragma once
#define MAX_ELEMENTOS 100
#include "Elemento.h"
#include "Circuito.h"
#include "Disparo.h"
#include "Interaccion.h"
#include "Coche.h"

class ListaElementos
{
	friend class Interaccion;
public:
	ListaElementos();
	virtual ~ListaElementos();

	//void mueve(float t);
	void dibuja();

	bool agregar(Elemento* co);
	void eliminar(Elemento* co);
	void eliminar(int index);
	void destruirContenido();

	void rebote();
	void rebote(Pared p);
	Elemento* colision(Disparo dis);
	Elemento* colision(Coche co);

	int getNumero() { return numero; }
	Elemento* operator[] (int index);

private:
	Elemento * lista[MAX_ELEMENTOS];
	int numero;
};
