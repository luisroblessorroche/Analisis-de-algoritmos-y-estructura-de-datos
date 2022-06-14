//TAD postfijo

/*
Podemos expresar una expresión aritmética de dos formas distintas:

	-infijo: 	(A+B)*(C+D) 	|| X/Y*Z+W
	-postfijo: 	AB+CD+*			|| XY/Z*W+

Dada una expresión postfijo en forma de cadena de caracteres y una lista de las variables
que aparecen en dicha expresion junto a sus respectivos valores,
programa una funcion que devuelva el resultado de evaluar la expresión, haciendo uso
del tad pila
*/

/*
Para este ejercicio haremos uso de varias pilas.
A la función le tendremos que pasar dos cosas: una cadena de caracteres con la expresion
y una lista de los valores de dichas variables.
Para la lista de valores vamos a emplear un vector del tipo valor que estara formado
por el caracter y su valor correspondiente.
*/

struct valor
{
	char nombre;
	float val;
}


//vamos a hacer uso de pilas vectoriales pseudoestaticas cuya parte privada es la siguiente:
	tElemento *elementos;
	unsigned Lmax;
	unsigned n_eltos;

//tambien haremos uso de listas vectoriales pseudoestaticas, donde la parte privada es la siguiente:
	tElemento *elementos;
	size_t Lmax;
	size_t n;


//Las operaciones del tad pila que vamos a usar son las siguientes:
const T& elemento tope() const;
void push(const T& x) const;
void pop();
bool vacia() const;

//Las operaciones del tad lista que vamos a usar son las siguientes:
posicion primera() const;
posicion fin() const;
posicion siguiente(posicion pos) const;
const T& elemento(posicion pos) const;


//la funcion para evaluar la expresion será la siguiente

//precondicion:
//postcondicion: devuelve el resultado de la operacion aritmetica
float expresion_resultado(vec<char> expresion, Lista<valor>L)
{
	Pila<char> P(expresion.size()); //tamaño de la expresion
	for(int i = expresion.size(); i == 0; i--)
	{
		P.push(expresion.at(i));
	}

	Pila<float> aux(expresion.size()); // podriamos hacerlas enlazadas ya que en la practica por muchas operaciones que haya
									  // no se almacenaran muchos valores en estas pilas
	Pila<float> aux2(expresion.size());
	while (!P.vacia())
	{
		if(P.tope() == '+' || P.tope() == '-' || P.tope() == '*' || P.tope() == '/')
		{
			while(!aux.vacia())
			{
				aux2.push(aux.tope());
					aux.pop();
			}
			aux.push(aux2.tope());
			aux2.pop();
			switch(P.tope())
			{
				case '+':
					float resultado = aux.tope() + aux2.tope();
					aux2.push(resultado);
					break;
				case '-':
					float resultado = aux.tope() - aux2.tope();
					aux2.push(resultado);
					break;
				case '*':
					float resultado = aux.tope() * aux2.tope();
					aux2.push(resultado);
					break;
				case '/':
					float resultado = aux.tope() / aux2.tope();
					aux2.push(resultado);
					break;
			}
		}
		else
		{
			float operando = convertir_a_valor(P.tope(),L);
			aux.push(operando);
		}
		P.pop();
	}
	return aux2.tope(); //el resultado final estara en la pila aux2 que solo tendra un valor
}


//precondicion: el valor se encuentra en la lista que le pasamos
//postcondicion: devuelve el valor flotante correspondiente a ese caracter
float convertir_a_valor(char x,Lista<valor>L)
{
	bool encontrado = false;
	Lista<valor>::posicion aux = L.primera();
	while (aux != L.fin() && !encontrado)
	{
		if(x == L.elemento(aux).nombre)
		{
			encontrado = true;
		}
		p = L.siguiente(p);
	}
	assert(encontrado);

	Lista<valor>::posicion p = L.primera();
	while(p != L.fin())
	{
		if(x == L.elemento(p).nombre)
		{
			return L.elemento(p).val;
		}
		p = L.siguiente(p);
	}
}
