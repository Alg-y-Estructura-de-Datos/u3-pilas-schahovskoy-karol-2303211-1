#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void reemplazar(Pila<int>& pila, int viejo, int nuevo) {
    Pila<int> pilaAux;

    // Desapila los elementos y reemplaza los valores correspondientes
    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == viejo) {
            pilaAux.push(nuevo);
        } else {
            pilaAux.push(valor);
        }
    }

    // Vuelve a apilar los elementos en la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {
    Pila<int> pila;
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);
    Pila<int> pilanueva;
    mostrarPila(pila);
    reemplazar(pila,3,1);
    mostrarPila(pila);
    return 0;
}
