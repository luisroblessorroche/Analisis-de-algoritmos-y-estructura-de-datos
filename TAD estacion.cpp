//TAD estacion

//parte privada lista vectorial pseudoestatica
T *elementos;
size_t Lmax;
size_t n;

//parte privada pila dinamica
struct nodo
{
	T elto;
	nodo * sig;
	nodo(const T& e, nodo p = nullptr):elto(e),sig(p){}
}
nodo *tope_;



class Estacion
{
	public:
		Estacion(int n);
		void llegada_tren(int n, int id_tren);
		void salida_tren(int n);
		void mover_de_transito_a_estacionamiento(int id_tren);
		void mover_de_estacionamiento_a_transito(int n, int id_tren);
		int via(int id_tren);
		int tren(int n);
	private:
		Lista<int>L;//vias transito
		Pila<int>P;//via estacionamiento
		Pila<int>aux;//via movimiento
		int num_vias;
}

Estacion::Estacion(int n)
{
	L = Lista<int>(n);
	num_vias = n;
}

void Estacion::llegada_tren(int n, int id_tren)
{
	assert(n>=0 && n<num_vias);
	assert(L.elemento(n) == nullptr);
	
	L.insertar(id_tren,n);
}

void Estacion::salida_tren(int n)
{
	assert(n>=0 && n<num_vias);
	assert(L.elemento(n) != nullptr);
	L.eliminar(n);
}

void Estacion::mover_de_transito_a_estacionamiento(int id_tren)
{
	Lista<int>::posicion p = L.primera();
	bool encontrado = false;
	while(p!= L.fin() && !encontrado)
	{
		if(id_tren == L.elemento(p))
		{
			encontrado = true;
			P.push(L.elemento(p));
			L.eliminar(p);
		}
		else
		{
			p = L.siguiente(p);
		}
	}
}

void Estacion::mover_de_estacionamiento_a_transito(int n,int id_tren)
{
	assert(n>=0 && n<num_vias);
	assert(L.elemento(n) == nullptr);
	bool encontrado = false;
	while(!P.vacia() && !encontrado)
	{
		if(P.tope() == id_tren)
		{
			L.insertar(P.tope(),n);
			P.pop();
			encontrado = true;
		}
		else
		{
			aux.push(P.tope());
			P.pop();
		}
	}
	while(!aux.vacia())
	{
		P.push(aux.tope());
		aux.pop();
	}
}

int Estacion::via(int id_tren)
{
	assert(L.buscar(id_tren) != L.fin());
	return L.buscar(id_tren);
}

int Estacion::tren(int n)
{
	assert(n>= 0 && n<num_vias);
	assert(L.elemento(n) != nullptr);
	return L.elemento(n);
}
