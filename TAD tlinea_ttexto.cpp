//TAD tLinea y tTexto

/*
Dado un texto del cual desconocemos el numero de lineas y de caracteres por linea y sabiendo que el texto
solo consta de caracteres alfanuméricos y signos de puntuación(no aparecen caracteres de control como fin de
linea, retorno de carro...).

	a) Diseñe una estructura de datos para almacenar un texto en memoria, definiendo los tipos de datos tLinea
	y tTexto que representarán una linea y un texto, respectivamente.
	Justifica razonadamente la estructura elegida.

	b) Escribe un subprograma que procese un texto ya almacenado en memoria y sustituya todas las ocurrencias de una palabra cualquiera por otra.
	Se entiende por palabra una secuencia de caracteres de cualquier longitud(no tiene por que empezar y acabar en la misma linea)

*/

//--------------------------------------SOLUCION---------------------------------

/*
Para este ejercicio usaremos 2 estructuras para cada tipo de datos:

	- tTexto consistira en una lista enlazada formada por una serie de lineas.
	- Cada linea (tLinea) estara formada por una pila dinamica de caracteres.
*/

struct tLinea
{
	Pila<char> P;
}

ListaE<tLinea> L;

//Las partes privadas de las Pilas y Listas son las siguientes:

//pila
struct nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* p = nullptr):elto(e),sig(p){}
}
nodo* tope_;

//Lista
struct nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* s = nullptr):elto(e),sig(s){}
}

//Las operaciones que usaremos del tad pila y tad lista seran las siguientes:

//Pila
bool vacia() const
void push(const T& x)
void pop() const
const T& tope() const

//Lista
posicion primera() const
posicion fin() const
posicion siguiente() const
T& elemento(posicion pos) const


//En este ejercicio no hay que comentar la clase si no hacer directamente un subprograma(una funcion) que
//será la siguiente:


//tendremos en cuenta que esta subrutina esta dentro de una clase como metodo y la lista como atributo
//precondicion:
//postcondicion: intercambia toda ocurrencia de una palabra por otra del texto

void intercambio(string palabra_old, string palabra_new)
{
	ListaE<tLinea>L;
	Pila<char>aux;
	string palabra;
	ListaE<tLinea>::posicion p = L.primera();

	while(p != L.fin())
	{
		while(!L.elemento(p).P.vacia())
		{
			if(L.elemento(p).P.tope() == ' ')
			{
				if(palabra == palabra_old)
				{
					for(int i = 0; i< palabra_new.length();i++)
					{
						aux.push(palabra_new.at(i));
					}
					palabra = '';
				}
				else
				{
					for(int i = 0; i<palabra.length();i++)
					{
						aux.push(palabra.at(i));
					}
					palabra = '';
				}
				L.elemento(p).P.pop();
			}
			else
			{
				palabra.push_back(L.elemento(p).P.tope());
				L.elemento(p).P.pop();
			}
		}
		while(!aux.vacia())
		{
			L.elemento(p).P.push(aux.tope());
			aux.pop();
		}

		p = L.siguiente(p);
	}
}