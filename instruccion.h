#ifndef INS_H
#define INS_H
#include "biblioteca.h"

class instruccion_t{
private:
  numero _n_robot;
  letra _operacion;
  string _producto;
  coordenada _destinox;
  coordenada _destinoy;
  bool estado;
public:
  instruccion_t(numero n_robot, letra operacion, string producto, coordenada dest_x, coordenada dest_y);
  
  void set_estado(bool _estado);
  
  numero get_n_robot();
  letra get_operacion();
  string get_producto(); 
  coordenada get_destinox();
  coordenada get_destinoy();
  bool get_estado();
}

#endif
