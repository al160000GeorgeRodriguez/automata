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
		void flecha(const std::string& tex, int tipo);
		float x1,y1,x2,y2;
		int colorPunta, colorLinea;
		
};

class estado
{
	public:
		estado(); //constructor del objeto
		float x,y; //coordenadas del objeto
		
		//char *nombre; //nombre del nodo
		int tipo; //tipo de nodo 0:inicial y aceptaci�n] 1:normal, 2:inicial, 3:aceptaci�n
		void dibujarestado(int color,const std::string& nombre);
		char *ID;
		int colorN;
		bool simetrico;
		bool reflexivo;
		char entrantes[];
		char salientes[];
		private:
		void InicialAceptacion(const std::string& nom);
		void Inicial(const std::string& nom);
		void Normal(const std::string& nom);
		void Aceptacion(const std::string& nom);
};

class fTransicion
{
	public:
	fTransicion();
	void funcionT(estado edoOrigen, const std::string& cadena, estado edoDestino);
	transicion enlace;
	private:
	bool comprobarReflexion(estado Origen, estado Destino ); //Comprueba si el nodo apunta hacia si mismo
	bool comprobarSimetria(estado Origen, estado Destino ); // Comprueba la simetr�a y devuelve los identificadores en una cadena
		};
	
	#endif
