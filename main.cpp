#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace miniwin;

int main()
{
	estado edos[3];
	fTransicion tran;
	vredimensiona(800,480);

edos[1].x=200;
edos[1].y=100;
edos[1].tipo=1;
//edos[1].colorN=BLANCO;
edos[1].nombre="C";
edos[1].dibujarestado(BLANCO);

edos[2].x=550;
edos[2].y=350;
edos[2].tipo=2;
//edos[2].colorN=BLANCO;
edos[2].nombre="D";
edos[2].dibujarestado(MAGENTA);

edos[3].x=350;
edos[3].y=250;
edos[3].tipo=2;
//edos[3].colorN=BLANCO;
edos[3].nombre="A";
edos[3].dibujarestado(BLANCO);

tran.funcionT(edos[1],"1",edos[2]);
tran.funcionT(edos[1],"2",edos[3]);

	refresca();
	return 0;
}





