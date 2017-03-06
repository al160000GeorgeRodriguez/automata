#ifndef BASE_H
#define BASE_H
class eregular
{
	public:
		eregular();
		void dibujar();
};

class transicion
{
	public:
		transicion();
		void flecha();
		float x1,y1,x2,y2;
		int colorPunta, colorLinea;
		char *tex;
};

class estado
{
	public:
		estado(); //constructor;
		float x,y; //coordenadas
		char *nombre; //nombre del nodo
		int tipo; //tipo de nodo 1:normal, 2:inicial, 3:aceptación
		void dibujarestado(int color);
		int colorN;
		private:
		void Inicial();
		void Normal();
		void Aceptacion();
};

class fTransicion
{
	public:
	fTransicion();
	void funcionT(estado edoOrigen, char *cadena, estado edoDestino);
	transicion enlace;
	//private:
		};
	
	#endif
