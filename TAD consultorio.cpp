//Luis Robles Sorroche

//TAD consultorio

/*
La dirección de un hospital quiere informatizar su consultorio médico con un programa que realice las siguientes operaciones
- Generar consultorio vacio
- Dar de alta a un nuevo médico
- Dar de baja a un médico
- Poner a un paciente en la lista de espera de un médico
- Consultar al paciente a quién le toque por parte de un médico
- Atender al paciente que le toque por parte de un médico
- Comprobar si un médico determinado tiene o no pacientes en espera
*/



//-------------------------------------------SOLUCIÓN------------------------------------------------------

/*
Para este ejercicio usaremos una representación enlazada del TAD lista donde cada elemento
tiene ademas de un médico una cola de pacientes
*/

//Parte privada del TAD lista

struct nodo
{
	T elto;
	nodo* sig, ant;
	nodo(const T& e, nodo* s = nullptr, nodo* a = nullptr): elto(e), sig(s), ant(a){}
}
nodo* L;

//Parte privada del TAD cola

struct nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* s = nullptr): elto(e), sig(s){}
}
nodo *inicio, *fin;


/*Vamos a definir los tipos de datos que vamos a usar:
El tipo de la lista sera de tipo medico que será una estructura.
Dentro de esa estructura tambien habra una cola que sera de tipo paciente
*/

struct paciente
{
	int id_pa;
	string nombre;
}

struct medico
{
	int id_med;
	Cola<paciente>C;
}

//Clase de nuestro TAD consultorio

class Consultorio
{
	public:
		Consultorio();
		void alta_medico(medico med);
		void baja_medico(medico med);
		void insertar_paciente(medico med, paciente pa);
		const paciente consultar_paciente_a_atender(medico med) const;
		void atender_paciente(medico med);
		bool tiene_pacientes(medico med);
	private:
		ListaE<medico>L;
		ListaE<medico>::posicion p = L.primera();
}

//Las operaciones del TAD Lista que vamos a usar seran las siguientes
posicion primera();
posicion fin();
posicion siguiente();
T& elemento(posicion pos);
void insertar(const T& x, posicion pos);
void eliminar(posicion pos);

//Las operaciones del TAD Cola que vamos a usar seran las siguientes
void push(const T& x);
void pop();
const T& frente() const;
bool vacia();

//Métodos de la clase:

//Precondición:
//Postcondición:crea un consultorio vacio
Consultorio::Consultorio()
{

}

//Precondición:
//Postcondición: inserta un nuevo medico a la lista si este no estaba antes
void Consultorio::alta_medico(medico med)
{
	pos = p;
	bool encontrado = false;
	while(pos != L.fin() && !encontrado)
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			encontrado = true;
		}

		pos = L.siguiente(pos); 
	}

	if(!encontrado)
	{
		L.insertar(med,L.primera());
	}
}

//Precondición:
//Postcondición:da de baja al medico cuya id corresponda con el que le pasamos
void Consultorio::baja_medico(medico med)
{
	pos = p;
	bool encontrado = false
	while(pos != L.fin() && !encontrado)
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			L.eliminar(pos);
			encontrado = true;
		}
		pos = L.siguiente(pos);
	}
}

//Precondición:
//Postcondición: inserta el paciente en el medico correspondiente si esta en la lista, si el medico no existe
//insertará tambien al medico en la lista
void Consultorio::insertar_paciente(medico med, paciente pa)
{
	pos = p;
	bool encontrado = false;
	while(pos != L.fin() && !encontrado)
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			L.elemento(pos).C.push(pa);
			encontrado = true;
		}

		pos = L.siguiente(pos);
	}

	if(!encontrado)
	{
		L.insertar(med,L.primera());
		L.elemento(L.primera()).C.push(pa);
	}
}

//Precondición: el medico esta en la lista y tiene al menos un paciente asignado
//Postcondición:devolvera el paciente que le toca ser atendido por el medico correspondiente
const paciente Consultorio::consultar_paciente_a_atender(medico med) const
{
	assert(L.buscar(med) != L.fin());

	pos = p;
	while(pos != L.fin())
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			assert(!L.elemento(pos).C.vacia());

			return L.elemento(pos).C.frente();
		}
		pos = L.siguiente(pos);
	}
}

//Precondición:
//Postcondición: atiende al paciente que le toca ser atendido por parte del medico
void Consultorio::atender_paciente(medico med)
{
	pos = p;
	bool encontrado = false;
	while(pos != L.fin() && !encontrado)
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			if(!L.elemento(pos).C.vacia())
			{
				L.elemento(pos).C.pop();
				encontrado = true;
			}
		}

		pos = L.siguiente(pos);
	}
}

//Precondición: el medico se encuentra en la lista
//Postcondición: devolvera true si el medico no tiene pacientes y false si tiene
bool Consultorio::tiene_pacientes(medico med)
{
	assert(L.buscar(med) != L.fin());

	pos = p;
	while(pos = L.fin())
	{
		if(L.elemento(pos).id_med == med.id_med)
		{
			return L.elemento(pos).C.vacia();
		}

		pos = L.siguiente(pos);
	}
}
