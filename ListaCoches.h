#pragma once
#define MAX_ELEMENTOS 100
#include "Elemento.h"
#include "Circuito.h"
#include "Disparo.h"
#include "Interaccion.h"
#include "Coche.h"

class ListaCoches
{
	friend class Interaccion;
public:
	ListaCoches();
	virtual ~ListaCoches();

	void mueve(float t);
	void dibuja();

	bool agregar(Coche* co);
	void eliminar(Coche* co);
	void eliminar(int index);
	void destruirContenido();

	void rebote();
	void rebote(Pared p);
	Coche* colision(Disparo dis, Coche co);
	Coche* colision(Elemento elto, Coche co);

	int getNumero() { return numero;}
	Coche* operator[] (int index);

private:
	Coche * lista[MAX_ELEMENTOS];
	int numero;
};

