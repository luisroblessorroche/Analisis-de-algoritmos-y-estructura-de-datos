//TAD ESCALONADA

/*
Una funcion f:R->R es escalonada cuando consiste en una sucesión de funciones constantes definidas en subintervalos disjuntos y contiguos, es decir,
f puede definirse mediante condiciones de la forma f(x) = y si xi <=xi+1,donde los valores yi son distintos para subintervalos adyacentes.
Cada uno de los puntos(xi,yi) en los que la función cambia de valor se llama salto o escalón.

Especificar un TAD para las funciones escalonadas con un numero finitos de saltos, que incluya las siguientes operaciones:
- Crear una función constante f(x)=yi definida a partir de xi
- Añadir un nuevo salto en el punto(x,y) a una función. Si ya existe un salto en las coordenadas x, se sustituye por el nuevo
- Eliminar el escalón definido en el intervalo que pertenece la coordenada x. El escalon anterior al eliminado se prolonga hasta el siguiente.
- Calcular el valor de una funcion en un punto dado
- Calcular el valor mínimo de una función escalonada
- Calcular el valor máximo de una función escalonada
- Hacer una traslación de una función w unidades horizontales y z unidades verticales, siendo w y z números reales.
- Destruir una función
*/

//-----------------------------------------------SOLUCIÓN----------------------------------------------------

/*
Para este ejercicio haremos uso de una lista enlazada ordenada.
La parte privada de la lista enlazada es la siguiente
*/

struc nodo
{
	T elto;
	nodo* ant, sig;
	nodo(const T& e, nodo* a = nullptr, nodo* s = nullptr): elto(e), ant(a), sig(s){}
}
nodo* L;

//Ahora definiremos el tipo de dato que vamos a usar
//Usaremos una estructura formada por los puntos x e y llamada salto:

struct salto
{
	double x;
	double y;
}


//Hacemos la clase de nuestro TAD escalonada:

class Escalonada
{
	public:
		Escalonada(double x);
		void insertar_escalon(salto sal);
		void eliminar_escalon(double x);
		double valor_fun(double x);
		double valor_min();
		double valor_max();
		void traslación(double w, double z);
		~Escalonada()
	private:
		ListaE<salto>L;
		ListaE<salto>::posicion p = L.primera();
}


//Las operaciones del TAD lista que vamos a usar van a ser las siguiente:
posicion primera();
posicion fin();
posicion siguiente();
void insertar(const T& x, posicion pos);
void eliminar(posicion pos);
T& elemento(posicion pos);

//precondición
//postcondición:crea una función constante f(x) definida por x 
Escalonada::Escalonada(double x)
{
	salto sal;
	sal.x = x;
	sal.y = x;
	L.insertar(sal,L.primera());
}


//Precondición:
//Postcondición: inserta el salto de manera ordeanada en la lista o modifica la coordenada y con la del nuevo salto si ya exisistia el punto x 
void Escalonada::insertar_escalon(salto sal)
{
	pos = p;
	bool insertado = false;
	while(pos != L.fin() && !insertado)
	{
		if(L.elemento(pos).x>=sal.x)
		{
			if(L.elemento(pos).x == sal.x)
			{
				L.elemento(pos).y = sal.y;
				insertado = true;
			}
			else
			{
				L.insertar(sal,pos);
				insertado = true;
			}
		}
		pos = L.siguiente(pos);
	}
	if(!insertado)
	{
		L.insertar(sal,L.fin());
	}
}

//Precondición:
//Postcondición:elimina el salto cuyo punto x corresponde con el que le pasamos
void Escalonada::eliminar_escalon(double x)
{
	pos = p;
	bool encontrado = false;
	while(pos != L.fin() && !encontrado)
	{
		if(L.elemento(pos).x == x)
		{
			L.eliminar(pos);
			encontrado = true;
		}

		pos = L.siguiente(pos);
	}
}

//Precondicion:La lista no esta vacia
//Postcondición:devuelve el punto y que le corresponde al salto cuyo eje x es el valor x que le pasamos
double Escalonada::valor_fun(double x)
{
	assert(L.primera() != L.fin());

	pos = p;
	bool encontrado = false;
	while(pos != L.fin())
	{
		if(L.elemento(pos).x == x)
		{
			return L.elemento(pos).y;
		}
		pos = L.siguiente(pos);
	}
}

//Precondición:La lista no esta vacía
//Postcondición: devuelve la coordenada y más pequeña de todos los saltos de la lista
double Escalonada::valor_min()
{
	assert(L.primera() != L.fin());

	pos = p;
	double min = L.elemento(pos).y;
	pos = L.siguiente(pos);

	while(pos != L.fin())
	{
		if(L.elemento(pos).y < min)
		{
			min = L.elemento(pos).y;
		}

		pos = L.siguiente(pos);
	}
	return min;
}

//Precondicion: la lista no esta vacía
//Postcondición: devuelve la coordenada y más grande de todos los saltos de la lista
double Escalonada::valor_max()
{
	assert(L.primera != L.fin());

	pos = p;
	double max = L.elemento(pos).y;
	pos = L.siguiente(pos);

	while(pos != L.fin())
	{
		if(L.elemento(pos).y > max)
		{
			max = L.elemento(pos).y;
		}

		pos = L.siguiente(pos);
	}
	return max;
}

//Precondición:
//Postcondición: hace una translación de la función w unidades horizontales(x) y z unidades verticales(y)
void Escalonada::translación(double w, double z)
{
	pos = p;
	while(pos != L.fin())
	{
		L.elemento(pos).x += w;
		L.elemento(pos).y += z;

		pos = L.siguiente(pos);
	}
}

//Precondición:
//Postcondición: destruye la lista de saltos
Escalonada::~Escalonada()
{

}

