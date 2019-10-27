#include "robot.h"
using namespace::std;

void robot::set_home(numero* home){
  _home=home;
}
 
void robot::set_tipo_producto(string tipo_producto){
  _tipo_producto=tipo_producto;
}
  
void robot::set_ubicacion_actual(numero* ubicacion_actual){
  _ubicacion_actual=ubicacion_actual;
}

void robot::set_id_robot(numero id_robot){
  _id_robot=id_robot;
}

void robot::set_instrucciones(vector<instruccion> instrucciones){
  _instrucciones=instrucciones;
}

void robot::set_estado(string estado){
  _estado=estado;
}

numero* robot::get_home(){
  return _home;
}

string robot::get_tipo_producto(){
  return _tipo_producto;
}

numero* robot::get_ubicacion_actual(){
  return _ubicacion_actual;
}

numero robot::get_id_robot(){
  return _id_robot;
}

vector<instruccion> robot::get_instrucciones(){
  return _instrucciones;
}

string robot::get_estado(){
  return _estado;
}

void robot::dejar(string tipo_producto, slot posicion_slot, instruccion &la_instruccion){
  cout << "En proceso.";
}

void robot::recoger(){
  cout << "En proceso.";
}

vector<vector<numero>> robot::mover(vector<robot> robots, numero turno){
  if (!colision(robots)){
    _ubicacion_actual=nullptr;
  }
  vector<vector<numero>> n={{1,2},{2,3}}; //solo como ejemplo
  return n;
}

bool robot::colision(vector<robot> robots){
  return true;
}

robot::~robot(){
  delete[]_home;
  delete[]_ubicacion_actual;
  _home=nullptr;
  _ubicacion_actual=nullptr;
}


