#include "Interaccion.h"




Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}

bool Interaccion::rebote(Coche &c, Pared p)
{
	
	
	Vector2D dir;
	float dif = p.distancia(c.p, &dir) - c.radio; //ajustar el radio de colisi�n
	if (dif <= 0.0f) {
		Vector2D v_inicial = c.v;
		c.v = v_inicial - dir * 2.0*(v_inicial*dir);
		c.p = c.p - dir * dif;
		return true;
	}
	return false;
	
}



void Interaccion::rebote(Coche& c, Circuito cir) //falta todas las paredes del circuito
{
	
}

bool Interaccion::rebote(Coche &c1, Coche &c2) //ajustar el radio para la colisi�n
{
	//Vector que une los centros
	Vector2D dif = c2.p - c1.p;
	float d = dif.Modulo();
	float dentro = d - (c1.radio + c2.radio);

	if (dentro < 0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = c1.v.Modulo();
		float ang1 = c1.v.Argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = c2.v.Modulo();
		float ang2 = c2.v.Argumento();

		//el argumento del vector que une los centros
		float angd = dif.Argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		c1.p = c1.p + desp;
		c2.p = c2.p - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = c1.radio;
		float m2 = c2.radio;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y*u1y + m2 * u2y*u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py*m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a*c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x*v1x + v1y * v1y);
		modv2 = sqrt(v2x*v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		c1.v.x = modv1 * cos(fi1);
		c1.v.y = modv1 * sin(fi1);
		c2.v.x = modv2 * cos(fi2);
		c2.v.y = modv2 * sin(fi2);
	}
	return false;
}


bool Interaccion::colision(Disparo d, Coche c)
{
	Pared aux;
	Vector2D p1 = d.getPos();
	Vector2D p2 = d.getOrigen();
	aux.setPos(p1.x, p1.y, p2.x, p2.y);
	float dist = aux.distancia(c.p);
	if (dist < c.radio)
		return true;
	return false;
}

bool Interaccion::colision(Elemento el, Coche c)
{
	Vector2D dif = c.p - el.p;
	float d = dif.Modulo();
	float dentro = d - (el.radio*0.7 + c.radio*0.5);
	if (dentro < 0.0f)
		return true;
	else
		return false;
}

bool Interaccion::colision(Disparo d, Pared p)
{
	Vector2D pos = d.getPos();
	float dist = p.distancia(pos);
	if (dist < d.getRadio())
		return true;
	return false;
}

bool Interaccion::colision(Disparo d, Elemento el) {
	Vector2D dif = d.p - el.p;
	float di = dif.Modulo();
	float dentro = di - (el.radio + d.radio);
	if (dentro < 0.0f)
		return true;
	else
		return false;
}

bool Interaccion::rebote(Elemento& el, Pared p) {
	Vector2D dir;
	float dif = p.distancia(el.p, &dir) - el.radio; //ajustar el radio de colisi�n
	if (dif <= 0.0f) {
		Vector2D v_inicial = el.v;
		el.v = v_inicial - dir * 2.0*(v_inicial*dir);
		el.p = el.p - dir * dif;
		return true;
	}
	return false;
}
bool Interaccion::rebote(Elemento &c1, Elemento &c2) //ajustar el radio para la colisi�n
{
	//Vector que une los centros
	Vector2D dif = c2.p - c1.p;
	float d = dif.Modulo();
	float dentro = d - (c1.radio + c2.radio);

	if (dentro < 0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = c1.v.Modulo();
		float ang1 = c1.v.Argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = c2.v.Modulo();
		float ang2 = c2.v.Argumento();

		//el argumento del vector que une los centros
		float angd = dif.Argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		c1.p = c1.p + desp;
		c2.p = c2.p - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = c1.radio;
		float m2 = c2.radio;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y*u1y + m2 * u2y*u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py*m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a*c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x*v1x + v1y * v1y);
		modv2 = sqrt(v2x*v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		c1.v.x = modv1 * cos(fi1);
		c1.v.y = modv1 * sin(fi1);
		c2.v.x = modv2 * cos(fi2);
		c2.v.y = modv2 * sin(fi2);
	}
	return false;
}