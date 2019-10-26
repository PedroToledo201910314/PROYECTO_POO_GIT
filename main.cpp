#include <iostream>
#include "funciones.h"
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;

int main() {
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
