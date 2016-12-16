#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "NodoL.h"
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::ofstream;
template<typename T>
//definicion de la clase Lista
class Lista {
private:
	//definicion del nodo Inicio y Nodo Final de la lista
	NodoL<T> *Inicio;
	NodoL<T> *Final;
public:
	Lista(); //Constructor
	//metodos set and get
	void setInicio(NodoL<T> *);
	void setFinal(NodoL<T> *);
	NodoL<T> *getInicio();
	NodoL<T> *getFinal();
	//Funciones para modificar la informacion contenida en la lista
	void IngresarInicio(T *);
	void IngresarFinal(T *);
	void EliminarInicio();
	void EliminarFinal();
	void Mostrar();
	void Leer(string);
	void guardar(string);
};
#endif
template<typename T>
Lista<T>::Lista() {
	setInicio(NULL);
	setFinal(NULL);
}
template<typename T>
void Lista<T>::setInicio(NodoL<T> *inicio) {
	this->Inicio = inicio;
}
template<typename T>
void Lista<T>::setFinal(NodoL<T> *Final) {
	this->Final = Final;
}
template<typename T>
NodoL<T> *Lista<T>::getInicio() {
	return Inicio;
}
template<typename T>
NodoL<T> *Lista<T>::getFinal() {
	return Final;
}
template<typename T>
//Guarda dentro de un fichero de texto ".txt" la informacion contenida dentro de la lista
void Lista<T>::guardar(string txt) {
	ofstream guarda(txt.c_str());
	NodoL<T> *aux = getInicio();
	while (aux) {
		guarda << aux->getDatos()->getPrecio() <<" "<< aux->getDatos()->getMarca() <<" "<< aux->getDatos()->getPrecio() << std::endl;
		aux = aux->getSiguiente();
	}
}
template<typename T>
//Lee datos contenidps dentro de un fichero ".txt"
//y los ingresa a la lista
void Lista<T>::Leer(string txt) {
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
			IngresarFinal(nuevo);
		}
	}
}
//Mostramos Informacion contenida dentro de la lista
template<typename T>
void Lista<T>::Mostrar() {
	//evalua si existe el nodo Inicio y Nodo Final
	if (getInicio() && getFinal()) {
		//evalua si el nodo Inicio y el nodo final son iguales
		if (getInicio() == getFinal()) {
			//si son iguales solo imprime la imformacion del nodo inicio
			NodoL<T> *aux = getInicio();
			std::cout << "Nombre: " << aux->getDatos()->getProducto() << std::endl;
			std::cout << "Genero: " << aux->getDatos()->getMarca() << std::endl;
			std::cout << "Precio: " << aux->getDatos()->getPrecio() << std::endl;
		}//si no son iguales
		else {
			//auxiliar toma los datos contenidos dentro del nodo inicio
			NodoL<T> *aux = getInicio();
			//mientras exista auxiliar "aux sea diferente de NULL"
			while (aux) {
				//inprime los datos contenidos en la lista
				std::cout << "Nombre: " << aux->getDatos()->getProducto() << std::endl;
				std::cout << "Genero: " << aux->getDatos()->getMarca() << std::endl;
				std::cout << "Precio: " << aux->getDatos()->getPrecio() << std::endl;
				//aux obtendra los datos del apuntador siguiente
				aux = aux->getSiguiente();
			}
		}
	}
	else {
		std::cout << "Lista vacia" << std::endl;
	}
}
//eliminamos el nodo inicio
template<typename T>
void Lista<T>::EliminarInicio() {
	//si existe Inicio y Final
	if (getInicio() && getFinal()) {
		//si Inicio i Final son iguales
		if (getInicio() == getFinal()) {
			//definismos Inicio y Final como NULL
			setInicio(NULL);
			setFinal(NULL);
		}
		//si no son iguales
		else {
			//*aux Toma informacion contenida dentro de nodo Inicio
			NodoL<T> *aux = getInicio();
			//enviamos los datos del siguiente nodo al nodo Inicio
			setInicio(getInicio()->getSiguiente());
			delete aux; //eliminamos aux para evitar sobrecarga de memoria
		}
	}
	else {
		std::cout << "Lista vacia" << std::endl;
	}
}
//eliminamos Datos del Nodo final
template<typename T>
void Lista<T>::EliminarFinal() {
	//si existe inicio y final
	if (getInicio() && getFinal()) {
		//si inicio y final son iguales
		if (getInicio() == getFinal()) {
			//definimos inicio y final como NULL "espacio de memoria 0000000000"
			setInicio(NULL);
			setFinal(NULL);
		}
		//si inicio y final no son iguales
		else {
			//aux Toma la informacion de del Nodo Inicio
			NodoL<T> *aux = getInicio();
			//mientras aux el apuntador al siguiente nodo sea diferente al Nodo final
			while (aux->getSiguiente() != getFinal()) {
				//aux toma la informacion del nodo siguiente
				aux = aux->getSiguiente();
			}
			//enviamos aux como nodo Final
			setFinal(aux);
			//eliminamos el nodo siguiente
			delete aux->getSiguiente();
			aux->setSiguiente(NULL);
		}
	}
	else {
		std::cout << "Lista vacia" << std::endl;
	}
}
//Ingresamos datos al inicio de la lista
template<typename T>
void Lista<T>::IngresarInicio(T *nuevo) {
	//creamos un nuevo nodo
	NodoL<T> *aux = new NodoL<T>();
	//enviamos datos obtenidos al nodo aux
	aux->setDatos(nuevo);
	//si existe nodo inicio y nodo final
	if (getInicio() && getFinal()) {
		//apuntador siguiente del nodo aux es igual al nodo Inicio
		aux->setSiguiente(getInicio());
		//definimos auxiliar como nodo inicio 
		setInicio(aux);
	}
	//si no existen los nodos Inicio y Final
	else {
		//Nodo final sera igual al nodo aux
		setFinal(aux);
		//a parte siguente del nodo aux ser le asignamos el nodo final
		aux->setSiguiente(getFinal());
		//definimos auxiliar como nodo Inicio
		setInicio(aux);
	}
}
//Ingreso de datos al final de la lista
template<typename T>
void Lista<T>::IngresarFinal(T *nuevo) {
	//creamos un nuevo nodo
	NodoL<T> *aux = new NodoL<T>();
	//enviamos datos obtenidos al nodo aux
	aux->setDatos(nuevo);
	// si nodo inicio y nodo final son iguales
	if (getInicio() && getFinal()) {
		//obtenemos el nodo final para enviarle aux a su nodo siguiente
		getFinal()->setSiguiente(aux);
		//definimos aux como nodo final
		setFinal(aux);
	}
	//si no existen
	else {
		//Nodo final sera igual a nodo aux
		setFinal(aux);
		//a parte siguiente del nodo auxiliar le asignamos el nodo final
		aux->setSiguiente(getFinal());
		//definimos auxiliar como inicio
		setInicio(aux);
	}
}
