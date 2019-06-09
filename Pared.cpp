#include "Pared.h"
#include "glut.h"
#include <math.h>


Pared::Pared()
{

}


Pared::~Pared()
{
}


void Pared::setPos(float x1, float z1, float x2, float z2) {

	posicion1.x = x1;
	posicion1.y = z1;
	posicion2.x = x2;
	posicion2.y = z2;
}

void Pared::setPos2(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4) {

	p1.x = x1;
	p1.y = z1;
	p2.x = x2;
	p2.y = z2;
	p3.x = x3;
	p3.y = z3;
	p4.x = x4;
	p4.y = z4;
}


void Pared::dibuja() {

	glDisable(GL_LIGHTING);
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(posicion1.x, posicion1.y, 0.0f);
	glVertex3f(posicion1.x, posicion1.y, 10.0f);
	glVertex3f(posicion2.x, posicion2.y, 10.0f);
	glVertex3f(posicion2.x, posicion2.y, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glFlush();

}

void Pared::dibuja2() {

	glDisable(GL_LIGHTING);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(p1.x, p1.y, 0.0f);
	glVertex3f(p2.x, p2.y, 0.0f);
	glVertex3f(p3.x, p3.y, 0.0f);
	glVertex3f(p4.x, p4.y, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glFlush();
}



float Pared::distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - posicion1);
	Vector2D v = (posicion2 - posicion1).Unitario();
	float longitud = (posicion1 - posicion2).Modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - posicion2);
	else
		dir = u - v * valor;
	distancia = dir.Modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.Unitario();
	return distancia;
}
