#include "miniwin.h"
#include "base.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include <queue>
#include <process.h>
#include <windows.h>
#include <windowsx.h>
using namespace miniwin;

int contador1,contador2=0;


enum {
NONE,NORMAL,INICIAL,ACEPTACION
};
enum {
	REFLEXIVO,NO_SIMETRICO,SIMETRICO
};
const double PI=3.14159265358979;
const int TCIRCULO=15;

float RGrados(float radian); /*convierte radianes a grados*/
float GRadian(float grados); /*convierte grados a radianes*/
void rectangularPolar(float x1, float y1, float x2, float y2,float &magnitud,float &direccion); /* Convierte un par de coordenadas cartesianas a un sistema polar*/
void polarRectangular(float x1, float y1, float magnitud,float direccion,float &x2, float &y2); /* Obtiene el punto final de un sistemas de coordenadas de un sistema polar con origen x1, y1 a */
void LineaPolar(float x1, float y1, float magnitud,float direccion);/* genera una línea introduciendo el puto inicial, la magnitud y el ángulo*/
void trianguloflecha(float x1, float y1, float radio, float angulo); /*Ajusta la dirección del triangulo hacia una dirección*/
void triangulo(float x1, float y1, float radio, float angulo);/* genera un triangulo inscrito con uno de sus vertices en 0 grados*/
void flecha(float x1, float y1, float x2, float y2);/* genera una flecha, ésta servirá para enlazar nodos*/
void bezier(int x0,int y0,int x1,int y1,int x2,int y2); /*Genera una curva de bezier para tres puntos*/
void bezier(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3);/*Genera una curva de bezier para cuatro puntos, función sobrecargada*/
char *numATexto(float numero);


eregular::eregular()
{
	
 } 
void eregular::dibujar()
{
	
 } 
transicion::transicion()
{
	x1=0;
	y1=0;
	x2=0;
	y2=0;
	colorPunta=colorLinea=BLANCO;
	//flecha(" ",REFLEXIVO);
}

void transicion::flecha(const std::string& tex, int tipo) //Es una flecha con el nombre del nodo a mostrar y el tipo de flecha
	{
		if (tipo==REFLEXIVO)	{
			
			float magn,dire,dire2,desfase, proporcion,xaux,yaux,xaux2,yaux2,xaux3,yaux3,xaux4,yaux4;
			
			//rectangularPolar(x1,y1,x2,y2,magn,dire);
			//if ((x2-x1)<0) dire=dire+GRadian(180);
			desfase=20; //desfase del angulo principal
			proporcion=4;// Proporción del tamaño del circulo
			dire=dire2=GRadian(90);
			polarRectangular(x1,y1,TCIRCULO,dire+GRadian(desfase),xaux,yaux); //la primera coordenada es el limite de la circunferencia a 100 grados
			polarRectangular(x1,y1,TCIRCULO*proporcion,dire+GRadian(desfase),xaux2,yaux2);  //la segunda coordenada es dos veces el tamaño de la circunferencia a 100 grados
			polarRectangular(x1,y1,TCIRCULO*proporcion,dire-GRadian(desfase),xaux3,yaux3);  //la tercera coordenada es dos veces el tamaño es el limite de la circunferencia a 80 grados
			polarRectangular(x1,y1,TCIRCULO+5,dire-GRadian(desfase),xaux4,yaux4);//la última coordenada es el limite de la circunferencia más 5 por la punta de la flecha a 80 grados
			color(colorLinea);	
			bezier(xaux,yaux,xaux2,yaux2,xaux3,yaux3,xaux4,yaux4);
			//linea(xaux,yaux,xaux2,yaux2);
			color(colorPunta);
			rectangularPolar(xaux3,yaux3,xaux4,yaux4,magn,dire);
			if ((xaux4-xaux3)<0) dire=dire+GRadian(180);
			trianguloflecha(xaux4,yaux4,5,dire);  //Coloca la punta de la flecha
			
			polarRectangular(x1,y1,TCIRCULO*(proporcion+.2),dire2,xaux,yaux); //Identifica las coordenadas del texto
			texto(xaux-3,yaux,tex.c_str());
		}
		
		else
		{
			//if 
			float magn,dire,xaux,yaux,xaux2,yaux2;
			magn=dire=xaux=yaux=xaux2=yaux2=0;
			rectangularPolar(x1,y1,x2,y2,magn,dire);
			if ((x2-x1)<0) dire=dire+GRadian(180);
			polarRectangular(x1,y1,TCIRCULO,dire,xaux,yaux);
			polarRectangular(x1,y1,magn-(TCIRCULO+5),dire,xaux2,yaux2);
			color(colorLinea);	
			linea(xaux,yaux,xaux2,yaux2);
			color(colorPunta);
			trianguloflecha(xaux2,yaux2,5,dire);   //Coloca la punta de la flecha
			polarRectangular(x1,y1,magn*.5,dire,xaux,yaux); //Identifica las coordenadas del texto
			texto(xaux+3,yaux+3,tex.c_str());
		}
	}

estado::estado()
{
	x=y=0;
	simetrico=reflexivo=false;
	tipo=1;
	colorN=BLANCO;
	dibujarestado(colorN," "); 
	}
