//TAD cartelera

/*
Se desea un TAD para carteleras de espectaculos, que representen un sistema informático con información
relativa a los espectaculos ofrecidos al público por una serie de salas. Cada sala puede ofrecer
varios espectaculos. El TAD debe conocer las siguientes operaciones:

	- Crear una cartelera vacia
	- Añadir una sala a la cartelera(esta no se modifica si la sala ya existia)
	- Añadir un espectaculo a la oferta de una sala ya existente(el sistema no se modifica si la sala ya ofrecia
	  el espectaculo)
	- Eliminar una sala junto con sus espectaculos(el sistema no se modifica si la sala no existe)
	- Eliminar un espectaculo de una sala(el sistema no se modifica si la sala no existe o el espectaculo no
	  existe en dicha sala)
	- Mostrar la lista de salas del sistema, ordenada y sin repeticiones
	- Mostrar la lista de espectaculos ofrecidas por una sala(vacia si la sala no existe) ordenada y sin repeticiones
 
 Además añadir:
 	- Mostrar la lista de espectaculos ofertados por el conjunto de salas(quizas vacia), ordenada y sin repeticiones
 	- Mostrar la lista de salas que ofrecen un espectaculo(quizas vacia), ordenada y sin repeticiones
*/


//------------------------------------------------SOLUCION----------------------------------------------------


/*
Para este ejercicio haremos uso de una lista enlazada de salas donde una sala contendra, a su vez, una lista enlazada
de espectaculos.
*/

//La lista estara formado por salas siendo la estructura asi:
struct sala
{
	int id_sala;
	Lista<espectaculo>L2;
}
//por otro lado espectaculo tendra por lo menos un id de espectaculo:
struct espectaculo
{
	int id_espectaculo;
	//...
}

//La estrcutura de la lista enlazada es la siguiente:
struct nodo
{
	T elto;
	nodo * sig;
	nodo(const T& e, nodo s = nullptr):elto(e),sig(p){}
}

nodo L;

//Las operaciones propias del TAD lista serán las siguiente:
posicion primera() const;
posifion fin() const;
posicion siguiente() const
void insertar(const T& x, posicion pos);
void eliminar(posicion);
T& elemento(posicion pos) const;


//La clase que vamos a crear será la siguiente:

class Cartelera
{
	public:
		Cartelera();
		void anadir_sala(sala sal);
		void anadir_espectaculo(int id_sala, espectaculo esp);
		void eliminar_sala(int id_sala);
		void eliminar_espectaculo(int id_sala, int id_espectaculo);
		ListaEnla<sala> mostrar_salas() const;
		ListaEnla<espectaculo> mostrar_espectaculos(int id_sala);
		ListaEnla<espectaculo> mostrar_espectaculos_conjunto(v);
		ListaEnla<sala> mostrar_salas(int id_espectaculo);

	private:
		ListaEnla<sala>L;
}


//Las implementaciones de los métodos serán las siguientes:

//precondición:
//postcondición: crea una cartelera vacia
Cartelera::Cartelera()
{

}

//precondición:
//postcondición: inserta una nueva sala de manera ordenada si no existia ya
void Cartelera::anadir_sala(sala sal)
{
	ListaEnla<sala>::posicion p = L.primera();
	bool insertada_existente = false;
	while(p != L.fin() && !insertada)
	{
		if(L.elemento(p).id_sala >= sal.id_sala)
		{
			if(L.elemento(p).id_sala == sala.id_sala)
			{
				insertada_existente = true;
			}
			else
			{
				L.insertar(sal,p);
				insertada_existente = true;
			}
		}

		p = L.siguiente(p);
	}
	if(!insertada_existente)
	{
		L.insertar(sal,L.fin());
	}
}

//precondición: la sala que le pasamos esta ya almacenada (esto ya es un poco subjetivo, interpretalo como quieras)
//postcondición: inserta un espectaculo en una sala YA EXISTENTE de  manera ordenada si es que no estaba ya insertada
void Cartelera::anadir_espectaculo(int id_sala, espectaculo esp)
{
	ListaEnla<sala>::posicion p=L.primera();
	bool encontrado = false;
	while(p!= L.fin() && !encontrado)
	{
		if(L.elemento(p).id_sala == id_sala)
		{
			ListaEnla<espectaculo>::posicion q = L.elemento(p).L2.primera();
			bool insertado_existente = false;
			while(q != L.elemento(p).L2.fin() && !insertada_existente)
			{
				if(L.elemento(p).L2.elemento(q).id_espectaculo >= esp.id)
				{
					if(L.elemento(p).L2.elemento(q).id_espectaculo == esp.id)
					{
						insertado_existente = true;
					}
					else
					{
						L.elemento(p).L2.insertar(esp,q);
						insertado_existente = true;
					}
				}
				q = L.elemento(p).L2.siguiente(q);
			}
			if(!insertado_existente)
			{
				L.elemento(p).L2.insertar(esp,L.elemento(p).L2.fin());
			}
		}
		p = L.siguiente(p);
	}
	if(!encontrado)
	{
		assert(false);//salta excepcion ya que no existia la sala para insertar el espectaculo
	}
}

//precondición:
//postcondición: elimina la sala si exisite en la lista
void Cartelera::eliminar_sala(int id_sala)
{
	ListaEnla<sala>::posicion p = L.primera();
	bool eliminado = false;
	while(p != L.fin() && eliminado)
	{
		if(id_sala == L.elemento(p).id_sala)
		{
			L.eliminar(p);
			eliminado = true;
		}
		else
		{
			p = L.siguiente(p);
		}
	}
}

//precondición:
//postcondición: elimina un espectaculo de la sala si es que la sala existe y el espectaculo tambien
void Cartelera::eliminar_espectaculo(int id_sala, int id_espectaculos)
{
	ListaEnla<sala>::posicion p = L.primera();
	bool existe_sala = false;
	while(p != L.fin() && !existe_sala)
	{
		if(L.elemento(p).id_sala == id_sala)
		{
			ListaEnla<espectaculo>::posicion q = L.elemento(p).L2.primera();
			bool existe_espectaculo = false;
			while(q != L.elemento(p).L2.fin() && !existe_espectaculo)
			{
				if(L.elemento(p).L2.elemento(q).id_espectaculo == id_espectaculo)
				{
					L.elemento(p).L2.eliminar(q);
					existe_espectaculo = true;
				}
				else
				{
					q = L.elemento(p).L2.siguiente(q);
				}
			}
		}
		p = L.siguiente(p);
	}
}

//precondición:
//postcondición: muestra la lista de salas ordenadas y sin repecticiones(ya viene ordenada de serie)
ListaEnla<sala> Cartelera::mostrar_salas()
{
	return L;
}

//precondición:
//postcondición: muestra la lista de espectaculos de una sala (vacia si no existe) de forma ordenada y sin repeticiones
//No se quier ha redactado esto pero no tiene sentido que devuelva una lista vacia en caso de no existir.
//Para diferenciar de si una sala existe pero no tiene espectaculos con que no exista la sala, vamos a tratar el que
//no exista la sala como una excepción que es lo más lógico de cara a la robustez del código.
ListaEnla<espectaculo> Cartelera::mostrar_espectaculos(int id_sala)
{
	ListaEnla<sala>::posicion p = L.primera();
	while(p!= L.fin() && !existe_sala)
	{
		if(id_sala == L.elemento(p).id_sala)
		{
			return L.elemento(p).L2;
		}
		p = L.siguiente(p);
	}
	assert(false)//no existe la sala. Solo ocurrira cuando
}

