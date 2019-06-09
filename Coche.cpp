#include "Coche.h"




Coche::Coche()
{
	p.x = 0;
	p.y = 0;
	v.x = 0;
	v.y = 0;
	a.x = 0;
	a.y = 0;
	red = green = blue = 255;
	lives = 3;
	indicador = true;
	radio = 2.0f;

}


Coche::~Coche()
{
}

void Coche::Dibuja() {
	glColor3ub(this->red, this->green, this->blue);
	glTranslatef(this->p.x, this->p.y, 0);
	glutSolidTeapot(2);
	glTranslatef(-this->p.x, -this->p.y, 0);
}

bool Coche::Puntos(int v) {
	lives += v;
	if (lives == 0) {
		return true;
	}
	else
		return false;
 
}

