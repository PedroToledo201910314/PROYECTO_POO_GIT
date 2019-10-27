#ifndef ALMACEN_H
#define ALMACEN_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>
#include "slot.h"
using namespace std;
using numero = int;
using letra = char;
using arreglo=vector<char>;


class almacen{
  private:
  numero _filas;
  numero _columnas;
  numero _capacidad;
  vector <arreglo> _matriz;
  vector<vector<slot>> _matriz_slots;
  public:
  almacen();

  void set_filas(numero filas);
  void set_columnas(numero columnas);
  void set_capacidad(numero capacidad);
  void set_matriz(vector<arreglo> matriz);

  vector<arreglo> get_matriz();

  void crear();
  void imprime();
  void redimensionar();
};

#endif
