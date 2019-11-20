#include "slot.h"

slot_t::slot_t(coordenada posx, coordenada posy, numero capacidad){
  _posx = posx;
  _posy = posy;
  _capacidad=capacidad;
  _tipo_slot=false;
  _tipo_producto="Ninguno";
  _estado='E';
  _cantidad=0;
}

void slot_t::set_posicion(coordenada fila, coordenada columna){
  _posx = fila;
  _posy = columna;
}
void slot_t::set_tipo_slot(bool tipo_slot){
  _tipo_slot=tipo_slot;
}
void slot_t::set_tipo_producto(string tipo_producto){
  if (_estado=='E'){
    _tipo_producto = "Ninguno";
  }
  else if(_estado=='L'){
    _tipo_producto=tipo_producto; 
  }
}
void slot_t::set_cantidad(numero cantidad){
  _cantidad=cantidad;
}
void slot_t::set_estado(letra estado){
  _estado=estado;
}
void slot_t::set_capacidad(numero capacidad){
  _capacidad=capacidad;
}

numero slot_t::get_posicionx(){
  return _posx;
}
numero slot_t::get_posiciony(){
  return _posy;
}
bool slot_t::get_tipo_slot(){
  return _tipo_slot;
}
string slot_t::get_tipo_producto(){
  return _tipo_producto;
}
numero slot_t::get_cantidad(){
  return _cantidad;
}
letra slot_t::get_estado(){
  return _estado;
}
numero slot_t::get_capacidad(){
  return _capacidad;
}

void slot_t::actualizar(){
  if(_cantidad==_capacidad){
    set_estado('F'); //Full - lleno
  }
  else if(_cantidad==0){
    set_estado('E'); //Empty - Vacio
    set_tipo_producto("Ninguno");
  }
  else {
    set_estado('L'); //Libre
  }
}
void slot_t::adicionar(string tipo_producto){
  if(_tipo_producto==tipo_producto){
    if(_cantidad+1<=_capacidad){
    _cantidad++;
    }
  actualizar();
  }
  else if(_tipo_producto=="Ninguno"){
    _tipo_producto=tipo_producto;
    if(_cantidad+1<=_capacidad){
    _cantidad++;
    }
  actualizar();
  }
}
void slot_t::retirar(string tipo_producto){
  if(_tipo_producto==tipo_producto){
    if(_cantidad-1>=0){
    _cantidad--;
    }
  actualizar();
  }
}
