#include <vector>
#include <iterator>

// Templeta de Clase Matriz
//
// La matriz se ha construido sobre un objeto "vector de vectores" estandar de C++. Esto nos da varias
// ventajas. La más importante es que no necesitamos establecer un máximo de filas / columnas de la 
// matriz, pudiendo ser tan grande como se desee. 
// 
//
// El uso de template permite que la matriz pueda ser de cualquier tipo: int, double, etc... la matriz
// puede ser una matriz de cualquier tipo de objetos: una matriz de Strings por ejemplo... incluso una 
// matriz de matricea. La única condición es sofisticar los operadores para que permita las operaciones 
// de multiplicación por un escalar o multiplicación de dos matricez de acuerdo con el álgebra deseada.
// 
// La implementación de la sobrecarga de parámetros puede ser más rica. Sólo se ha implementado lo
// básico. Por ejemplo, no está implementada la suma de matrices de diferentes tipos (sumar una matriz 
// de entradas <int> con una matriz de entradas <double>)

template <class TIPO> 
class Matriz {

private:
	// vector de vectores privado sobre el que se monta la matriz
	std::vector< std::vector<TIPO> > entradas;

public:
	// contructor por defecto
	Matriz() {	}

	// contructor de una matriz de f x c nula
	Matriz(int f, int c) {
		int i;

		this->entradas.resize(f);
		for( i=0; i<f; i++)
			this->entradas[i].resize(c);
	}

	// contructor de una matriz a partir de los elementos
	Matriz(std::vector< std::vector<TIPO> > e) {
		// TODO: comprobar que todos los vectores filas tienen el mimso número de columnas
		this->entradas = e;
	}

	// establece el valor de una entrada concreta (fila f y columna c) de la matriz
	void setEntrada(int f, int c, TIPO e) {
		// TODO: comprobar que f y c estan dentro de las dimensiones de la matriz
		this->entradas[f][c] = e;
	}

	// retorna el valor de una entrada concreta de la matriz
	TIPO getEntrada(int f, int c) {
		// TODO: comprobar que f y c estan dentro de las dimensiones de la matriz
		return this->entradas[f][c];
	}

	// retorna las filas de la matriz
	int filas() {
		// TODO: ¿que pasa si se ha inicializado a nulo?
		return this->entradas.size();
	}

	// retorna la columnas de la matriz
	int columnas() {
		// columnas coincide con el tamaño de cualquier vector, por ejemplo... el primero
		return this->entradas.begin()->size();
	}

	// sobrecarga de operador '<<' sobre std::ostream
	friend std::ostream &operator << (std::ostream &out, Matriz<TIPO> &m)	{

		int i, j;

        out << "matriz de " << m.filas() << " x " << m.columnas() << ":" << std::endl;

        // recorremos todas las filas
        for (i = 0; i != m.filas(); ++i) {

        	// todas las columnas de la fila
	        for (j = 0; j != m.columnas(); ++j)

	        	out << m.getEntrada(i, j) << " ";

    		out << std::endl;
    	}

        return out;
    }


};

// sobrecarga del operador '+' suma de matrices
template <typename TIPO>
Matriz<TIPO> operator + (const Matriz<TIPO> &m1, const Matriz<TIPO> &m2) {

		int i, j;

		int f = m2.filas();
		int c = m2.columnas();

    	// TODO: comprobar que las matrices son de la misma dimensión

    	// matriz resultado
    	Matriz<TIPO> suma(f, c);

        // recorremos todas las filas de la primera matriz
        for (i = 0; i != m1.filas(); ++i) 

        	// todas las columnas de la fila
	        for (j = 0; j != m1.columnas(); ++j)

	        	// sumamos elementos
	        	suma.setEntrada(i, j, m1.getEntrada(i, j) + m2.getEntrada(i, j));

	    return suma;
    }


// TODO: Operador suma de matrices

// TODO: Operador matriz por un escalara

// TODO: Operador multiplicación de matrices
