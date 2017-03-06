#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace miniwin;

const double PI=3.14159265358979;
const int Tcirculo=20;
float RGrados(float radian); /*convierte radianes a grados*/
float GRadian(float grados); /*convierte grados a radianes*/
void rectangularPolar(float x1, float y1, float x2, float y2,float &magnitud,float &direccion); /* Convierte un par de coordenadas cartesianas a un sistema polar*/
void polarRectangular(float x1, float y1, float magnitud,float direccion,float &x2, float &y2); /* Obtiene el punto final de un sistemas de coordenadas de un sistema polar con origen x1, y1 a */
void LineaPolar(float x1, float y1, float magnitud,float direccion);/* genera una línea introduciendo el puto inicial, la magnitud y el ángulo*/
void trianguloflecha(float x1, float y1, float radio, float angulo);
void triangulo(float x1, float y1, float radio, float angulo);/* genera un triangulo inscrito con uno de sus vertices en 0 grados*/
void flecha(float x1, float y1, float x2, float y2);/* genera una flecha, ésta servirá para enlazar nodos*/

transicion::transicion()
{
	x1=0;
	y1=0;
	x2=0;
	y2=0;
	colorPunta=colorLinea=BLANCO;
	tex="";
}

void transicion::flecha()
{
	float magn,dire,xaux,yaux,xaux2,yaux2;
	rectangularPolar(x1,y1,x2,y2,magn,dire);
	if ((x2-x1)<0) dire=dire+GRadian(180);
	polarRectangular(x1,y1,Tcirculo,dire,xaux,yaux);
	polarRectangular(x1,y1,magn-(Tcirculo+5),dire,xaux2,yaux2);
	color(colorLinea);	
	linea(xaux,yaux,xaux2,yaux2);
	color(colorPunta);
	trianguloflecha(xaux2,yaux2,5,dire);
	polarRectangular(x1,y1,magn*.5,dire,xaux,yaux);
	texto(xaux+3,yaux+3,tex);
}

estado::estado()
{
	x=y=0;
	tipo=1;
	colorN=BLANCO;
	nombre="";
	}
void estado::dibujarestado(int color)
{
	colorN=color;
	switch(tipo)
	{
	case 1:	Inicial(); 
	break;
	case 2: Normal();
	break;
	case 3: Aceptacion();
	break;
	}
}

void estado::Inicial()
{
	flecha(x-(Tcirculo+55),y,x-(Tcirculo+5),y);
	color(colorN);
	circulo(x,y,Tcirculo);
	texto(x-65,y-15,"Inicio");
	texto(x-4,y-8,nombre);	
}

void estado::Normal()
{
	color(colorN);
	circulo(x,y,Tcirculo);
	texto(x-4,y-8,nombre);	
}
void estado::Aceptacion()
{
	color(colorN);
	circulo(x,y,Tcirculo);
	circulo(x,y,Tcirculo-3);
	texto(x-4,y-8,nombre);
}


fTransicion::fTransicion()
{
	/*edoOrigen.x=100;
	edoOrigen.y=100;
	
	edoOrigen.tipo=1;
	edoOrigen.nombre="A";
	edoDestino.x=200;
	edoDestino.y=200;
	
	edoDestino.tipo=2;
	edoDestino.nombre="B";*/
	}
	
void fTransicion::funcionT(estado edoOrigen, char *cadena, estado edoDestino)
{
enlace.x1=edoOrigen.x;
enlace.y1=edoOrigen.y;
edoOrigen.colorN=BLANCO;	
enlace.x2=edoDestino.x;
enlace.y2=edoDestino.y;
edoDestino.colorN=BLANCO;
enlace.tex=cadena;
enlace.flecha();

}

float RGrados(float radian)
{
return radian*180/PI;
	
}
float GRadian(float grados)
{
return grados*PI/180;	
}
void rectangularPolar(float x1, float y1, float x2, float y2,float &magnitud,float &direccion)
{
	float xdif,ydif;
	xdif=(x2-x1);
	ydif=-(y2-y1);
	magnitud= sqrt(xdif*xdif+ydif*ydif);
	if (xdif!=0) direccion=atan(ydif/xdif);	
	else 
		if (ydif>0) direccion=PI/2;
		else direccion=(3/2)*PI;
}


void polarRectangular(float x1, float y1, float magnitud,float direccion,float &x2, float &y2)
{
	x2=x1+magnitud*cos(direccion);
	y2=y1-magnitud*sin(direccion);
}

void trianguloflecha(float x1, float y1, float radio, float angulo)
{
	float xt1,yt1,xt2,yt2,xt3,yt3;
	polarRectangular(x1,y1,radio,angulo,xt1,yt1);
	polarRectangular(x1,y1,radio,angulo+GRadian(150),xt2,yt2);
	polarRectangular(x1,y1,radio,angulo-GRadian(150),xt3,yt3);
	linea(xt1,yt1,xt2,yt2);
	linea(xt2,yt2,xt3,yt3);
	linea(xt3,yt3,xt1,yt1);
}
void triangulo(float x1, float y1, float radio, float angulo)
{
	float xt1,yt1,xt2,yt2,xt3,yt3;
	polarRectangular(x1,y1,radio,angulo,xt1,yt1);
	polarRectangular(x1,y1,radio,angulo+GRadian(120),xt2,yt2);
	polarRectangular(x1,y1,radio,angulo-GRadian(240),xt3,yt3);
	linea(xt1,yt1,xt2,yt2);
	linea(xt2,yt2,xt3,yt3);
	linea(xt3,yt3,xt1,yt1);
}
void LineaPolar(float x1, float y1, float magnitud,float direccion)
{
float xt1,yt1;
	polarRectangular(x1,y1,magnitud,direccion,xt1,yt1);
	linea(x1,y1,xt1,yt1);	
}

void flecha(float x1, float y1, float x2, float y2)
{
	float magnitudv,direccionv;

	color(GRISO);	
	linea(x1,y1,x2,y2);
	color(BLANCO);
	rectangularPolar(x1,y1,x2,y2,magnitudv,direccionv);
//	LineaPolar(x1+50,y1+50,magnitudv,direccionv);
	if ((x2-x1)<0) direccionv=direccionv+GRadian(180);
//	LineaPolar(x1+50,y1+50,magnitudv,direccionv);

	trianguloflecha(x2,y2,5,direccionv);
}
