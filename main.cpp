#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace miniwin;
enum {
INICIAL_ACEPTACION,INICIAL,NORMAL,ACEPTACION
};

int main()
{
	estado edos[20];
	fTransicion tran;
	const int TPANTALLAX=1152;
	const int TPANTALLAY=864;
	int INICIO=80;
	int DX=65;
	int MITADPANTALLAY=trunc(TPANTALLAY/2);
//	std::string *nombre[] = {"ABCDEFG"};
	
//	p_nombre=&nombre[0];
	//obtenerPantalla(TPANTALLAX,TPANTALLAY);
	vredimensiona(TPANTALLAX,TPANTALLAY);

edos[1].x=INICIO;
edos[1].y=MITADPANTALLAY;
edos[1].tipo=INICIAL;
edos[1].dibujarestado(BLANCO,"q1");

edos[2].x=INICIO+DX;
edos[2].y=MITADPANTALLAY;
edos[2].tipo=NORMAL;
edos[2].dibujarestado(BLANCO,"q2");

edos[3].x=INICIO+DX;
edos[3].y=MITADPANTALLAY-DX*3;
edos[3].tipo=NORMAL;
//edos[3].ID="A";
edos[3].dibujarestado(BLANCO,"q3");

edos[4].x=INICIO+DX*2;
edos[4].y=MITADPANTALLAY-DX*3;
edos[4].tipo=NORMAL;
edos[4].dibujarestado(BLANCO,"q4");

edos[5].x=INICIO+DX;
edos[5].y=MITADPANTALLAY+DX*3;
edos[5].tipo=2;
edos[5].dibujarestado(BLANCO,"q5");

edos[6].x=INICIO+DX*2;
edos[6].y=MITADPANTALLAY-DX*5;
edos[6].tipo=2;
edos[6].dibujarestado(BLANCO,"q6");

edos[7].x=INICIO+DX*4;
edos[7].y=MITADPANTALLAY-DX*5;
edos[7].tipo=2;
edos[7].dibujarestado(BLANCO,"q7");

edos[8].x=INICIO+DX*5;
edos[8].y=MITADPANTALLAY-DX*5;
edos[8].tipo=2;
edos[8].dibujarestado(BLANCO,"q8");

edos[9].x=INICIO+DX*4;
edos[9].y=MITADPANTALLAY-DX*3;
edos[9].tipo=2;
edos[9].dibujarestado(BLANCO,"q9");

edos[10].x=INICIO+DX*5;
edos[10].y=MITADPANTALLAY-DX*3;
edos[10].tipo=2;
edos[10].dibujarestado(BLANCO,"q10");

edos[11].x=INICIO+DX*6;
edos[11].y=MITADPANTALLAY-DX*4;
edos[11].tipo=2;
edos[11].dibujarestado(BLANCO,"q11");

edos[12].x=INICIO+DX*2;
edos[12].y=MITADPANTALLAY-DX*2;
edos[12].tipo=NORMAL;
edos[12].dibujarestado(BLANCO,"q12");

edos[13].x=INICIO+DX*6;
edos[13].y=MITADPANTALLAY-DX*2;
edos[13].tipo=NORMAL;
edos[13].dibujarestado(BLANCO,"q13");

edos[14].x=INICIO+DX*7;
edos[14].y=MITADPANTALLAY-DX*3;
edos[14].tipo=NORMAL;
edos[14].dibujarestado(BLANCO,"q14");

edos[15].x=INICIO+DX*2;
edos[15].y=MITADPANTALLAY;
edos[15].tipo=NORMAL;
edos[15].dibujarestado(BLANCO,"q15");
	//refresca();
	
tran.funcionT(edos[1],"r",edos[2]);


tran.funcionT(edos[2],"£",edos[3]);
//Rama 1 superior
tran.funcionT(edos[3],"í",edos[6]);

tran.funcionT(edos[4],"£",edos[12]);
tran.funcionT(edos[12],"o",edos[13]);
tran.funcionT(edos[13],"£",edos[14]);

tran.funcionT(edos[4],"£",edos[8]);
tran.funcionT(edos[5],"e",edos[10]);
tran.funcionT(edos[6],"£",edos[7]);
tran.funcionT(edos[7],"s",edos[8]);
tran.funcionT(edos[8],"£",edos[11]);
tran.funcionT(edos[6],"£",edos[9]);
tran.funcionT(edos[9],"£",edos[10]);
tran.funcionT(edos[10],"£",edos[11]);
tran.funcionT(edos[11],"£",edos[14]);

//tran.funcionT(edos[5],"2",edos[5]);
//tran.funcionT(edos[3],"2",edos[5]);
	refresca();
	return 0;
}



