#include "funciones.h"
#include "robot.h"
#include "instruccion.h"
#include "slot.h"
#include "almacen.h"
#include "biblioteca.h"

//Ingresa numero de robots
void cantidad_robots(int & n_robots){
  do{
  cout<<"Ingrese numero de robots: ";cin>>n_robots;}while(n_robots<3);
}

void ingresar(vector<robot> &robots, numero num_robots, vector<vector<slot>> slots){
  cout<<endl; 
  numero fila=0,columna=0;
  for (size_t i=0;i<num_robots;i++){
    cout<<"Origen del robot #"<<i+1<<": "<<endl;
    robots[i].set_id_robot(i+1);
    cout<<"Fila: ";cin>>fila;
    cout<<"Columna: ";cin>>columna;
    (slots[fila][columna]).set_tipo_slot(true);
    cout<<endl;
    robots[i].set_home(fila,columna);
  }
}

//Ingresa instrucciones
void num_instrucciones(int &num){
  cout<<endl;
  cout<<"Ingrese numero de instrucciones: ";cin>>num;
}

void pide_instrucciones(int n_instrucciones, vector<instruccion> &instrucciones, vector<robot> robots){
  for (size_t i=0;i<n_instrucciones;i++){
    cout<<endl<<"Instruccion "<<i+1<<": "<<endl;
    cout<<"---------------"<<endl;
    int numero=0;
    cout<<"Numero de robot: ";cin>>numero;
    instrucciones[i].set_n_robot(numero);
    char op;
    cout<<"Operacion (Ingreso (I)/Retiro (R)): ";cin>>op;
    instrucciones[i].set_operacion(op);
    int fila = 0,columna = 0;
    cout<<"Destino: "<<endl;
    cout<<"Fila: ";cin>>fila;
    cout<<"Columna: ";cin>>columna;
    instrucciones[i].set_destino(fila, columna);
    string product="";
    cout<<"Producto: ";cin>>product;
    instrucciones[i].set_producto(product);
    robots[numero-1].set_instrucciones(instruccion(instrucciones[i]));
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

void realiza_instrucciones(vector<instruccion> instrucciones, vector<robot> robots, almacen &a1 ){
  numero i=1;
  cout<<endl<<"                   REPORTE DE INSTRUCCIONES                   "<<endl;
  cout<<"__________________________________________________________"<<endl;
  for (auto &ins:instrucciones){
    cout<<endl<<"Reporte de instruccion "<<i<<":"<<endl;
    cout<<"---------------------------"<<endl;
    if (ins.get_operacion()=='I'|| ins.get_operacion()=='i'){
        robots[ins.get_n_robot()-1].dejar(ins.get_producto(), ins, a1.get_matriz_slots(), robots, a1);
      }
    else if(ins.get_operacion()=='R'||(ins.get_operacion()=='r')){
        robots[ins.get_n_robot()-1].recoger(ins.get_producto(), ins, a1.get_matriz_slots(), robots, a1);
      }
    i++;
  }
}

void reporte_slots(almacen almacen_de_slots){
  cout<<endl<<"                      REPORTE DE SLOTS                   "<<endl;
  cout<<"__________________________________________________________"<<endl;
  for (size_t i=0;i<almacen_de_slots.get_filas();i++){
    for (size_t j=0;j<almacen_de_slots.get_columnas();j++){
      cout<<"Slot "<<"["<<i<<"]["<<j<<"]:"<<endl;
      cout<<"Tipo de producto: "<<almacen_de_slots.get_matriz_slots()[i][j].get_tipo_producto()<<endl;
      cout<<"Cantidad: "<<almacen_de_slots.get_matriz_slots()[i][j].get_cantidad()<<endl;
    }
  }
}
