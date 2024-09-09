#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main() {
    Pila<char> pila;
    pila.push('k');
    pila.push('a');
    pila.push('r');
    pila.push('o');
    pila.push('l');
    while (!pila.esVacia()) {
        cout << pila.pop();
    }
    return 0;
}