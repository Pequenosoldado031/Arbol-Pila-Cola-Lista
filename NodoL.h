#ifndef NODOL_H
#define NODOL_H
//definimos la calse lista
template <typename T> class Lista;
template<typename T>
class NodoL {
	//definimos la clase lista como clase amiga de la clase nodoL
	friend class Lista<T>;
private:
	//datos contenidos dentro del nodo
	NodoL<T> *siguiente;
	T *Datos;

public:
	//Metodos get and set para acceder a las variables privadas
	void setDatos(T *);
	void setSiguiente(NodoL<T> *);
	T *getDatos();
	NodoL<T> *getSiguiente();
};
#endif
template<typename T>
void NodoL<T>::setDatos(T *datos) {
	this->Datos = datos;
}
template<typename T>
void NodoL<T>::setSiguiente(NodoL<T> *sig) {
	this->siguiente = sig;
}
template<typename T>
T *NodoL<T>::getDatos() {
	return Datos;
}
template<typename T>
NodoL<T> *NodoL<T>::getSiguiente() {
	return siguiente;
}