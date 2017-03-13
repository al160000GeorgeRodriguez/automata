#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace miniwin;

int main()
{
	estado edos[5];
	fTransicion tran;
	const int TPANTALLAX=1024;
	const int TPANTALLAY=640;
	
	vredimensiona(TPANTALLAX,TPANTALLAY);

edos[1].x=200;
edos[1].y=350;
edos[1].tipo=1;
edos[1].dibujarestado(BLANCO,"C");

edos[2].x=550;
edos[2].y=150;
edos[2].tipo=2;
edos[2].dibujarestado(MAGENTA,"D");

edos[3].x=350;
edos[3].y=250;
edos[3].tipo=2;
edos[3].dibujarestado(BLANCO,"A");

edos[4].x=550;
edos[4].y=350;
edos[4].tipo=3;
edos[4].dibujarestado(BLANCO,"F");

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
	refresca();
	return 0;
}



