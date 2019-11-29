#include "almacen.h"
#include "biblioteca.h"
#include "slot.h"
#include "robot.h"

almacen_t::almacen_t(numero _filas, numero _columnas, numero _capacidad):filas(_filas),columnas(_columnas),capacidad(_capacidad){
  vector<slot_t*> vec_slots(_columnas);
  for (size_t i=0;i<_filas;i++){
    matriz_slots.push_back(vec_slots);
  }
  for (size_t i=0;i<_filas;i++){
    for(size_t j=0;j<_columnas;j++){
      slot_t* s = new slot_t(i,j,capacidad);
      matriz_slots[i][j]=s;
    }
  }
  vector<arreglo> matriz_temp(_filas, arreglo(_columnas,' '));
  matriz = matriz_temp;
}

vector<arreglo> almacen_t::get_matriz(){
  return matriz;
}

vector<vector<slot_t*>> almacen_t::get_matriz_slots(){
  return matriz_slots;
}

numero almacen_t::get_filas(){
  return filas;
}

numero almacen_t::get_columnas(){
  return columnas;
}

numero almacen_t::get_capacidad(){
  return capacidad;
}

vector <robot_t*> almacen_t::get_robots(){
  return robots;
}

void almacen_t::imprime(){
  cout<<endl;
  cout<<"  ";
  for(size_t z=0;z<columnas;z++){
    cout<<setw(4)<<z;
  } cout<<endl;
  cout<<"   ";
  for(size_t z=0;z<columnas;z++){
    cout<<setw(4)<<"___";
  }
  cout<<endl;
  for(size_t i=0;i<filas;i++){
    cout<<"   ";
    for(size_t j=0;j<columnas;j++){
      cout<<"|"<<setw(4);
    }
    cout<<"|"<<endl;
    cout<<i<<' ';
    if(i<10){
      cout << ' ';
    }
    for(size_t j=0;j<columnas;j++){
      matriz[i][j];
      cout<<"|"<<setw(2)<<matriz[i][j]<<setw(2);
    }
    cout<<"|"<<endl;
    cout<<"   ";
    for(size_t j=0;j<columnas;j++){
      cout<<"|___";
    }
    cout<<"|"<<endl;
  }
  cout<<endl;
}

void almacen_t::set_robots(numero cantidad_robots){
  numero fila=0,columna=0;
  for (size_t i=0;i<cantidad_robots;i++){
    cout<<endl<<"Origen del robot #"<<i+1<<": "<<endl;
    cout<<"Fila: ";cin>>fila;
    cout<<"Columna: ";cin>>columna;
    robot_t* robot = new robot_t(fila,columna,i+1);
    robots.push_back(robot);
    matriz_slots[fila][columna]->set_tipo_slot(true);
  }
}

void almacen_t::llena_almacen (numero num_robots){
  for (size_t k=0;k<num_robots;k++){
    char number='0'+k+1;
    matriz[robots[k]->get_homex()][robots[k]->get_homey()]=number;
  }
}
