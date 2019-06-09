#include "Elemento.h"



Elemento::Elemento(float x, float y)
{
	p.x = x;
	p.y = y;
	radio = 20.0f;

}


Elemento::~Elemento()
{
}

void Elemento::Dibuja() {
	glPushMatrix();
	glTranslatef(p.x, p.y, 0);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX);
	glutSolidCube(radio);
	glPopMatrix();
}