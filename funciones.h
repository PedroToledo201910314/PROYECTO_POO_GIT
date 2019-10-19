#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

class robot {
  private:
  numero* home=new numero(2);
  string tipo_producto;
  numero* ubicacion_actual=new numero(2);
  numero numero_robot;
  numero numero_intruccion;
  string estado;
  public:
  //Constructor por defecto
  robot();
  robot(numero* _home, string _tipo_producto, numero* _ubicacion, numero numero_robot, numero numero_instruccion, string _estado);
  void dejar();
  void recoger();
  void mover();
  bool colision();
};
  
  
#endif //UNTITLED16_FUNCIONES_H
