#include "Bonus.h"



Bonus::Bonus()
{
	//movimiento gravitatorio
	//velocidad vertical inicial
	a.y = -9.8f;
	v.y = 5;
	lado = 0.5f;
}

Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(p.x, p.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX);
	glutSolidCube(lado);
	glPopMatrix();

}
