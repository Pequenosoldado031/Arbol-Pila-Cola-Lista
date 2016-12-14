#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <fstream>
#include <string>
#include "Pila.h"
using std::string;
using std::ifstream;
using std::ofstream;
template<typename T>
//definimos cola que hereda la parte publica de pila
class Cola:public Pila<T> {
public:
	//Funciones para modificar la cola
	void Ingresar(T *);
	void Eliminar();
	void mostrar();
	void Guardar(string);
};
#endif
template<typename T>
void Cola<T>::Guardar(string txt) {
	Lista<T>::guardar(txt);
}
template<typename T>
void Cola<T>::mostrar() {
	Lista<T>::Mostrar();
}
template<typename T>
void Cola<T>::Eliminar() {
	Lista<T>::EliminarInicio();
}
template<typename T>
void Cola<T>::Ingresar(T *nuevo) {
	Lista<T>::IngresarFinal(nuevo);
}
