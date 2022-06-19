//TAD tic-tac-toe

/*
Representar el TAD tablero tic tac toe con las siguientes funciones:
	- Crear tablero vacio
	- Colocar ficha de un jugador en la casilla determinada
	- Devolver un conjunto de las casillas vacias
	- devolver la ficha de una casilla
	- comprobar si un jugador determinado tiene 3 fichas en raya
	- comprobar si la partida ha acabdo en tablas(empate)
	- destruir el tablero
*/


/*
Para este ejercicio no haremos uso de ningun tad conocido ya que es mas facil hacerlo mediante un vector.
Para ello usare un vector de la stl.
Al tratarse de un 3 en raya, solo necesitaremos un vector de 9 posiciones (de 0 a 8)
El tablero tendra las casillas con - si está vacio, y si no lo está, las posibles fichas serán x e o
*/

//las operaciones que empleare del la clase vector sera:
const T& at(int pos); //para acceder al elemento de esa posicion del vector
void push_back(t& x); //insertar elemento al final del vector


//la clase será la siguiente:
class TicTacToe()
{
	public:
		TicTacToe();
		void colocar_ficha(char ficha, int casilla);
		int casillas_vacias() const;
		char ficha_casilla(int casilla);
		bool victoria(char ficha) const;
		bool empate() const;
		~TicTacToe();
	private:
		vector<char>v(9);
}

//precondicion:
//postcondicion: crea un tablero vacio(de 9 casillas)
TicTacToe::TicTacToe()
{

	for(int i = 0; i<9; i++)
	{
		v.at(i) = '-'; //inicializar tablero vacio(todo a -)
	}
}

//precondicion: la ficha es x o o y la casilla esta entre las disponibles y no esta ocupada
//postcondicion: inserta la ficha en esa casilla
void TicTacToe::colocar_ficha(char ficha, int casilla)
{
	assert(ficha == 'x' || ficha == 'o');
	assert(casilla >= 0 && casilla <= 8);
	assert(v.at(casilla) == '-');

	v.at(casilla) = ficha;
}

//precondicion:
//postcondicion:devuelve una lista con las casillas vacias
int TicTacToe::casillas_vacias() const
{
	vec<int> v2;
	for(int i = 0; i<9;i++)
	{
		if(v.at(i) == '-')
		{
			v2.push_back(i);
		}
	}
	return v2;
}


//precondicion: la casilla esta entre el rango permitido (mayor o igual a 0 y menor que 9)
//postcondicion: devuelve la ficha de esa posicion
char TicTacToe::ficha_casilla(int casilla)
{
	assert(casilla >= 0 && casilla < 9);
	return v.at(casilla);
}

//precondicion: la ficha es una de las disponibles
//postcondicion: devuelve true si el jugador especifico ha ganado y false si no
bool TicTacToe::victoria(char ficha) const
{
	assert(ficha == 'x' || ficha == 'o');

	return ((v.at(0) == ficha && v.at(1) == ficha && v.at(2) == ficha) ||
			(v.at(3) == ficha && v.at(4) == ficha && v.at(5) == ficha) ||
			(v.at(6) == ficha && v.at(7) == ficha && v.at(8) == ficha) ||
			(v.at(0) == ficha && v.at(3) == ficha && v.at(6) == ficha) ||
			(v.at(1) == ficha && v.at(4) == ficha && v.at(7) == ficha) ||
			(v.at(2) == ficha && v.at(5) == ficha && v.at(8) == ficha) ||
			(v.at(0) == ficha && v.at(4) == ficha && v.at(8) == ficha) ||
			(v.at(2) == ficha && v.at(4) == ficha && v.at(6) == ficha));
}

//precondicion: el tablero esta entero ocupado
//postcondicion: devuelve true si hay empate y false si no
bool TicTacToe::empate()
{
	for (int i = 0; i<9;i++)
	{
		if(v.at(i) == '-')
		{
			assert(false);
		}
	}
	char x = 'x';
	char o = 'o';
	return(!victoria(x) && !victoria(o));
}

//precondicion:
//postcondicion:elimina el tablero
TicTacToe::~TicTacToe()
{
	
}