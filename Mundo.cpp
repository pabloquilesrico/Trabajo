#include "Mundo.h"
#include "Interaccion.h"
#include "Coche.h"
#include "Mueve.h"

Mundo::Mundo() {

}

Mundo::~Mundo() {

}

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}


void Mundo::Dibuja()
{
	if (jugador.getVel().Modulo() != 0)
	SigueCam();
	Lista.dibuja();
	circuito.dibuja();
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	//disparo.Dibuja();
	jugador.Dibuja();

	glPushMatrix();
	glTranslatef(-20.0f, 60.0f, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();
	
	/*
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
	glVertex3f(-100.0f,-100.0f, 0);
	glVertex3f(-100.0f, 100.0f, 0);
	glColor3ub(255,255,0);
	glVertex3f(100.0f, 100.0f, 0);
	glVertex3f(100.0f, -100.0f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	*/
}

void Mundo::Mueve()
{
	jugador.Movimiento(0.0025f, jugador.getPos());
	//Lista.mueve(0.0025f);
	Elemento *aux = Lista.colision(jugador);
	if (aux != 0)
	{
		Lista.eliminar(aux);
		jugador.setVel(100);
		jugador.Puntos(-1);

	}
}

void Mundo::Inicializa()
{
	wp = false;
	ap = false;
	sp = false;
	dp = false;
	x_ojo=0;
	y_ojo=0;
	z_ojo=30;
	for (int i = 0; i < 5; i++) {
		Elemento *aux = new Elemento(20 * i);
		Lista.agregar(aux);
	}
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		jugador.getPos().x, jugador.getPos().y, 0.0,    // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
	ETSIDI::playMusica("musica/pipo.mp3", true);
}

void Mundo::Tecla(unsigned char key) {
	if (key == 'w') wp = true;
	if (key == 's')	sp = true;
    if (key == 'a')	ap = true;	
	if (key == 'd') dp = true;	
}

void Mundo::UnTecla(unsigned char key) {
	if (key == 'w') wp = false;
	if (key == 'a') ap = false;
	if (key == 's') sp = false;
	if (key == 'd') dp = false;
}

void Mundo::Accion() {
	if (wp) {
		jugador.setAcel(500);
		jugador.setRot(false, false, &jugador.indicador);
	}
	if (ap) {
		jugador.setRot(false, true, &jugador.indicador);
	}
	if (sp) {
		jugador.setAcel(-1000);
		jugador.setRot(false, false, &jugador.indicador);
	}
	if (dp) {
		jugador.setRot(true, false, &jugador.indicador);
	}
	if (dp == false && ap == false) {
		jugador.setRot(false, false, &jugador.indicador);
	}

	if (wp == false && ap == false && sp == false && dp == false) {
		jugador.setAcel(0.0);
		jugador.setRot(false, false, &jugador.indicador);
	}
}
void Mundo::SigueCam() {
	
		gluLookAt(jugador.getPos().x - jugador.getVel().Unitario().x*15, jugador.getPos().y -jugador.getVel().Unitario().y*15, 3,  // posicion del ojo
		jugador.getPos().x, jugador.getPos().y, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 0.0, 1.0);      // definimos hacia arriba (eje Z)
		}
