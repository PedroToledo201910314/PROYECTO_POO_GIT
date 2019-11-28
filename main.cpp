#include "funciones.h"
#include "biblioteca.h"
#include "instruccion.h"
#include "robot.h"
#include "almacen.h"

int main() {
  logo();
  bienvenida(); //Logo y bienvenida

  numero filas_almacen=0, columnas_almacen=0, capacidad_almacen=0;
  setea_almacen(filas_almacen, columnas_almacen, capacidad_almacen);
  almacen_t* a1 = new almacen_t(filas_almacen,columnas_almacen,capacidad_almacen);
  a1->imprime();
  numero n_robots=0;
  cantidad_robots(n_robots,filas_almacen, columnas_almacen);
  a1->set_robots(n_robots);
  a1->llena_almacen(n_robots);
  a1->imprime();
  numero n_instrucciones=0;
  num_instrucciones(n_instrucciones);
  vector<instruccion_t*> instrucciones = pide_instrucciones(n_instrucciones, a1); //Acá termina el ingreso de robots

  limpiar();
  char ans;
  while(true){
  limpiar();
  menu(instrucciones,a1,n_instrucciones,filas_almacen,columnas_almacen);
  cout<<endl<<endl<<endl<<"¿Desea realizar otra acción? (Si->s/No->n): ";cin>>ans;
  if (tolower(ans)=='n'){
    cout<<endl<<"GRACIAS POR USAR TISG WAREHOUSING!!!"<<endl<<endl<<endl;
    break;
    }
  };
}
