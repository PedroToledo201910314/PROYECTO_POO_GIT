#include "funciones.h"
#include "almacen.h"
#include "instruccion.h"
#include "robot.h"
#include "slot.h"
#include <string>
#include <fstream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
  bienvenida();
  almacen a1;
  a1.crear();
  a1.imprime();
  
  int num_int=0, num_robots=0;
  
  //ROBOTS
  cantidad_robots(num_robots);
  vector<robot> robots(num_robots);
  ingresar(robot,num_robots);
  
  //INSTRUCCIONES
  num_instrucciones(num_ins);
  vector<intruccion> instrucciones(num_ins);
  pide_instrucciones(num_ins,instrucciones);
  
  //Reporte de estado instrucciones
  realiza_instrucciones(instrucciones, robots, a1);
  a1.imprime();

  //Posiciones finales
  a1.posiciones_finales(robots, num_robots, instrucciones);
  a1.imprime();

  //Estado de slots
  reporte_slots(a1);
  
  //REDIMENSIONAR ALMACEN
  string ans="";
  cout<<endl<<"Desea redimensionar almacen (Si/No): ";
  cin>>ans;
  
  for (int i = 0; i < ans.length(); i++) {ans[i] = toupper(ans[i]);}
  if (ans=="SI"){
    a1.redimesionar();
    a1.imprime();
  }
  
  return 0;
}
