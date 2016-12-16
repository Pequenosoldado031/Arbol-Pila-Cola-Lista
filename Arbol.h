#ifndef ARBOL_H
#define ARBOL_H
#include "NodoA.h"
#include "Cola.h"
#include <iostream>
//definicion de la clase arbol
template<typename T>
class Arbol {
private:
	//definicio de la raiz del arbol
	NodoA<T> *Raiz;
	void IngresarDato(NodoA<T> *, NodoA<T> *);
	NodoA<T> *Nuevo(T*);
	NodoA<T> *Buscar(int, NodoA<T> *);
	void HelpInOrden(NodoA<T>*, Cola<T>&);
	void HelpPostOrden(NodoA<T>*, Pila<T>&);
public:
	Arbol(); //cosntructor
	//metodos get and set
	void setRaiz(NodoA<T> *);
	NodoA<T> *getRaiz();

	//funciones de edicion del arbol
	void Ingresar(T*);
	void InOrden(Cola<T>&);
	void PostOrden(Pila<T>&);
	void PreOrden(NodoA<T>*);
	void Abrir(string);

};
template<typename T>
void Arbol<T>::Abrir(string txt){
	ifstream abrir(txt.c_str());
	if (abrir.fail()) {
		std::cout << "Fatal Error" << std::endl;
	}
	else {
		string nombre,genero;
		int precio;
		while (!abrir.eof()) {
			abrir >> nombre >> genero >> precio;
			//al modificar el objeto o tipo de dato a ultilizar
			//Lista<Cancion>  es necesario modificar la siguiente linea a conveniencia
			T *nuevo = new  T(nombre, genero, precio);
			Ingresar(nuevo);
		}
	}
}
#endif
template<typename T>
void Arbol<T>::HelpPostOrden(NodoA<T> *ptr, Pila<T> &pila) {

	if (getRaiz()) {
		if (ptr) {
			//enviamos apuntador izquierdo a la misma funcion para volver a evaluar
			HelpPostOrden(ptr->getIzquierda(), pila);
			//inprimimos los datos contenidos dentro del nodo actual
			std::cout << "Nombre: " << ptr->getDatos()->getProducto() << std::endl;
			std::cout << "Marca: " << ptr->getDatos()->getMarca() << std::endl;
			std::cout << "Precio: " << ptr->getDatos()->getPrecio() <<std::endl;
			std::cout<<"-------------------------\n";
			pila.Ingresar(ptr->getDatos());
			//enviamos apuntador derecho a la misma funcion para volverse a evaluar
			HelpPostOrden(ptr->getDerecha(), pila);
		}
	}
	else {
		std::cout << "Arbol vacio\n";
	}
}
template<typename T>

void Arbol<T>::HelpInOrden(NodoA<T> *ptr, Cola<T> &cola){
if (getRaiz()) {
		if (ptr) {
			//enviamos apuntador izquierdo a la misma funcion para volver a evaluar
			HelpPostOrden(ptr->getIzquierda(), cola);
			//enviamos apuntador derecho a la misma funcion para volver a evaluar
			HelpPostOrden(ptr->getDerecha(), cola);
			//imprimimos datos del nodo actual del arbol
			std::cout << "Nombre: " << ptr->getDatos()->getProducto() << std::endl;
			std::cout << "Marca: " << ptr->getDatos()->getMarca() << std::endl;
			std::cout << "Precio: " << ptr->getDatos()->getPrecio() <<std::endl;
			std::cout<<"-------------------------\n";
			cola.Ingresar(ptr->getDatos());
		}
	}
	else {
		std::cout << "Arbol vacio\n";
	}

}
template<typename T>
Arbol<T>::Arbol() {
	setRaiz(NULL);
}
template<typename T>
void Arbol<T>::setRaiz(NodoA<T> *Raiz) {
	this->Raiz = Raiz;
}
template<typename T>
NodoA<T> *Arbol<T>::getRaiz() {
	return Raiz;
}
template<typename T>

//creamos nuevo nodo apartir de la informacion recibida
NodoA<T> *Arbol<T>::Nuevo(T *nuevo) {
	NodoA<T> *aux = new NodoA<T>();
	aux->setDatos(nuevo);
	aux->setDerecha(NULL);
	aux->setIzquierda(NULL);
	return aux;
}
template<typename T>
void Arbol<T>::Ingresar(T *nuevo) {
	NodoA<T> *aux = new NodoA<T>();
	aux = Nuevo(nuevo);
	IngresarDato(getRaiz(), aux);
}
//Procesamiento de datos inOrden del arbol
template<typename T>
void Arbol<T>::PostOrden(Pila<T> &pila) {
	HelpPostOrden(getRaiz(),pila);
}
//Procesamiento de datos Preorden
template<typename T>
void Arbol<T>::PreOrden(NodoA<T> *ptr) {
	if (getRaiz()) {
		if (ptr) {
			//inprimimos los datos dentro del nodo actual
			std::cout << "Nombre: " << ptr->getDatos()->getProducto() << std::endl;
			std::cout << "Marca: " << ptr->getDatos()->getMarca() << std::endl;
			std::cout << "Precio: " << ptr->getDatos()->getPrecio() <<std::endl;
			std::cout<<"-------------------------\n";
			//enviamos apuntador izquierdo a la misma funcion para volver a evaluar
			PreOrden(ptr->getIzquierda());
			//enviamos apuntador derecho a la misma funcion para volver a evaluar
			PreOrden(ptr->getDerecha());
		}
	}
	else {
		std::cout << "Arbol vacio\n";
	}
}
//Procesamiento de dats PostOrden
template<typename T>
void Arbol<T>::InOrden(Cola<T> &cola) {
	HelpInOrden(getRaiz(),cola);
}
//private
template<typename T>
void Arbol<T>::IngresarDato(NodoA<T> *raiz, NodoA<T> *nuevo) {
	if (raiz == NULL) {
		setRaiz(nuevo);
	}
	else {
		if ((nuevo->getDatos()->getPrecio()) < (raiz->getDatos()->getPrecio())) {
			if (raiz->getIzquierda() == NULL) {
				raiz->setIzquierda(nuevo);
			}
			else {
				IngresarDato(raiz->getIzquierda(), nuevo);
			}
		}
		else {
			if ((nuevo->getDatos()->getPrecio()) > (raiz->getDatos()->getPrecio())){
				if (raiz->getDerecha() == NULL) {
					raiz->setDerecha(nuevo);
				}
				else {
					IngresarDato(raiz->getDerecha(), nuevo);
				}

			}
			else {
				
			}
		}
	}
}
