#ifndef CANCION_H
#define CANCION_H
#include <string>
using std::string;
class Cancion {
private:
	string Nombre, Genero;
	int Precio;
public:
	Cancion(string, string ,int);
	void setNombre(string);
	void setGenero(string);
	void setPrecio(int);
	string getNombre();
	string getGenero();
	int getPrecio();
};
#endif
Cancion::Cancion(string n,string g, int p){
	setNombre(n);
	setGenero(g);
	setPrecio(p);
}
void Cancion::setNombre(string Nombre){
	this->Nombre=Nombre;
}
void Cancion::setGenero(string Genero){
	this->Genero=Genero;
}
void Cancion::setPrecio(int Precio){
	this->Precio=Precio;
}
string Cancion::getNombre(){
	return Nombre;
}
string Cancion::getGenero(){
	return Genero;
}
int Cancion::getPrecio(){
	return Precio;
}
