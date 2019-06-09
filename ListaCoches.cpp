#include "ListaCoches.h"
ListaCoches::ListaCoches(void)
{
	numero = 0;
	for (int i = 0; i < MAX_ELEMENTOS; i++)
		lista[i] = 0;
}

ListaCoches::~ListaCoches(void)
{

}

bool ListaCoches::agregar(Coche *c)
{
	for (int i = 0; i < numero; i++)//para evitar que se añada una elemento ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_ELEMENTOS)
		lista[numero++] = c;
	else
		return false;
	return true;
}

void ListaCoches::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaCoches::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaCoches::eliminar(int index)//posición del objeto 
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];

}

void ListaCoches::eliminar(Coche *co)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == co)
		{
			eliminar(i);
			return;
		}

}
/*
void ListaCoches::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Movimiento(t);
}
*/
Coche* ListaCoches::colision(Disparo dis, Coche co)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(dis, *(lista[i])))
			return lista[i];
	}
	return 0; //no hay colisión
}
Coche* ListaCoches::colision(Elemento elto, Coche co)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(elto, *(lista[i])))
			return lista[i];
	}
	return 0; //no hay colisión
}

Coche *ListaCoches::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}

void ListaCoches::rebote() {
	for (int i = 0; i < numero - 1; i++)
		for (int j = i + 1; j < numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
}

void ListaCoches::rebote(Pared p) {
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}