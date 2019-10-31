#ifndef SLOT_H
#define SLOT_H
#include "biblioteca.h"

class slot{
private:
  numero* _posicion = new numero(2);
  bool _tipo_slot;
  string _tipo_producto;
  numero _cantidad;
  letra _estado;
  numero _capacidad;
public:
  void set_posicion(numero* posicion);
  void set_tipo_slot(bool tipo_slot);
  void set_tipo_producto(string tipo_producto);
  void set_cantidad(numero cantidad);
  void set_estado(letra estado);
  void set_capacidad(numero capacidad);
  
  numero* get_posicion();
  bool get_tipo_slot();
  string get_tipo_producto();
  numero get_cantidad();
  letra get_estado();
  numero get_capacidad();
  
  void adicionar();
  void retirar();
}

#endif
