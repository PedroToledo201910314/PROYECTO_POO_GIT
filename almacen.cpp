#include "almacen.h"
#include "robot.h"
#include "funciones.h"
#include "biblioteca.h"
#include "instruccion.h"

void almacen::set_filas(numero filas){
  _filas = filas;
}

void almacen::set_columnas(numero columnas){
  _columnas = columnas;
}

void almacen::set_capacidad(numero capacidad){
  _capacidad = capacidad;
}

void almacen::set_matriz(vector<arreglo> matriz){
  _matriz = matriz;
}
  
vector<arreglo> almacen::get_matriz(){
  return _matriz;
}

vector<vector<slot>> almacen::get_matriz_slots(){
  return _matriz_slots;
}

numero almacen::get_filas(){
  return _filas;
}

numero almacen::get_columnas(){
  return _columnas;
}

void almacen::crear(){
  cout<<"Ingrese filas del almacen: ";cin>>_filas;
  cout<<"Ingrese columnas del almacen: ";cin>>_columnas;
  cout<<"Ingrese capacidad: ";cin>>_capacidad;
  _matriz_slots = vector<vector<slot>> (_filas, vector <slot>(_columnas));
  _matriz = vector<arreglo>(_filas, arreglo(_columnas,' '));
  for (size_t i=0;i<_filas;i++){
    for(size_t j=0;j<_columnas;j++){
      (_matriz_slots[i][j]).set_capacidad(_capacidad);
    }
  }
}

void almacen::imprime(){
  cout<<endl;
  cout<<"  ";
  for(size_t z=0;z<_columnas;z++){
    cout<<setw(4)<<z;
  } cout<<endl;
  cout<<"   ";
  for(size_t z=0;z<_columnas;z++){
    cout<<setw(4)<<"___";
  }
  cout<<endl;
  for(size_t i=0;i<_filas;i++){
    cout<<"   ";
    for(size_t j=0;j<_columnas;j++){
      cout<<"|"<<setw(4);
    }
    cout<<"|"<<endl;
    cout<<i<<' ';
    if(i<10){
      cout << ' ';
    }
    for(size_t j=0;j<_columnas;j++){
      _matriz[i][j];
      cout<<"|"<<setw(2)<<_matriz[i][j]<<setw(2);
    }
    cout<<"|"<<endl;
    cout<<"   ";
    for(size_t j=0;j<_columnas;j++){
      cout<<"|___";
    }
    cout<<"|"<<endl;
  }
  cout<<endl;
}

void almacen::redimensionar(){
  cout<<endl<<"Ingrese nueva cantidad de filas del almacen: ";cin>>_filas;
  cout<<"Ingrese nueva cantidad de columnas del almacen: ";cin>>_columnas;
  _matriz = vector<arreglo>(_filas, arreglo(_columnas,' '));
  _matriz_slots = vector<vector<slot>> (_filas, vector <slot>(_columnas));
}

void almacen::llena_almacen (vector<robot> robots, numero num_robots){
  for (size_t k=0;k<num_robots;k++){
    char number='0'+k+1;
    _matriz[(robots[k].get_home())[0]][(robots[k].get_home())[1]]=number;
  }
}

void almacen::dibujar(vector<vector<numero>> mover, numero n_robot){
  for (size_t k=0;k<mover.size();k++){
    char number='0'+n_robot;
    _matriz[(mover[k][0])][(mover[k][1])]=number ;}
}

void almacen::posiciones_finales (vector<robot> robots, numero num_robots, vector<instruccion> &instrucciones){
  for (size_t k=0;k<instrucciones.size();k++){
    numero robot_asignado = instrucciones[k].get_n_robot();
    robots[robot_asignado-1].set_ubicacion_actual((instrucciones[k].get_destino())[0],(instrucciones[k].get_destino())[1]);
    _matriz[(robots[robot_asignado-1].get_ubicacion_actual())[0]][(robots[robot_asignado-1].get_ubicacion_actual())[1]]='+';
  }
}
