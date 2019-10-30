#include "instruccion.h"
#include "biblioteca.h"

void instruccion::set_n_robot(numero n_robot){
  _n_robot=n_robot;
}
void instruccion::set_operacion(letra operacion){
  _operacion=operacion;
}
void instruccion::set_destino(numero fila, numero columna){
  _destino[0]=fila;
  _destino[1]=columna;
}
void instruccion::set_producto(string producto){
  _producto=producto;
}

numero* instruccion::get_destino(){
  return _destino;
}
//
letra instruccion::get_operacion(){
  return _operacion;
}

numero instruccion::get_n_robot(){
  return _n_robot; 
}

string instruccion::get_producto() {
  return _producto;
}
