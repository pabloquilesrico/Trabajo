

#include "Circuito.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Circuito::Circuito()
{
	ext_recta1.setPos(-20.0f, 0.0f, -20.0f, -60.0f);
	ext_recta2.setPos(-20.0f, -60.0f, 160.0f, -60.0f);
	ext_recta3.setPos(160.0f, -60.0f, 160.0f, 100.0f);
	ext_recta4.setPos(160.0f, 100.0f, 270.0f, 100.0f);
	ext_recta5.setPos(270.0f, 100.0f, 270.0f, 320.0f);
	ext_recta6.setPos(270.0f, 320.0f, -10.0f, 320.0f);
	ext_recta7.setPos(-10.0f, 320.0f, -10.0f, 200.0f);
	ext_recta8.setPos(-10.0f, 200.0f, 70.0f, 200.0f);
	ext_recta9.setPos(70.0f, 200.0f, 70.0f, 120.0f);
	ext_recta10.setPos(70.0f, 120.0f, -20.0f, 120.0f);
	ext_recta11.setPos(-20.0f, 120.0f, -20.0f, 0.0f);



	int_recta1.setPos(20.0f, 0.0f, 20.0f, -20.0f);
	int_recta2.setPos(20.0f, -20.0f, 120.0f, -20.0f);
	int_recta3.setPos(120.0f, -20.0f, 120.0f, 140.0f);
	int_recta4.setPos(120.0f, 140.0f, 230.0f, 140.0f);
	int_recta5.setPos(230.0f, 140.0f, 230.0f, 280.0f);
	int_recta6.setPos(230.0f, 280.0f, 30.0f, 280.0f);
	int_recta7.setPos(30.0f, 280.0f, 30.0f, 240.0f);
	int_recta8.setPos(30.0f, 240.0f, 110.0f, 240.0f);
	int_recta9.setPos(110.0f, 240.0f, 110.0f, 80.0f);
	int_recta10.setPos(110.0f, 80.0f, 20.0f, 80.0f);
	int_recta11.setPos(20.0f, 80.0f, 20.0f, 0.0f);


	suelo_recta1.setPos2(-20.0f, 0.0f, -20.0f, -60.0f, 20.0f, -20.0f, 20.0f, 0.0f);
	suelo_recta2.setPos2(20.0f, -20.0f, -20.0f, -60.0f, 160.0f, -60.0f, 120.0f, -20.0f);
	suelo_recta3.setPos2(120.0f, -20.0f, 160.0f, -60.0f, 160.0f, 100.0f, 120.0f, 140.0f);
	suelo_recta4.setPos2(120.0f, 140.0f, 160.0f, 100.0f, 270.0f, 100.0f, 230.0f, 140.0f);
	suelo_recta5.setPos2(230.0f, 140.0f, 270.0f, 100.0f, 270.0f, 320.0f, 230.0f, 280.0f);
	suelo_recta6.setPos2(230.0f, 280.0f, 270.0f, 320.0f, -10.0f, 320.0f, 30.0f, 280.0f);
	suelo_recta7.setPos2(30.0f, 280.0f, -10.0f, 320.0f, -10.0f, 200.0f, 30.0f, 240.0f);
	suelo_recta8.setPos2(30.0f, 240.0f, -10.0f, 200.0f, 70.0f, 200.0f, 110.0f, 240.0f);
	suelo_recta9.setPos2(110.0f, 240.0f, 70.0f, 200.0f, 70.0f, 120.0f, 110.0f, 80.0f);
	suelo_recta10.setPos2(110.0f, 80.0f, 70.0f, 120.0f, -20.0f, 120.0f, 20.0f, 80.0f);
	suelo_recta11.setPos2(20.0f, 80.0f, -20.0f, 120.0f, -20.0f, 0.0f, 20.0f, 0.0f);
}

Circuito::~Circuito()
{


}

void Circuito::dibuja()
{
	ext_recta1.dibuja();
	ext_recta2.dibuja();
	ext_recta3.dibuja();
	ext_recta4.dibuja();
	ext_recta5.dibuja();
	ext_recta6.dibuja();
	ext_recta7.dibuja();
	ext_recta8.dibuja();
	ext_recta9.dibuja();
	ext_recta10.dibuja();
	ext_recta11.dibuja();

	int_recta1.dibuja();
	int_recta2.dibuja();
	int_recta3.dibuja();
	int_recta4.dibuja();
	int_recta5.dibuja();
	int_recta6.dibuja();
	int_recta7.dibuja();
	int_recta8.dibuja();
	int_recta9.dibuja();
	int_recta10.dibuja();
	int_recta11.dibuja();

	suelo_recta1.dibuja2();
	suelo_recta2.dibuja2();
	suelo_recta3.dibuja2();
	suelo_recta4.dibuja2();
	suelo_recta5.dibuja2();
	suelo_recta6.dibuja2();
	suelo_recta7.dibuja2();
	suelo_recta8.dibuja2();
	suelo_recta9.dibuja2();
	suelo_recta10.dibuja2();
	suelo_recta11.dibuja2();

}