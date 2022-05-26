/*
(Definir prototipos, operaciones del TAD. No hay carácter de salto de línea, el texto te lo dan
a partir de la estructura)

a)	Diseñe una estructura de datos para almacenar en memoria un texto del cual desconocemos el numero
	de lineas y de caracteres por línea.
	Sabemos que el texto solo consta de caracteres alfanuméricos y signos de puntuación, es decir,
	en el no aparencen caracteres de control como fin de linea, retorno de carro...
	Sin embargo, hay caracteres especiales que pueden aparecer un número indeterminado de veces.
	@ indica el borrado del caracter anterior. En caso de que aparezcan varios consecutivos,
	solo tiene efecto el primero;el resto aunque se almacene, se ignora.
	Este caracter no aparecerá al principio de ninguna linea
	# indica  el borrado de la linea completa. Si aparecen varios igual, solo aparecerá al final
	de la linea.

b)	Escribe una funcion MostrarTexto(). Al realizar este volcado a pantalla no te preocupes por el
	numero de caracteres ni de linea.
*/


/*
Para realizar este ejercicio haremos uso de una lista enlazada de pilas dinamicas.
En cada celda de la lista se almacenara una linea del texto que viene dada por una pila.
*/

//La parte privada de una pila enlazada es la siguiente:
struct nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* s = nullptr): elto(e), sig(s){}
}

//La parte privada de una lista enlazada es la siguiente:
struct celda
{
	T elto;
	nodo* sig,ant;
	nodo(const T& e, nodo* s = nullptr, nodo* a = nullptr): elto(e), sig(s), ant(a){}
}

//la lista estara formada por la estructura de linea que será:
struct linea
{
	//...
	PilaD<char>P;
}

//Aunque no pida hacerla, la clase texto quedará mas o menos asi:

class Texto()
{
	public:
		Texto();
		MostrarTexto();
	private:
		ListaEnla<linea>L;
}

//Las operaciones del TAD que tenemos que realizar son:

//precondición:
//postcondición: devuelve el texto con los cambios realizados en funcion a sus caracteres especiales
linea Texto::MostrarTexto()
{
	PilaD<char>aux;
	ListaEnla<linea>::posicion p = L.primera();
	while(p != L.fin())
	{
		bool eliminado = false;
		while(!L.elemento(p).P.vacia() && !eliminado)
		{
			if(L.elemento(p).P.tope() == '@')
			{
				aux.pop();
				L.elemento(p).P.pop();
				while(!L.elemento(p).P.vacia() && L.elemento(p).P.tope() == '@')
				{
					L.elemento(p).P.pop();
				}
			}
			if(L.elemento(p).P.tope() == '#')
			{
			
				eliminado = true;
			}
			aux.push(L.elemento(p).P.tope());
			L.elemento(p).P.pop();
		}
		if(eliminado)
		{
			while(!aux.vacia())
			{
					aux.pop();
			}
			L.eliminar(p);
		}
		else
		{
			while(!aux.vacia())
			{
				L.elemento(p).P.push(aux.tope());
				aux.pop();
			}

			p = L.siguiente(p);
		}
	}
	return L;
}