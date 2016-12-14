#ifndef NODOA_H
#define NODOA_H
//definimos la clase arbol
template<typename T>class Arbol;
template<typename T>
class NodoA {
	friend class Arbol<T>;//definimos clase arbol como amiga de clase NodoA
private:
	/*definimos apuntador izquierdo
	definimos apuntador derecho
	definimos la varible que guardara los datos
	*/
	NodoA<T> *izquierda;
	NodoA<T> *derecha;
	T* Datos;
public:
	//Principio de encapsulamiento definicion de los metodos get and set
	void setIzquierda(NodoA<T> *);
	void setDerecha(NodoA<T> *);
	void setDatos(T *);
	T *getDatos();
	NodoA<T> *getIzquierda();
	NodoA<T> *getDerecha();
};
#endif

template<typename T>
void NodoA<T>::setDatos(T *Datos) {
	this->Datos = Datos;
}
template<typename T>
void NodoA<T>::setDerecha(NodoA<T> *derecha) {
	this->derecha = derecha;
}
template<typename T>
void NodoA<T>::setIzquierda(NodoA<T> *izquierda) {
	this->izquierda = izquierda;
}
template<typename T>
T *NodoA<T>::getDatos() {
	return Datos;
}
template<typename T>
NodoA<T> *NodoA<T>::getDerecha() {
	return derecha;
}
template<typename T>
NodoA<T> *NodoA<T>::getIzquierda() {
	return izquierda;
}
