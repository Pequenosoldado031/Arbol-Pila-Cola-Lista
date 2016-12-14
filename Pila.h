#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "Lista.h"
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::ofstream;
template<typename T>
//Definimos a clase pila que hereda la parte publica de la clase Lista
class Pila:public Lista<T> {
public:
	//Fuciones para modificar la Pila
	void Ingresar(T *);
	void Eliminar();
	void mostrar();
	void Guardar(string);
};
#endif
template<typename T>
void Pila<T>::Guardar(string txt) {
	Lista<T>::guardar(txt);
}
template<typename T>
void Pila<T>::mostrar() {
	Lista<T>::Mostrar();
}
template<typename T>
void Pila<T>::Eliminar() {
	Lista<T>::EliminarFinal();
}
template<typename T>
void Pila<T>::Ingresar(T *nuevo) {
	Lista<T>::IngresarFinal(nuevo);
}
