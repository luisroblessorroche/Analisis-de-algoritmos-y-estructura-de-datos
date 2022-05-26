//TAD diccionario

/*
Crear un diccionario ingles-español,en que cada palabra en ingles tiene
1 o varias traducciones:
Se requerirá las siguientes operaciones:
- Crear un diccionario vacío
- Insertar una traducción española de una palabra inglesa
- Eliminar una traducción española de una plabra inglesa
- Consultar TODAS las traducciones al español de una palabra inglesa
- Destruir el diccionario
*/

//--------------------------------SOLUCION----------------------------

/*Para este ejercicio haremos uso de una lista enlazada de listas enlazadas, siendo la primera lista ordenada
ya que podemos usar la libreria string.h que tiene los operadores < sobrecargados
Tambien podriamos hacer uso de una doble enlazada pero solo cambiara el orden de inserción
de los traducciones o palabras en caso de no estar de antemano debido al coste de las operaciones
propias del tad lista fin() y anterior()
*/


//La parte privada de una lista enlazada es la siguiente

struct celda
{
	T elto;
	nodo* sig, ant;
	nodo(const T& e, nodo* s = nullptr, nodo* a = nullptr): elto(e), sig(s), ant(a){}
}

nodo* L;

/*
El tipo de datos que vamos a usar va a ser de tipo ingles que estará formada por un string y una lista del tipo espanol
que estará formada por lo menos por un string que sera su traducción en español 
*/

struct ingles
{
	string palabra_ing;
	ListaE<espanol>L2;
}

struct espanol
{
	string palabra_esp;
	//....
}

//La clase de de nuestro TAD diccionario será la siguiente:

class Diccionario
{
	public:
		Diccionario();
		void insertar_traduccion(ingles ing, espanol esp);
		void eliminar_traduccion(string palabra_ing, espanol esp);
		const espanol consultar_traduccion(string palabra_ing) const;
		~Diccionario();

	private:
		ListaE<ingles>L;
}

//Las operaciones propias del TAD lista enlazada que vamos a usar van a ser las siguientes:

posicion primera()
posicion fin()
posicion siguiente(posicion p)
posicion buscar(const T& x)
void insertar(const T& x, posicion p)
void eliminar(posicion p)
const T& elemento(posicion p)


//La implementación de los metodos de las clases son los siguientes

//precondicion:
//postcondicion: crea un diccionario vacio
Diccionario::Diccionario()
{

}

//precondicion:
//postcondicion: inserta de manera ordenada las traducciones en español de la palabra inglesa en caso de no estar la traduccion.
//Si no esta la palabra inglesa tambien la insertar e insertara la traduccion
void Diccionario::insertar_traduccion(ingles ing, espanol esp)
{
	ListaE<ingles>::posicion p = L.primera();
	bool encontrado = false;
	while(p != L.fin() && !encontrado)
	{
		if(L.elemento(p).palabra_ing >= ing.palabra_ing)
		{
			if(L.elemento(p).palabra_ing == ing.palabra_ing)
			{
				ListaE<espanol>::posicion q = L.elemento(p).L2.primera();
				bool encontrado2 = false;
				while(q != L.elemento(p).L2.fin() && !encontrado)
				{
					if(L.elemento(p).L2.elemento(q).palabra_esp > esp.palabra_esp)
					{
						L.elemento(p).L2.insertar(esp,q);
						encontrado2 = true;
					}
					q = L.elemento(p).L2.siguiente(q);
				}
				if(!encontrado)
				{
					L.elemento(p).L2.insertar(esp,q);
				}
			}
			encontrado = true;
		}
		else
		{
			L.insertar(ing,p);
			L.elemento(p).L2.insertar(esp,L.elemento(p).L2.primera());
			encontrado = true;
		}

		p = L.siguiente(p);
	}
	if(!encontrado)
	{
		L.insertar(ing,L.fin());
		L.elemento(p).L2.insertar(esp,L.elemento(p).L2.primera());
	}
}

//precondicion:
//postcondicion:elimina la traduccion española de la palabra inglesa. Si al eliminar la traduccion, la palabra no tiene traduccion,
//debera eliminar la palabra inglesa
void Diccionario::eliminar_traduccion(string palabra_ing, espanol esp)
{
	ListaE<ingles>::posicion p = L.primera();
	bool encontrado = false;
	while(p != L.fin() && !encontrado)
	{
		if(L.elemento(p).palabra_ing == palabra_ing)
		{
			ListaE<espanol>::posicion q = L.elemento(p).L2.primera();
			bool encontrado2 = false;
			while(q != L.elemento(p).L2.fin() && !encontrado2)
			{
				if(L.elemento(p).L2.elemento(q).palabra_esp == esp.palabra_esp)
				{
					L.elemento(p).L2.eliminar(q);
					encontrado2 = true;
				}
				
				q = L.elemento(p).L2.siguiente(q);
			
			}
			encontrado = true;
		}
		p = L.siguiente(p);
	}
	if(encontrado)
	{
		if(L.elemento(p).L2.primera() == L.elemento(p).L2.fin())
		{
			L.eliminar(p);
		}
	}
}


//precondicion: la palabra inglesa que le pasamos esta en la lista
//postcondicion: devuelve la lista de traducciones españolas
const espanol Diccionario::Diccionario(string palabra_ing) const
{
	ListaE<ingles>::posicion p_assert = L.primera();
	bool bool_assert = false;
	while(p_assert != L.fin() && !bool_assert)
	{
		if(L.elemento(p_assert).palabra_ing == palabra_ing)
		{
			bool_assert = true;
		}
		p_assert = L.siguiente(p_assert);
	}
	assert(bool_assert);

	ListaE<ingles>::posicion p = L.primera();
	while(p != L.fin())
	{
		if(L.elemento(p).palabra_ing == palabra_ing)
		{
			return L.elemento(p).L2;
		}
		p = L.siguiente(p);
	}

	//assert(p != L.fin());
}

//precondicion:
//postcondicion: destruye el diccionario
Diccionario::~Diccionario()
{
	
}



