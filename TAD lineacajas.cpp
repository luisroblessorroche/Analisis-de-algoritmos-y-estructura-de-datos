//TAD LineaCaja

/*
Un hipermercado dispone para el pago de las compras de 50 cajas numeradas del 1 al 50. El
número de cajas que permanecen abiertas a lo largo del dia es variable, de tal forma, que en cada
momento hay entre 10 y 50 cajas en funcionamiento, dependiendo de la afluencia de clientes
(en las horas y fechas puntas hay mas cajas abiertas que en los momentos de menor clientela),
aunque la media es de 48 cajas abiertas. El horario se cubre cada 2 turnos de trabajo al dia y
en cada turno se supone que hay suficientes cajeros para atender la demanda maxima que se puede
producir y ademas algunos suplentes para sistituir a los que necesitan descansar.
Por cada caja hay que almacenar el numero de caja, el identificador del cajero(3 digitos) y la
facturacion realizada desde el comienzo del turno de trabajo.

Escribe la especificacion del TAD LineaCajas con las siguientes operaciones
	- Crear una linea de cajas cerradas
	- Abrir una caja determinada
	- Cerrar una caja determinada y devolver la facturación realizada en ella desde la 
	  ultima vez que se abrió
	- Cobrar a un cliente el importe de su compra en una caja
	- Sustituir al cajero de una determinada caja. La caja sigue funcionando
	- Cambiar el turno de trabajo y devolver la recaudación total que hay en las cajas
	  en el momento del cambio. En esta operación puede que el total de cajas, asi como
	  cajas concretas de uno u otro no coincidan.
	- Cerrar todas las cajas y devolver la recaudación total que hay en ellas en el momento
	  del cierre.

Realiza la implementación del TAD LineasCajas, teniendo en cuenta lo siguiente:
	- El tiempo de ejecución de cerrar una caja, cobrar la compra y sustituir a un cajero
	  debe ser constante.
	- Justificar razonadamente la estructura de datos elegida en terminos de eficiencia
	  en espacio y tiempo.
*/

//-----------------------------SOLUCIÓN------------------------------

/*
Para este ejercicio vamos a hacer uso de vectores en vez de cualquiera de las representaciones
vistas en clase.
Podriamos pensar y hacerlo con una lista vectorial, pero esto inclumpliria que el tiempo de ejecución
de cerrar una caja, cobrar la compra y sustituir a un cajero, ya que con la lista serian de orden
lineal y con un vector de orden constante ya que podemos acceder directamente al elemento del vector.

Podemos hacer uso tanto de vectores normales(vistos en IP por ejemplo) como de vectores de la STL.
en mi caso usare vectores de la STL.

No explicare la parte privada del vector de la STL ya que viene en la libreria de c++.
*/

//Las operaciones que usare del vector serán las siguientes:
const T& at(int pos);

//El vector estara formado de cajas por lo que su estructura será la siguiente:
struct caja
{
	int num_caja;
	int id_cajero;
	float facturacion;
	bool abierto;
}

//La clase será la siguiente:

class LineaCajas
{
	public:
		LineaCajas();
		void abrir_caja(int id,int x);
		float cerrar_caja_devolver_fact(int x);
		void cobrar_cliente(float importe,int x);
		void sustituir_cajero(int x);
		float cambiar_turno_trabajo_y_devolver_recaudacion_total();
		float cerrar_cajas_devolver_recaudacion_total();
	private:
		vector<caja> v;
}

//precondicion:
//postcondicion:crea 50 cajas cerradas
LineaCajas::LineaCajas()
{
	v = new vector<caja>v(50);

	for(int i = 0;i<50;i++)
	{
		v.at(i).num_caja = i+1;
		v.at(i).abierto = false;
	}
}

//precondicion: la caja ya estaba abierta o el numero de caja no es uno disponible
//postcondicion:abre una caja determinada
LineaCajas::abrir_caja(int id, int x)
{
	x = x--;
	assert(x>=0 && x<50);
	assert(v.at(x).abierto == false);

	v.at(x).id_cajero = id;
	v.at(x).abierto = true;
	v.at(x).facturacion = 0;
}


//precondicion: la caja es una de las disponibles y esta abierta
//postcondicion: cierra la caja y devuelve lo facturado hasta el momento;
float LineaCajas::cerrar_caja_devolver_fact(int x)
{
	x = x--;
	assert(x>=0 && x<50);
	assert(v.at(x).abierto == true);

	float facturacion = v.at(x).facturacion;
	v.at(x).facturacion = 0;
	v.at(x).abierto = false;
	return facturacion;
}

//precondicion:la caja esta abierta y el importe es superior a 0(algo obvio pero bueno), la caja es una de las disponibles
//postcondicion: realiza una compra
void LineaCajas::cobrar_cliente(float importe, int x)
{
	x = x--;
	assert(x>=0 && x<50);
	assert(importe > 0);
	assert(v.at(x).abierto == true);

	v.at(x).facturacion = v.at(x).facturacion + importe;
}


//precondicion: la caja es una existente y esta abierta
//postcondicion: cambia al cajero por otro
void LineaCajas::sustituir_cajero(int id, int x)
{
	x = x--;
	assert(x>=0 && x<50);
	assert(v.at(x).abierto == true);

	v.at(x).id_cajero = id;
}


//precondicion:
//postcondicion: cierra todas las cajas y devuelve todo lo recaudado

float LineaCajas::cerrar_cajas_devolver_recaudacion_total()
{
	float recaudacion_total = 0;
	for (int i = 0; i<50;i++)
	{
		if(v.at(x).abierto == true)
		{
			recaudacion_total = recaudacion_total + v.at(x).facturacion;
			v.at(x).facturacion = 0;
			v.at(x).abierto = false;
		}
	}
	return recaudacion_total;
}


