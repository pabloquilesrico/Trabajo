#include "Vector2D.h"


Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}


Vector2D::~Vector2D()
{
}

float Vector2D::Modulo() {
	return (float)sqrt(x * x + y * y);
}

float Vector2D::Argumento(bool rad) {
	if (rad == true) 
			return (float)atan2(y, x);
	
	else if (rad == false)
			return (float)(180/3.14159)*atan2(y, x);
	
}

Vector2D Vector2D::Unitario() {
	Vector2D retorno(x, y);
	float mod = Modulo();
	if (mod > 0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D &v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D &v) {
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

//Producto escalar
float Vector2D::operator * (Vector2D &v) {

	return x * v.x + y * v.y;

}

//Producto vectorial xd
Vector2D Vector2D::operator * (float v) {
	Vector2D res;
	res.x = x * v;
	res.y = y * v;
	return res;
}

Vector2D& Vector2D::rotar(float th) {
	float x_ = x;
	float y_ = y;

	x = x_ * cos(th) - y_ * sin(th);
	y = x_ * sin(th) + y_ * cos(th);
	return *this;
}


