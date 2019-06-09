#pragma once
#include "Mueve.h"
#include <stdlib.h>
#include "glut.h"

class Bonus : public Mueve
{
	friend class Interaccion;
public:

	void dibuja();
	Bonus();
	virtual ~Bonus();
private:
	float lado;
};
