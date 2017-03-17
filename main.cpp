#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace miniwin;

int main()
{
	estado edos[6];
	fTransicion tran;
	const int TPANTALLAX=1024;
	const int TPANTALLAY=640;
//	std::string *nombre[] = {"ABCDEFG"};
	
//	p_nombre=&nombre[0];
	vredimensiona(TPANTALLAX,TPANTALLAY);

edos[1].x=200;
edos[1].y=350;
edos[1].tipo=1;
edos[1].dibujarestado(BLANCO,"A");

edos[2].x=550;
edos[2].y=150;
edos[2].tipo=2;
edos[2].dibujarestado(BLANCO,"B");

edos[3].x=350;
edos[3].y=150;
edos[3].tipo=2;
//edos[3].ID="A";
edos[3].dibujarestado(BLANCO,"C");

edos[4].x=600;
edos[4].y=350;
edos[4].tipo=3;
edos[4].dibujarestado(BLANCO,"D");

edos[5].x=200;
edos[5].y=200;
edos[5].tipo=2;
edos[5].dibujarestado(BLANCO,"E");
tran.funcionT(edos[2],"1",edos[3]);
tran.funcionT(edos[5],"2",edos[5]);
tran.funcionT(edos[1],"2",edos[3]);
tran.funcionT(edos[4],"1",edos[3]);
tran.funcionT(edos[5],"2",edos[3]);
tran.funcionT(edos[5],"2",edos[5]);
tran.funcionT(edos[3],"2",edos[5]);
	refresca();
	return 0;
}



