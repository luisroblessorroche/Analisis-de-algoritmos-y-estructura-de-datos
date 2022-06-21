//TAD SIMBOLO

/*
El TAD simbolo se usa para representar simbolos trazados con lineas rectas. Un simbolo es
una sucesion de trazos, un trazo es una linea recta que puede tener un sentido a izquierda,
derecham arriba o abajo. El TAD simbolo tiene que permitir realizar las siguientes operaciones con un simbolo:
	- Crear un simbolo vacio
	- Añadir un trazo al final de un simbolo
	- Deshacer los ultimos n trazos
	- Simetrico con respecto a eje x
	- Simetrico con respecto a eje y
	- Simetrico con respecto a eje xy
*/


/*
Para realizar este ejercicio haremos uso de pilas dinamicas(enlazadas).
La estructura de una pila enlazada es la siguiente:
*/

struc nodo
{
	T elto;
	nodo* sig;
	nodo(const T& e, nodo* p = nullptr): elto(e), sig(p){}
}
nodo* tope_;

//dicha pila estara formada por trazos, que en nuestro caso van a ser caracteres.
// la equivalencia será: w(arriba), a(izquierda), s(abajo), d(derecha)

//Las operaciones del TAD pila que vamos a usar serán las siguientes:

void push(const T& x);
void pop();
const T& tope() const;
bool vacia() const;

//La clase que vamos a crear será la siguiente:

class Simbolo
{
	public:
		Simbolo();
		void anadir_trazo(char trazo);
		void eliminar_n_trazos(int n);
		char simetrico_x() const;
		char simetrico_y() const;
		char simetrico_xy() const;
	private:
		Pila<char>P;
}

//Las operciones serán las siguientes:

//precondicion:
//postcondicion:crea un simbolo vacio
Simbolo::Simbolo()
{

}


//precondicion:el trazo es uno de los disponibles
//postcondicion: inserta un nuevo trazo al final del simbolo
void Simbolo::anadir_trazo(char trazo)
{
	assert(trazo == 'w' || trazo == 's' || trazo == 'a' || trazo == 'd');
	P.push(trazo);
}

//precondicion: la pila tiene mas o los mismos trazos que se desean eliminar
//postcondicion: elimina los n ultimos trazos
void Simbolo::eliminar_n_trazos(int n)
{
	Pila<char>aux(P);
	int cont = 0;
	while(!aux.vacia())
	{
		aux.pop();
		cont++;
	}

	assert(cont > n);

	while(n>0)
	{
		P.pop();
		n--;
	}
}

//precondicion:
//postcondicion: devuelve el simetrico del simbolo con respecto al eje x
char Simbolo::simetrico_x() const
{
	Pila<char>aux(P);//para no modificar la pila original
	Pila<char>aux2;

	while(!aux.vacia())
	{
		if(aux.tope() == 'w')
		{
			aux2.push('s');
		}
		else
		{
			if(aux.tope() == 's')
			{
				aux2.push('w');
			}
			else
			{
				aux2.push(aux.tope());
			}
		}
		aux.pop();
	}

	while(!aux2.vacia())
	{
		aux.push(aux2.tope());
		aux2.pop();
	}
	return aux;
}

//precondicicion:
//postcondicion: devuelve el simetrico del simbolo con respecto al eje y
char Simbolo::simetrico_y() const
{
	Pila<char>aux(P);//para no modificar la pila original
	Pila<char>aux2;

	while(!aux.vacia())
	{
		if(aux.tope() == 'a')
		{
			aux2.push('d');
		}
		else
		{
			if(aux.tope() == 'd')
			{
				aux2.push('a');
			}
			else
			{
				aux2.push(aux.tope());
			}
		}
		aux.pop();
	}

	while(!aux2.vacia())
	{
		aux.push(aux2.tope());
		aux2.pop();
	}
	return aux;
}

//precondicion:
//postcondicion: devuelve el simetrico del simbolo con respecto al eje x e y
char Simbolo::simetrico_xy() const
{
	Pila<char>aux(P);//copia para no modificar la pila original
	PIla<char>aux2;

	while(!aux.vacia())
	{
		if(aux.tope() == 'a')
		{
			aux2.push('d');
		}
		else
		{
			if(aux.tope() == 'd')
			{
				aux2.push('a');
			}
			else
			{
				if(aux.tope() == 'w')
				{
					aux2.push('s');
				}
				else
				{
					aux2.push('w');
				}
			}
		}
		aux.pop();
	}
	while(aux2.vacia())
	{
		aux.push(aux2.tope());
		aux2.pop();
	}
	return aux;
}