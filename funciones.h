#ifndef PROYECTO_H
#define PROYECTO_H
#include <vector>
#include <string>
using namespace std;
using numero = int;
using letra = char;
using arreglo=vector<char>

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
  

 class slot{
  private:
  numero* posicion = new numero(2);
  bool tipo_slot;
  string tipo_producto;
  numero cantidad;
  letra estado;
  numero capacidad;
  public:
  void adicionar();
  void retirar();
  letra get_estado();
  numero get_cantidad();
};
  

class almacen{
  private:
  numero filas;
  numero columnas;
  numero capacidad;
  vector <arreglo> matriz;
  public:
  almacen();
  almacen(int &_filas, int &_columnas, int &_capacidad, vector <arreglo> &_matriz);
  void crear();
  void imprime();
  void redimensionar();
}

#endif
