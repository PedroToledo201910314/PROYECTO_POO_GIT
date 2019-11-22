#ifndef ALMACEN_H
#define ALMACEN_H

#include "robot.h"
#include "slot.h"

class almacen_t{
  private:
    numero filas;
    numero columnas;
    numero capacidad;
    vector<arreglo> matriz;
    vector<vector<slot_t*>> matriz_slots;
    vector<robot_t*> robots;
  public:
    almacen_t(numero _filas, numero _columnas, numero _capacidad);
    vector<arreglo> get_matriz();
    vector<vector<slot_t*>> get_matriz_slots();
    numero get_filas();
    numero get_columnas();
    numero get_capacidad();
    vector <robot_t*> get_robots();
    void set_robots(numero cantidad_robots);
    void imprime();
    void llena_almacen(numero num_robots);
};

#endif
