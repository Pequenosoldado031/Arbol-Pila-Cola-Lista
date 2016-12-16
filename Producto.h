#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using std::string;
class Producto{
private:
string producto;
string marca;
int precio;
public:
Producto(string,string,int);
void setProducto(string);
void setMarca(string);
void setPrecio(int);
string getProducto();
string getMarca();
int getPrecio();
};
#endif
Producto::Producto(string P,string M, int p){
setProducto(P);
setMarca(M);
setPrecio(p);
}
void Producto::setProducto(string p){
this->producto=p;
}
void Producto::setMarca(string m){
this->marca=m;
}
void Producto::setPrecio(int p){
this->precio=p;
}
string Producto::getProducto(){
return producto;
}
string Producto::getMarca(){
return marca;
}
int Producto::getPrecio(){
return precio;
}
