//Luis Robles Sorroche

//TAD tren

/*
Realizar la especificación e implementación de un TAD tren que sirva para representar secuencias (de longitud arbitraria)
de vagones (se supone que el tipo vagón ya esta predefinido). Si la secuencia no está vacía, hay un vagon del tren
denominado "activo" sobre el que puede actuar un robot manipulador. Las operaciones que se piden son:

- Crear un tren
- Desplazar a la izquierda: Mueve el tren una posición a la izquierda de manera que el nuevo vagón activo es el que
  está inmediatamente a la derecha del actual. Si no hay vagon a la derecha, no se hace nada
- Desplazar a la derecha: Simétrica a la anterior
- Eliminar el vagón activo: Se suprime el vagon activo y se convierte en activo el que esta a su derecha.
  Si no hay sera el de su izquierda y si este tampoco existe se quedara vacio el tren
- Insertar vagon activo: inserta un nuevo vagon activo, desplazando el vagon activo y todos los derechos una posicion
  a la derecha
- Observar vagon activo: una camara fija situada en el robot devuelve el vagon activo
- Tren vacio: indica si el tren tiene vagones

Se prohibe el uso de estructuras doblemente enlazada y el coste de todas las operaciones debe ser constante
*/


//------------------------------------------------SOLUCIÓN-----------------------------------------------------

/*
Para resolver este ejercicio haremos uso de dos pilas enlazadas donde el tope de la pila derecha
sera el vagon activo.
*/

//La parte privada del TAD pila es la siguiente

struct nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* s = nullptr): elto(e), sig(s){}
}
nodo* tope_;

//El tipo de dato que vamos a usar es el tipo vagon que ya nos dice que está predefinido


//Pasamos a hacer la clase de nuestro TAD Tren

class Tren
{
	public:
		Tren();
		void mover_izqdo();
		void mover_drcho();
		void eliminar_vagon_activo();
		void insertar_vagon_activo(vagon v);
		const vagon vagon_activo() const;
		bool tren_vacio();
	private:
		Pila<vagon>PI;
		Pila<vagon>PD;
}

//Las operaciones del TAD pila que vamos a usar van a ser las siguientes:
void push(const T& x);
void pop();
const T& tope() const;
bool vacia();


//Implementación de los métodos de la clase

//Precondición:
//Postcondición:crea un tren vacio
Tren::Tren()
{

}

//Precondición:
//Postcondición:mueve el tren una posicion a la izquierda, en caso de moverlo y detectar que
//no hay vagon a la derecha, se debera dejar el tren como estaba antes
void Tren::mover_izqdo()
{
	if(!PD.vacia())
	{
		PI.push(PD.tope());
		PD.pop();
		if(PD.vacia())
		{
			PD.push(PI.tope());
			PI.pop();
		}
	}
}

//Precondición:
//Postcondición: mueve el tren una posicion a la derecha, en caso de moverlo y detectar que no
//hay vagon a la izquierda, se debera dejar el tren como estaba antes
void Tren::mover_drcho()
{
	if(!PI.vacia())
	{
		PD.push(PI.tope());
		PI.pop();
		if(PI.vacia())
		{
			PI.push(PD.tope());
			PD.pop();
		}
	}
}


//precondición:
//postcondición:elimina el vagon activo, dejando el derecho como nuevo vagon activo.
//Si este tampoco tiene pasara a ser el vagon izquierdo y si tampoco hay es que el tren esta vacio
void Tren::eliminar_vagon_activo()
{
	if(!PD.vacia())
	{
		PD.pop();
		if(PD.vacia())
		{
			if(!PI.vacia())
			{
				PD.push(PI.tope());
				PI.pop();
			}
		}
	}
}

//precondición
//postcondición:inserta el vagon como nuevo vagon activo
void Tren::insertar_vagon_activo(vagon v)
{
	PD.push(v);
}

//precondicion:existe un vagon activo
//postcondicion: devuelve dicho vagon activo
const vagon Tren::vagon_activo() const
{
	assert(!PD.vacia());
	return PD.tope();
}

//precondición:
//postcondición:devuelve true si el tren esta vacio o false si no lo está
bool Tren::tren_vacio()
{
	return (PD.vacia() && PI.vacia());
}



