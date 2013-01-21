#include <iostream>
#include <cstdlib>

#include "jmatriz.hpp"

using namespace std;

int main(void) {

    Matriz<int> m1(5,5);
    Matriz<int> m2( {{1,2},{3,4}} );   // notar que es necesario compilar con -stfd=c++11 para usar listas en el constructor
    Matriz<int> m3( {{5,6},{7,8}} );

    cout << "m1:" << endl;

    cout << "setEntrada" << endl;
    m1.setEntrada(1, 2, 10);

    cout << "getEntrada" << endl;
    cout << m1.getEntrada(1,2) << endl;

    cout << m1;

    cout << endl;

    cout << "m2:" << endl;
    cout << m2 << endl;

    cout << "Suma de m2 + m3:" << endl;
    Matriz<int> suma = m2 + m3;
    cout << suma << endl;

    return 0;
}
