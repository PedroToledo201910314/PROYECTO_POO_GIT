#include "funciones.h"
#include "robot.h"
#include "instruccion.h"
#include <fstream>
using namespace std;

//Ingresa numero de robots
void cantidad_robots(int & n_robots){
  do{
  cout<<"Ingrese numero de robots: ";cin>>n_robots;}while(n_robots<3);
}

void ingresar(vector<robot>robots,numero num_robots){
  cout<<endl;
  for (size_t i=0;i<num_robots;i++){
    int* home = new int[2];
    cout<<"Origen del robot #"<<i+1<<": ";cin>>home[i]>>home[i];
    robots[i].set_home(home);
  }
}

//Ingresa instrucciones
void num_instrucciones(int &num){
  cout<<endl;
  cout<<"Ingrese numero de instrucciones: ";cin>>num;
}

void pide_instrucciones(int n_instrucciones, vector<instruccion> instrucciones){
  for (size_t i=0;i<n_instrucciones;i++){
    cout<<endl<<"Instruccion "<<i+1<<": "<<endl;
    int numero=0;
    cout<<"Numero de robot: ";cin>>numero;
    instrucciones[i].set_n_robot(numero);
    char op;
    cout<<"Operacion (Ingreso (I)/Retiro (R)): ";cin>>op;
    instrucciones[i].set_operacion(op);
    int* des = new int[2];
    cout<<"Destino (Fila, columna): ";cin>>des[0]>>des[1];
    instrucciones[i].set_destino(des);
    string product="";
    cout<<"Producto: ";cin>>product;
    instrucciones[i].set_producto(product);
  }
}

//Inicio
void bienvenida(){
  ifstream archivo;
  archivo.open("inicio.txt",ios::in);
  string texto;
  while(!archivo.eof()){
    getline(archivo,texto);
    cout<<texto<<endl;
  }
  archivo.close();
}
