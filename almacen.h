#ifndef ALMACEN_H
#define ALMACEN_H

#include "slot.h" 
#include "robot.h"  
#include "biblioteca.h" 
#include "instruccion.h" 


class almacen{
  private:
  numero _filas;
  numero _columnas;
  numero _capacidad;
  vector <arreglo> _matriz;
  vector<vector<slot>> _matriz_slots;
  public:
  void set_filas(numero filas);
  void set_columnas(numero columnas);
  void set_capacidad(numero capacidad);
  void set_matriz(vector<arreglo> matriz);
  
  vector<arreglo> get_matriz();
  vector<vector<slot>> get_matriz_slots();
  numero get_filas();
  numero get_columnas();

  void crear();
  void imprime();
  void llena_almacen(vector <robot> robots, numero num_robots);

  void posiciones_finales(vector <robot> robots, numero num_robots, vector<instruccion> &instrucciones);

  void dibujar(vector<vector<numero>> mover, numero n_robot); 

  void redimensionar();
};

#endif
