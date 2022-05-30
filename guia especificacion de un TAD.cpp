//COMO HACER ESPECIFICACION DE UN EJERCICIO DE TAD

//PASO 1: Hablar un poco acerca del ejercicio

//PASO 2: Explicar en que tad de los conocidos nos vamos a apoyar y definir el tipo de dato que vamos a usar

	//definir estructura en caso de ser necesaria
	struct
	{
		//...
	}

//PASO 3: Definir la parte privada de el tad del que vamos a hacer uso
	
	//----Pila pseudoestatica-----
	tElemento *elementos; //vector de elementos
	unsigned Lmax; //tamaño del vector
	unsigned n_eltos; //tamaño de la pila

	//----Pila dinamica-----
	struct nodo
	{
		T elto;
		nodo* sig;
		nodo(const T& e, nodo* p = nullptr): elto(e), sig(p){}
	}

	//----Cola pseudoestatica----
	T *elementos; //vector de elementos
	size_t Lmax; //tamaño del vector
	size_t n_eltos; //tamaño de la cola

	//----Cola dinamica----
	struct nodo
	{
		T elto;
		nodo* sig;
		nodo(const T& e, nodo* p = nullptr): elto(e), sig(p){}
	}

	//----Lista pseudoestatica-----
	T *elementos; //vector de elementos
	size_t Lmax; //tamaño del vector
	size_t n; // longitud de la lista

	//----Lista dinamica----
	struct nodo
	{
		T elto;
		nodo* ant,sig;
		nodo(const T& e, nodo* a = nullptr, nodo* s = nullptr): elto(e), ant(a), sig(s){}
	}

//PASO 4: Mencionar las operaciones propias del TAD que se van a emplear

	//----Pila----
	Pila();
	bool vacia() const;
	const tElemento& tope() const;
	void pop();
	void push(const T& x);
	bool llena() const; //solo en pila pseudoestatica

	//----Cola----
	Cola();
	bool vacia() const;
	const tElemento& frente() const;
	void pop();
	void push(const t& x);
	bool llena() const; //solo en cola pseaudoestatica

	//----Lista----
	Lista();
	void insertar(const T& x, posicion pos);
	void eliminar(posicion pos);
	posicion primera() const;
	posicion fin() const;
	posicion siguiente(posicion pos) const;
	posicion anterior(posicion pos) const;
	posicion buscar(const T& x) const;
	const T& elemento(posicion pos) const;
	T& elemento(posicion pos);

//PASO 5: Crear la clase con las operaciones que se nos pida y los atributos que necesitemos

	class xxx
	{
		public:
			//...
		private:
			//...
	}




