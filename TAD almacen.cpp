// TAD almacen

/*
Una empresa ha robotizado su almacén. Para ello lo ha divido en 60 estantes de 3 tamaños diferentes
(pequeño, mediano y grande) a partes iguales. A cada estante se le asigna elementos según si tamaño
(en cada estantes solo hay elementos de un tipo, pero puede haber hasta 50 elementos del mismo tipo).
Se pide diseñar un TAD para el funcionamiento del robot que incluya las siguientes operaciones:
	- Crear un almacen vacio
	- Insertar un elemento en un estante. Si ya hay un estante asignado, y el elemento cabe, se coloca
	  en ese. Si no es así, se busca otro estante del mismo tamaño. Si no hay, se devuelve false. Si se
	  puede colocar se devuelve True.
	- Comprobar si hay elementos de un tipo determinado.
	- Sacar un elemento de un tipo dado
	- Vaciar el almacen (destructor del TAD)
*/

//-------------------------------------------SOLUCION-----------------------------------------------

/*
Para resolver este ejercicio haremos uso de listas vectoriales pseudoestaticas y pilas vectoriales
El tipo de la lista sera de estantes y estara formado de la siguiente forma:
*/

struct estante
{
	string item;
	Pila<elemento>P_(50);
}

//cada elemento de la lista estara formado por:

struct elemento
{
	string nombre;
	char tam;
}

//la parte privada de una lista vectorial pseudoestatica es:
T *elementos;
size_t Lmax;
aize_t n;

//la parte privada de una pila es la siguiente:
tElemento *elementos;
unsigned Lmax;
unsigned n_eltos;

//Las operaciones del TAD lista que vamos a usar serán las siguientes:
posicion primera() const;
posicion fin() const;
posicion siguiente() const;
T& elemento(posicion pos) const;

//Las operaciones del TAD pila que vamos a usar son:
T& tope() const;
bool llena() const;
void push(const T& x);
void pop();

//La clase almacen será la siguiente:

class Almacen
{
	public:
		Almacen();
		bool insertar_elemento(elemento x);
		bool existe_stock_elemento(elemento x);
		void sacar_elemento(elemento x);
		~Almacen();
	private:
		Lista<estantes>P(20);
		Lista<estantes>M(20);
		Lista<estantes>G(20);
}


//precondición:
//postcondición:crea un almacen vacio
Almacen::Almacen()
{

}

//precondición: el elemento es de tamaño P, M o G;
//postcondición: inserta si existe un estante con hueco para el elemento y 
//devuelve true o falso dependiendo de si se puede insertar
bool Almacen::insertar_elemento(elemento x)
{
	assert(x.tam == P || x.tam == M || x.tam == G);
	switch(x.tam)
	{
		case P:
			Lista<estantes>::posicion p = P.primera();
			while(p!=P.fin())
			{
				if(P.elemento(p).item == x.nombre && !P.elemento(p).P_.llena())
				{
					P.elemento(p).P_.push(x);
					return true;
				}
			}
			return false;
		break;

		case M:
			Lista<estantes>::posicion p = M.primera();
			while(p!=M.fin())
			{
				if(M.elemento(p).item == x.nombre && !M.elemento(p).P_.llena())
				{
					M.elemento(p).P_.push(x);
					return true;
				}
			}
			return false;
		break;

		case G:
			Lista<estantes>::posicion p = G.primera();
			while(p!=G.fin())
			{
				if(G.elemento(p).item == x.nombre && !G.elemento(p).P_.llena())
				{
					G.elemento(p).P_.push(x);
					return true;
				}
			}
			return false;
		break;
	}
}

//precondición: el elemento es de tipo S, M o G
//postcondición: comprueba si hay elementos en el almacen de un elemento en concreto
bool Almacen::existe_stock_elemento(elemento x)
{
	assert(x.tam == P || x.tam == M || x.tam == G);
	switch(x.tam)
	{
		case P:
			Lista<estantes>::posicion p = P.primera();
			while(p!=P.fin())
			{
				if(x.nombre == P.elemento(p).item && !P.elemento(p).Pila.vacia())
				{
					return true;
				}
			}
			return false;
		break;
		case M:
			Lista<estantes>::posicion p = M.primera();
			while(p!=M.fin())
			{
				if(x.nombre == M.elemento(p).item && !M.elemento(p).Pila.vacia())
				{
					return true;
				}
			}
			return false;
		break;
		case G:
			Lista<estantes>::posicion p = G.primera();
			while(p!=G.fin())
			{
				if(x.nombre == G.elemento(p).item && !G.elemento(p).Pila.vacia())
				{
					return true;
				}
			}
			return false;
		break;
	}
}

//precondición: el elemento tiene un tamaño valido
//postcondición: elimina un elemento del estante si es que existe
void Almacen::sacar_elemento(elemento x)
{
	assert(x.tam == P || x.tam == M || x.tam == G);
	switch(x.tam)
	{
		case P:
			bool eliminado = false;
			Lista<estantes>::posicion p = P.primera();
			while(p != P.fin() && !eliminado)
			{
				if(x.nombre == P.elemento(p).item && !P.elemento(p).Pila.vacia())
				{
					P.elemento(p).P.pop();
					eliminado = true;
				}
			}
		break;
		case M:
			bool eliminado = false;
			Lista<estantes>::posicion p = M.primera();
			while(p != M.fin() && !eliminado)
			{
				if(x.nombre == M.elemento(p).item && !M.elemento(p).Pila.vacia())
				{
					M.elemento(p).Pila.pop();
					eliminado = true;
				}
			}

		break;
		case G:
			bool eliminado = false;
			Lista<estantes>::posicion p = G.primera();
			while(p != G.fin() && !eliminado)
			{
				if(x.nombre == G.elemento(p).item && !G.elemento(p).Pila.vacia())
				{
					G.elemento(p).Pila.pop();
					eliminado = true;
				}
			}
		break;
	}
}

//precondición:
//postcondición:elimina el almacen
Almacen::~Almacen()
{
	
}