#ifndef INS_H
#define INS_H
#include "biblioteca.h"

class instruccion{
private:
  numero _n_robot;
  letra _operacion;
  string _producto;
  numero* _destino = new numero[2];
public:
  void set_n_robot(numero n_robot);
  void set_operacion(letra operacion);
  void set_destino(numero fila, numero columna);
  void set_producto(string producto);
  numero* get_destino();
  letra get_operacion();
  numero get_n_robot();
  string get_producto(); 
}

#endif
