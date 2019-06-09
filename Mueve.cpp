#include "Mueve.h"

Mueve::Mueve()
{
	p.x = 0.0f;
	p.y = 0.0f;
}


Mueve::~Mueve()
{
}
void Mueve::Movimiento(float t, Vector2D c) {
	Vector2D nuevaPos;			

	float velocidad = v.Modulo();
	float angvelocidad = v.Argumento();
	if (velocidad > 300) {
		velocidad = 300;
	}
	if (velocidad < -300) {
		velocidad = -300;
	}
	v.x = velocidad * cos(angvelocidad);
	v.y = velocidad * sin(angvelocidad);
	v = v + a * t;
	nuevaPos = p + v * t + a * (0.5f * t * t);

	
	if (posValidaX(nuevaPos)) {
		nuevaPos.x = c.x;
	}
	if (posValidaY(nuevaPos)) {
		nuevaPos.y = c.y;
	}

	p = nuevaPos;
	//p = p + v * t + a * (0.5f * t * t);
}
bool Mueve::posValidaX(Vector2D pos) {
	//paredes exterioresX
	if (pos.x < -20.0f && (-60.0f) < pos.y && (0.0f) > pos.y && pos.x < 20.0f) return true;
	if (pos.x > 160.0f && (-60.0f) < pos.y && (100.0f) > pos.y && pos.x > 120.0f) return true;
	if (pos.x > 270.0f && (100.0f) < pos.y && (320.0f) > pos.y && pos.x > 230.0f) return true;
	if (pos.x < -10.0f && (200.0f) < pos.y && (320.0f) > pos.y && pos.x < 30.0f) return true;
	if (pos.x < 70.0f && (200.0f) > pos.y && (120.0f) < pos.y && pos.x < 110.0f) return true;
	if (pos.x < -20.0f && (120.0f) > pos.y && (0.0f) < pos.y && pos.x < 20.0f) return true;

	
	//paredes interioresX
	if (pos.x > 20.0f  && (-20.0f) < pos.y && (0.0f) > pos.y && pos.x < 120.0f) return true;
	if (pos.x < 120.0f && (-20.0f) < pos.y && (140.0f) > pos.y && pos.x > 110.0f) return true;
	if (pos.x < 230.0f && (140.0f) < pos.y && (280.0f) > pos.y && pos.x > 110.0f) return true;
	if (pos.x > 30.0f && (240.0f) < pos.y && (280.0f) > pos.y && pos.x < 120.0f) return true;
	if (pos.x > 110.0f && (80.0f) < pos.y && (240.0f) > pos.y && pos.x < 120.0f) return true;
	if (pos.x > 20.0f && (0.0f) < pos.y && (80.0f) > pos.y && pos.x < 120.0f ) return true;

	return false;
}
bool Mueve::posValidaY(Vector2D pos) {

	//paredes exterioresY
	if (pos.y < -60.0f && (160.0f) > pos.x && (-20.0f) < pos.x && pos.y < -20.0f) return true;
	if (pos.y < 100.0f && (160.0f) < pos.x && (270.0f) > pos.x && pos.y < 140.0f) return true;
	if (pos.y > 320.0f && (270.0f) > pos.x && (-10.0f) < pos.x && pos.y > 280.0f) return true;
	if (pos.y < 200.0f && (70.0f) > pos.x && (-10.0f) < pos.x && pos.y > 120.0f) return true;
	if (pos.y > 120.0f && (70.0f) > pos.x && (-20.0f) < pos.x && pos.y < 200.0f) return true;
	//if (pos.y < limiteparedvertical && min < pos.y && max > pos.y) return true;
	

	//paredes interioresY
	if (pos.y > -20.0f && (120.0f) > pos.x && (20.0f) < pos.x && pos.y < 80.0f) return true;
	if (pos.y > 140.0f && (120.0f) < pos.x && (230.0f) > pos.x && pos.y < 280.0f) return true;
	if (pos.y < 280.0f && (230.0f) > pos.x && (30.0f) < pos.x && pos.y > 240.0f) return true;
	if (pos.y > 240.0f && (110.0f) > pos.x && (30.0f) < pos.x && pos.y < 280.0f) return true;
	if (pos.y < 80.0f && (110.0f) > pos.x && (20.0f) < pos.x && pos.y > -20.0f) return true;
	return false;
}


void Mueve::setVel(float veloz) {

	float angvelocidad = v.Argumento();
	v.x = veloz * cos(angvelocidad);
	v.y = veloz * sin(angvelocidad);

}

void Mueve::setRot(bool der, bool izq, bool *indicador) {
	float velocidad = v.Modulo();
	float angvelocidad = v.Argumento();
	float aceleracion = a.Modulo();
	float angaceleracion = a.Argumento();
	Vector2D newAcc = a.rotar(angvelocidad);

	if (izq) {
		newAcc.y = velocidad * velocidad / 10;
		*indicador = true;
	}
	else if (der) {
		newAcc.y = -velocidad * velocidad / 10;
		*indicador = true;
	}
	else {
		if (*indicador) {
			newAcc.y = 0;
			newAcc.rotar(angvelocidad);
			a = newAcc * 0.75f;
			*indicador = false;
			return;
		}
		else {
			newAcc.y = 0;
			newAcc.rotar(angvelocidad);
			a = a + newAcc * 0.75f;
			return;
		}
		return;
	}

	newAcc.rotar(angvelocidad);
	a = newAcc * 0.75f;
	//x direccion tangencial, y direccion normal 

}


void Mueve::setPos(Vector2D pos)
{
	p = pos;
}

Vector2D Mueve::getPos() {
	return p;
}

Vector2D Mueve::getVel() {
	return v;
}

Vector2D Mueve::getAcel() {
	return a;
}

void Mueve::setAcel(float acel) {

	float angaceleracion = a.Argumento();
	a.x = acel * cos(angaceleracion);
	a.y = acel * sin(angaceleracion);
}
