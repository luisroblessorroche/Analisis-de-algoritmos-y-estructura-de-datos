//TAD cubilete

/*
Un conocido juguete está formado por una colección de cubiletes de distintos
tamaños que se pueden apilar colocando cada uno de ellos boca abajo o boca arriba.
El juego consiste en construir una nueva pila con todos los cubos boca abajo y ordenarlos
de mayor a menor tamaño(en sentido de abajo a arriba).

	a) Defina el tipo de datos tCubo para representar los cubiletes del juego
	b) Implemente una funcionque, dado una pila cualquiera de cubiletes, simule
	   el juego y devuelva la nueva pila construida. La solucion se basará en
	   el TAD pila
*/

//------------------------------SOLUCION---------------------------------

/*
Como ya hemos mencionado, usaremos pilas enlazadas ya que desconocemos el numero
de elementos con los que vamos a trabajar.
*/

//La parte privada de la pila enlazada es la siguiente:

struct nodo
{
	T elto;
	nodo *sig;
	nodo(const T& e, nodo p = nullptr): elto(e), sig(p){}
}
nodo tope_;

//El tipo de datos que usaremos sera el tipo tCubo formado al menos
//por el tamaño que vendra dada por un entero

struct tCubo
{
	int tam;
	//...
}

//Las operaciones del TAD pila que vamos a usar serán:
T& tope() const;
void push(const T& x);
void pop();
bool vacia() const;


//la funcion que se nos pide será la siguiente:
Pila<tCubo> juego(Pila<tCubo>P)
{
	Pila<tCubo>aux;
	Pila<tCubo>aux2;
	while(!P.vacia())
	{
		if(aux.vacia() || aux.tope().tam > P.tope().tam)
		{
			aux.push(P.tope());
			P.pop();
		}
		else
		{
			bool insertado = false;
			while(!aux.vacia() && !insertado)
			{

				if(aux.tope() > P.tope())
				{
					aux.push(P.tope());
					P.pop();
					insertado = true;
				}
				else if(aux.vacia())
				{
					aux.push(P.tope());
					P.pop();
					insertado = true;
				}
				else
				{
					aux2.push(aux.tope());
					aux.pop();
				}
			}
			while(!aux2.vacia())
			{
				aux.push(aux.tope());
				aux2.pop();
			}
		}
	}
	while(!aux.vacia())
	{
		P.push(aux.tope());
		aux.pop();
	}
	return P;
}
