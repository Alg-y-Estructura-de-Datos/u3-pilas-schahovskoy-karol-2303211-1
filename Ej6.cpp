#include <iostream>
#include "Pila/Pila.h"
#include <string>

using namespace std;

void registrarDesplazamiento(Pila<string>& pilaMovimientos, const string& movimiento, const string& area) {
    if (movimiento == "in") {
        pilaMovimientos.push(area);
    } else if (movimiento == "out" && !pilaMovimientos.esVacia()) {
        pilaMovimientos.pop();
    }else{
        cout << "error" << endl;
    }
}

void mostrar(Pila<string> &pila){
    Pila<string> pilaAux;
    while (!pila.esVacia()) {
        string valor = pila.pop();
        cout << valor << endl;
        pilaAux.push(valor);
    }
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main(){
    string lugar;
    Pila<string> pila;

    registrarDesplazamiento(pila, "in", "Recepcion");
    registrarDesplazamiento(pila, "in", "Oficina");
    registrarDesplazamiento(pila, "in", "Sala de Reuniones");
    registrarDesplazamiento(pila, "out", "Sala de Reuniones");
    registrarDesplazamiento(pila, "in", "GYM");

    mostrar(pila);
    return 0;
}