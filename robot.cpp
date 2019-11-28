#include "robot.h"

robot_t::robot_t(coordenada fila, coordenada columna, numero id_robot){
  _homex=fila;
  _homey=columna;
  _ubicacion_actualx=fila;
  _ubicacion_actualy=columna;
  _estado="inactivo";
  _id_robot = id_robot;
}
void robot_t::set_ubicacion_actual(numero fila, numero columna){
  _ubicacion_actualx=fila;
  _ubicacion_actualy=columna;
}
void robot_t::set_id_robot(numero id_robot){
  _id_robot = id_robot;
}
void robot_t::set_instrucciones(instruccion_t* la_instruccion_recibida){
  _instrucciones.push_back(la_instruccion_recibida);
}
void robot_t::set_estado(string estado){
  _estado = estado;
}
coordenada robot_t::get_homex(){
  return _homex;
}
coordenada robot_t::get_homey(){
  return _homey;
}
coordenada robot_t::get_ubicacion_actualx(){
  return _ubicacion_actualx;
}
coordenada robot_t::get_ubicacion_actualy(){
  return _ubicacion_actualy;
}
numero robot_t::get_id_robot(){
  return _id_robot;
}
vector<instruccion_t*> robot_t::get_instrucciones(){
  return _instrucciones;
}
instruccion_t* robot_t::get_instruccion(numero indice){
  instruccion_t* obj=_instrucciones[indice];
  return obj;
}
string robot_t::get_estado(){
  return _estado;
}
vector<columna> robot_t::get_ruta(){
  return _ruta;
}
void robot_t::dejar(instruccion_t* ins, slot_t &slot_e){
  if(slot_e.get_tipo_slot()==false){
    slot_e.adicionar(ins->get_producto());
  }
}
void robot_t::recoger(instruccion_t* ins, slot_t &slot_e){
  if(slot_e.get_tipo_slot()==false){
    slot_e.retirar();
  }
}
robot_t::~robot_t(){
  for(int i=0; i<_instrucciones.size(); i++){
    delete _instrucciones[i];
  }
}



