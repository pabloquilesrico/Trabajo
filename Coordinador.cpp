#include "Coordinador.h"



Coordinador::Coordinador()
{
	estado = INICIO;
}


Coordinador::~Coordinador()
{
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/AVENGERS.ttf", 30);
		ETSIDI::printxy("CYBERTAZASIMULATOR 2077", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/AVENGERS.ttf", 20);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 4);
	}
	else if (estado == JUEGO){
		mundo.Dibuja();
	}
	else if (estado == GAME_OVER) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/AVENGERS.ttf", 30);
		ETSIDI::printxy("FIN DEL JUEGO", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/AVENGERS.ttf", 20);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
	}
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == 'e' || key == 'E')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 's' || key == 'S')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
	}
}

void Coordinador::Untecla(unsigned char key)
{
	if (estado == JUEGO)
	{
		mundo.UnTecla(key);
	}
	else
		return;
}

void Coordinador::accion() {
	if (estado == INICIO) {
		return;
	}
	else if (estado == JUEGO)
		mundo.Accion();
}
void Coordinador::mueve()
{
	if (estado == JUEGO)
		mundo.Mueve();
	else  {
		return;
	}
}