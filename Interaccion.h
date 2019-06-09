#pragma once
#include "Coche.h"
#include "Circuito.h"
#include "Disparo.h"
#include "Elemento.h"
#include "Pared.h"
#include "math.h"
class Interaccion
{
public:

	Interaccion();
	virtual ~Interaccion();


	static bool rebote(Coche& c, Pared p);
	static bool rebote2(Coche& c, Pared p);
	static void rebote(Coche& c, Circuito cir);
	static bool rebote(Coche& c1, Coche& c2);
	static bool rebote(Elemento &c1, Elemento &c2);
	static bool rebote(Elemento& el, Pared p);


	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Elemento el);
	static bool colision(Disparo d, Circuito cir);
	static bool colision(Disparo d, Coche c);
	static bool colision(Elemento el, Coche c);
	


};