#ifndef ROBOT_H
#define ROBOT_H

#include "instruccion.h"
#include "slot.h"

class robot_t{
  private:
  coordenada _homex;
  coordenada _homey;
  coordenada _ubicacion_actualx;
  coordenada _ubicacion_actualy;
  numero _id_robot;
  string _estado;
  vector<instruccion_t*> _instrucciones;
  public:
  vector<columna> _ruta;
  vector<vector<columna>> _rutas_dibujar;
  //Setters
  robot_t(coordenada fila, coordenada columna, numero id_robot);
  void set_ubicacion_actual(coordenada fila, coordenada columna);
  void set_id_robot(numero id_robot);
  void set_instrucciones(instruccion_t* la_instruccion_recibida);
  void set_estado(string estado);
  //Getters
  coordenada get_homex();
  coordenada get_homey();
  coordenada get_ubicacion_actualx();
  coordenada get_ubicacion_actualy();
  numero get_id_robot();
  vector<instruccion_t*> get_instrucciones();
  instruccion_t* get_instruccion(numero indice);
  string get_estado();
  vector<columna> get_ruta();

  void dejar(instruccion_t* ins, slot_t &slot_e);
  void recoger(instruccion_t* ins, slot_t &slot_e);
  virtual ~robot_t();
};
#endif
