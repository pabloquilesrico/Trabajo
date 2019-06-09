#include "ListaElementos.h"

ListaElementos::ListaElementos(void)
{
	numero = 0;
	for (int i = 0; i < MAX_ELEMENTOS; i++)
		lista[i] = 0;
}

ListaElementos::~ListaElementos(void)
{

}

bool ListaElementos::agregar(Elemento *elto)
{
	for (int i = 0; i < numero; i++)//para evitar que se añada una elemento ya existente
		if (lista[i] == elto)
			return false;

	if (numero < MAX_ELEMENTOS)
		lista[numero++] = elto;
	else
		return false;
	return true;
}

void ListaElementos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}
/*
void ListaElementos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Movimiento(t);
}
*/


void ListaElementos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaElementos::eliminar(int index)//posición del objeto 
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];

}

void ListaElementos::eliminar(Elemento *co)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == co)
		{
			eliminar(i);
			return;
		}

}

Elemento* ListaElementos::colision(Disparo dis)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(dis, *(lista[i])))
			return lista[i];
	}
	return 0; //no hay colisión
}
Elemento* ListaElementos::colision(Coche co)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), co))
			return lista[i];
	}
	return 0; //no hay colisión
}

Elemento *ListaElementos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}

void ListaElementos::rebote() {
	for (int i = 0; i < numero - 1; i++)
		for (int j = i + 1; j < numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
}

void ListaElementos::rebote(Pared p) {
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}
