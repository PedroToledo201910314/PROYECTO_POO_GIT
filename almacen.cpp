#include "almacen.h"
using namespace std;

almacen::almacen(){
  int filas;
  int columnas;
  int capacidad;
  vector <vector<char>> matriz;
  vector <vector<slot>> matriz_1;
}

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

void almacen::crear(){
  cout<<"Ingrese filas del almacen: ";cin>>_filas;
  cout<<"Ingrese columnas del almacen: ";cin>>_columnas;
  cout<<"Ingrese capacidad: ";cin>>_capacidad;
  _matriz = vector<arreglo>(_filas, arreglo(_columnas,' '));
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

vector<vector<char>> llena_almacen (vector <int> home_filas,vector <int> home_columnas, int filas, int columnas){
  vector<vector<char>> matriz_almacen (filas,vector<char>(columnas,' '));
  for (size_t k=0;k<home_filas.size();k++){
    matriz_almacen[home_filas[k]][home_columnas[k]]='*';
  }
  return matriz_almacen;
}
