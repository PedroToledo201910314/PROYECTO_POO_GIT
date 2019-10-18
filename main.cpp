#include <iostream>
#include "funciones.h"
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;

int main() {
  //Define dimensiones del almacen
  int n_filas=0,n_columnas=0;
  almacen(n_filas,n_columnas);
  //Genera matriz que representa el almacen
  vector<vector<char>> matriz_almacen = genera_almacen(n_filas,n_columnas);
  //Imprime el almacen
  imprime_almacen(matriz_almacen,n_filas, n_columnas);
  //Define el numero de robots a implementarse
  int n_robots=0;
  num_robots(n_robots);
  //Vector con las filas y columnas del home de cada robot 
  vector <int> home_filas (n_robots);
  vector <int> home_columnas (n_robots);
  //Ingresa home de cada robot
  ingresar(home_filas,home_columnas,n_robots);
  //Llena el almacen con los robots e imprime
  matriz_almacen = llena_almacen(home_filas, home_columnas, n_filas, n_columnas);
  imprime_almacen(matriz_almacen,n_filas, n_columnas);
  //Define cantidad de instrucciones
  int n_instrucciones=0;
  num_instrucciones(n_instrucciones);
  //Vectores que guardan instrucciones para cada robot
  vector<int> num_robot(n_instrucciones);
  vector<char> operacion(n_instrucciones,' ');
  vector<int> filas_d(n_instrucciones,0); 
  vector<int> columnas_d(n_instrucciones,0); 
  vector<string> productos(n_instrucciones,"");
  //Pide instrucciones 
  pide_instrucciones(num_robot, operacion, filas_d,columnas_d, productos, n_instrucciones);
  return 0;
}
