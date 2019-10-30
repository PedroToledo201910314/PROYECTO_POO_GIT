#include "slot.h"
#include "biblioteca.h"

void slot::set_posicion(numero* posicion){
  _posicion=posicion;
}
void slot::set_tipo_slot(bool tipo_slot){
  _tipo_slot=tipo_slot;
}
void slot::set_tipo_producto(string tipo_producto){
  _tipo_producto=tipo_producto;
}
void slot::set_cantidad(numero cantidad){
  _cantidad=cantidad;
}
void slot::set_estado(letra estado){
  _estado=estado;
}
void slot::set_capacidad(numero capacidad){
  _capacidad=capacidad;
}

numero* slot::get_posicion(){
  return _posicion;
}
bool slot::get_tipo_slot(){
  return _tipo_slot;
}
string slot::get_tipo_producto(){
  return _tipo_producto;
}
numero slot::get_cantidad(){
  return _cantidad;
}
letra slot::get_estado(){
  return _estado;
}
numero slot::get_capacidad(){
  return _capacidad;
}

void slot::adicionar(){
  _cantidad++; //Por ahora falta adiconar las condicionales.
}
void slot::retirar(){
  _cantidad--; //Por ahora falta adiconar las condicionales.
}
