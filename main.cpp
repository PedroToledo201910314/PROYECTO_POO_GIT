#include "funciones.h"
#include "biblioteca.h"
#include "instruccion.h"
#include "robot.h"
#include "almacen.h"

int main() {
  bienvenida();

  numero filas_almacen=0, columnas_almacen=0, capacidad_almacen=0;

  setea_almacen(filas_almacen, columnas_almacen, capacidad_almacen);

  almacen_t* a1 = new almacen_t(filas_almacen,columnas_almacen,capacidad_almacen);

  a1->imprime();

  numero n_robots=0;

  cantidad_robots(n_robots);

  a1->set_robots(n_robots);

  a1->llena_almacen(n_robots);

  a1->imprime();

  numero n_instrucciones=0;

  num_instrucciones(n_instrucciones);

  vector<instruccion_t*> instrucciones = pide_instrucciones(n_instrucciones, a1);

  reporte(instrucciones,a1,n_instrucciones);

  rutas(n_instrucciones, instrucciones, filas_almacen, columnas_almacen, a1);

  reporte_slots(a1);

  cout<<endl<<"GRACIAS POR USAR TISG WAREHOUSING!!!";
}
