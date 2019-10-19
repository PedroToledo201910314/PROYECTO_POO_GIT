#ifndef PROYECTO_H
#define PROYECTO_H
#include <vector>
#include <string>
using namespace std;
using numero = int;
using letra = char;
using arreglo=vector<char>

class robot {
  private:
  
  public:
  

class almacen{
  private:
  numero filas;
  numero columnas;
  numero capacidad;
  vector <arreglo> matriz;
  public:
  almacen();
  almacen(int &_filas, int &_columnas, int &_capacidad, vector <arreglo> &_matriz);
  void crear();
  void imprime();
  void redimensionar();
}

#endif //UNTITLED16_FUNCIONES_H