void estado::dibujarestado(int color,const std::string &nombre)
{

	colorN=color;
	ID=(char *)nombre.c_str();  //Forza la conversión de tipos para asignar la variable ID
//	strcpy(ID,nombre.c_str());
   // texto(55+contador1,450,edoOrigen.ID);
   contador1+=50;
				texto(75+contador1,350,ID);
	switch(tipo)
	{
	case 1:	Inicial(nombre.c_str()); 
	break;
	case 2: Normal(nombre.c_str());
	break;
	case 3: Aceptacion(nombre.c_str());
	break;
	}
}

void estado::Inicial(const std::string& nom)
{
	
	flecha(x-(TCIRCULO+55),y,x-(TCIRCULO+5),y);
	color(colorN);
	circulo(x,y,TCIRCULO);
	texto(x-65,y-15,"Inicio");
	texto(x-4,y-8,nom.c_str());	
}

void estado::Normal(const std::string& nom)
{
	color(colorN);
	circulo(x,y,TCIRCULO);
	texto(x-4,y-8,nom.c_str());	
}
void estado::Aceptacion(const std::string& nom)
{
	color(colorN);
	circulo(x,y,TCIRCULO);
	circulo(x,y,TCIRCULO-3);
	texto(x-4,y-8,nom.c_str());
}


fTransicion::fTransicion()
{
	/*edoOrigen.x=100;
	edoOrigen.y=100;
	
	edoOrigen.tipo=1;
	edoOrigen.nombre="A";
	edoDestino.x=200;
	edoDestino.y=200;char *cadena
	
	edoDestino.tipo=2;
	edoDestino.nombre="B";*/
	}
	
	bool fTransicion::comprobarReflexion(estado Origen, estado Destino )
		{
			
			if ((Origen.x==Destino.x) & (Destino.y==Origen.y))
			{
				return true;
			}
		}
	bool fTransicion::comprobarSimetria(estado Origen, estado Destino )
	{
		
		for (int i=0;strlen(Origen.entrantes);i++)
		{
			if (Origen.entrantes[i]==*Destino.ID){
				return true;
			}
		}
	}
		
	void fTransicion::funcionT(estado edoOrigen,const std::string& cadena, estado edoDestino)
		{
				
				enlace.x1=edoOrigen.x;
				enlace.y1=edoOrigen.y;
				edoOrigen.colorN=BLANCO;	
				enlace.x2=edoDestino.x;
				enlace.y2=edoDestino.y;
				edoDestino.colorN=BLANCO;
					contador1=contador1+50;
				texto(50+contador1,450,"(");
				texto(55+contador1,450,edoOrigen.ID);
				texto(75+contador1,450,edoDestino.ID);
				texto(90+contador1,450,")");
				texto(55+contador1,500,edoOrigen.entrantes);
				texto(175+contador1,500,edoDestino.salientes);
				strcat(edoOrigen.entrantes,edoOrigen.ID);   //Guarda el ID del nodo para su comparación posterior
				strcat(edoDestino.salientes,edoDestino.ID);
			
				
				if (!(edoOrigen.reflexivo)) {
				edoOrigen.reflexivo=comprobarReflexion(edoOrigen,edoDestino);
				}
				
			if (comprobarReflexion(edoOrigen,edoDestino))
				{
					enlace.flecha(cadena.c_str(),REFLEXIVO);
					texto(10+contador1,400,"R");
					
				//	texto(10+contador1,400,cordx);
					contador1=contador1+50;
				}
				else
				 {
						if(comprobarSimetria(edoOrigen,edoDestino)){
							enlace.flecha(cadena.c_str(),NO_SIMETRICO);	
							texto(10+contador1,400,"NS");
							contador1=contador1+50;
						}
						else 
						{
							enlace.flecha(cadena.c_str(),SIMETRICO);	
							texto(10+contador1,400,"S");
							contador1=contador1+50;
						}
				
				}
						
		}

float RGrados(float radian) //Convierte una cantidad de  radianes a grados
{
return radian*180/PI;
	
}
float GRadian(float grados) //Convierte una cantidad en grados a radianes
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

void bezier(int x0,int y0,int x1,int y1,int x2,int y2)
{
    double x,y,t=0;
    linea(x0,y0,x1,y1);
    linea(x1,y1,x2,y2);
 
       do{
		    x=x0*pow(1-t,2)+ x1*2*t*(1-t)+ x2*pow(t,2);//ecuacion parametrica para X
		    y=y0*pow(1-t,2)+ y1*2*t*(1-t)+ y2*pow(t,2);//ecuacion parametrica para Y
		    punto(x,y);//dibuja  un punto en la cordenadas x,y 
		    t=t+0.001;//incremento mediante  el cual se dibujaran  los pixeles
   
        }while(t<=1);//limite por el cual se dibujan los pixeles

}

void bezier(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3)
{
    double x,y,t=0;
        do{
    x=x0*pow(1-t,3)+ x1*3*t*pow(1-t,2)+ x2*3*pow(t,2)*(1-t)+x3*pow(t,3);//ecuacion parametrica para X
    y=y0*pow(1-t,3)+ y1*3*t*pow(1-t,2)+ y2*3*pow(t,2)*(1-t)+y3*pow(t,3);//ecuacion parametrica para Y
    punto(x,y);//dibuja  un punto en la cordenadas x,y 
        t=t+0.001;//incremento mediante  el cual se dibujaran  los pixeles
   
        }while(t<=1);//limite por el cual se dibujan los pixeles

}

char *numATexto(float numero)
{
	int n=sizeof(trunc(numero));
	int i,j;
	
	
}
