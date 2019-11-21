#include "instruccion.h"

instruccion_t::instruccion_t(numero n_robot, letra operacion, string producto, coordenada dest_x, coordenada dest_y){
  _n_robot=n_robot;
  _operacion=operacion;
  _producto=producto;
  _destinox=dest_x;
  _destinoy=dest_y;
  estado = true;
}

void instruccion_t::set_estado(bool _estado){
  estado = _estado;
}

numero instruccion_t::get_n_robot(){
  return _n_robot; 
}
letra instruccion::get_operacion(){
  return _operacion;
}
string instruccion::get_producto() {
  return _producto;
}
coordenada instruccion_t::get_destinox(){
  return _destinox;
}
coordenada instruccion_t::get_destinoy(){
  return _destinoy;
}
bool instruccion_t::get_estado(){
  return estado;
}
