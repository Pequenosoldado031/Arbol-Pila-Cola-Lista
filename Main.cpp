#include "Cancion.h"
#include "Producto.h"
#include "Arbol.h"
template<typename L,typename A>
void Ordenar(L&, A&);
template<typename AR, typename PI, typename CO>
void Guardar(AR&, PI&, CO&);
int main(){
	Arbol<Producto> tienda;
	tienda.Abrir("Fichero.txt");
	Cola<Producto> Compra;
	std::cout<<"Recorrido InOrden\n";
	tienda.InOrden(Compra);
	std::cin.get();
	Pila<Producto> reserva;
	std::cout<<"Recorrido Postorden\n";
	tienda.PostOrden(reserva);
	std::cin.get();
	std::cout<<"Datos Cola\n";
	Compra.mostrar();
	std::cin.get();
	std::cout<<"Datos Pila\n";
	reserva.mostrar();
	std::cin.get();
	Compra.Guardar("ColaArbol.txt");
	reserva.Guardar("PilaArbol.txt");
	std::cout<<"Datos guardados, presione enter para continuar\n";
	std::cin.get();
	return 0;

}
/*int main() {
	//si se decea trabajar con otro objeto o tipo de dato cambiar <Cancion> por <objeto o tipo de dato a utlizar>
	Cola<Cancion> C;
	Pila<Cancion> P;
	Lista <Cancion> L;

	//lee fichero de texto ".txt" si no desea leer fichero ".txt"
	//hacer los siguiente para trabajar con el objeto actual
	//Cancion *nuevo = new Cancion(string,int)
	//IngresarInicio(nuevo);
	//IngresarFinal(nuevo);
	//EliminarInicio();
	//eliminarFinal();
	L.Leer("Fichero.txt");
	//Mostramos la informacion contenida en la lista
	L.Mostrar();
	//definimos Arbol "si se desea trabajar con otro tipo de tado cambiaar <Cancion> por <objeto o tipo de dato a utilizar>"
	Arbol<Cancion> A;
	//enviamos la lista y el arbol para ordenar los datos dentro de la lista
	Ordenar<Lista<Cancion>, Arbol<Cancion> >(L, A);
	std::cout << "InOrden\n";
	//Procesamiento inOrden al ser llamado desde el main es necesario enviar la raiz de el arbol
	A.InOrden(A.getRaiz());
	std::cin.get();
	std::cout << "PreOrden\n";
	//Procesamiento PreOrden al ser llamado desde el main es necesario enviar la raiz de el arbol
	A.PreOrden(A.getRaiz());
	std::cin.get();
	std::cout << "PostOrden\n";
	//Procesamiento PostOrden al ser llamado desde el main es necesario enviar la raiz de el arbol
	A.PostOrden(A.getRaiz());
	std::cin.get();
	return 0;
}*/
template<typename L, typename A>
void Ordenar(L &lista, A &arbol) {
	//Obtenemos el incio de la lista
	NodoL<Cancion> *aux = lista.getInicio();
	//mientras exista auxiliar
	while (aux) {
		//Ingresarmos en el arbol los datos contenidos dentro del nodo de la lista
		//tener en cuenta que es necesario enviar la raiz del arbol
		arbol.Ingresar(aux->getDatos());
		//avanzamos dentro de la lista
		aux = aux->getSiguiente();
	}
}
template<typename AR, typename PI, typename CO>
void Guardar(AR &arbol, PI &pila, CO &cola) {
	
}
