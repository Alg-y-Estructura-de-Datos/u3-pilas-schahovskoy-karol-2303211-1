#ifndef U03_PILAS_PILA_PILA_H_
#define U03_PILAS_PILA_PILA_H_

#include "nodo.h"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T>
class Pila
{
private:
  Nodo<T> *tope;

public:
  Pila();

  ~Pila();

  void push(T dato);

  T pop();

  T peek(); // Nueva función para obtener el elemento en el tope sin eliminarlo

  bool esVacia();
};

/**
 * Constructor de la clase Pila
 * @tparam T
 */
template <class T>
Pila<T>::Pila()
{
  tope = nullptr;
}

/**
 * Destructor de la clase Pila, se encarga de liberar la memoria de todos los
 * nodos utilizados en la pila
 * @tparam T
 */
template <class T>
Pila<T>::~Pila()
{
  while (!esVacia())
  {
    pop();
  }

  delete tope;
}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T>
void Pila<T>::push(T dato)
{

  Nodo<T> *nuevo;
  nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  nuevo->setSiguiente(tope);
  tope = nuevo;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T>
T Pila<T>::pop()
{
  if (esVacia())
  {
    throw 400;
  }

  T dato = tope->getDato();
  Nodo<T> *aBorrar = tope;
  tope = tope->getSiguiente();

  delete aBorrar;
  return dato;
}

/**
 * Obtiene el dato en el tope de la pila sin eliminarlo
 * @tparam T
 * @return dato almacenado en el tope
 */
template <class T>
T Pila<T>::peek()
{
  if (esVacia())
  {
    throw 400;
  }

  return tope->getDato();
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T>
bool Pila<T>::esVacia()
{
  return tope == nullptr;
}

#endif // U03_PILAS_PILA_PILA_H_
