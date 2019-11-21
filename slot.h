#ifndef SLOT_H
#define SLOT_H
#include "biblioteca.h"

class slot_t{
private:
  coordenada _posx;
  coordenada _posy;
  bool _tipo_slot; 
  string _tipo_producto;
  numero _cantidad;
  letra _estado;
  numero _capacidad;
public:
  slot_t(coordenada posx, coordenada posy, numero capacidad);
  
  void set_posicion(coordenada fila, coordenada columna);
  void set_tipo_slot(bool tipo_slot);
  void set_tipo_producto(string tipo_producto);
  void set_cantidad(numero cantidad);
  void set_estado(letra estado);
  
  numero get_posicionx();
  numero get_posiciony();
  bool get_tipo_slot();
  string get_tipo_producto();
  numero get_cantidad();
  letra get_estado();
  numero get_capacidad();
  
  void actualizar();
  void adicionar(string tipo_producto);
  void retirar(string tipo_producto);
}

#endif
