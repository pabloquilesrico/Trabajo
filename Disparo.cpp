#include "Disparo.h"




Disparo::Disparo(float x, float y)
{
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	p.x = x;
	p.y = y;
	radio = 2;

}


Disparo::~Disparo()
{
}

void Disparo::Dibuja() {
	//Disparo
	Color.ponColor();
	glPushMatrix();
	glTranslatef(p.x, p.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-p.x, -p.y, 0);
	glPopMatrix();

	//Estela
	glColor3f(200, 0, 133);
	glBegin(GL_LINES);
	glVertex2d(p.x, p.y);
	glVertex2d(origen.x, origen.y);
	glTranslatef(-p.x, -p.y, 0);
	glEnd();
}

Vector2D Disparo::getOrigen() {
	return p;
}

float Disparo::getRadio() {
	return radio;
}

void Disparo::setColor(Byte r, Byte g, Byte b) {
	Color.set(r, g, b);

}