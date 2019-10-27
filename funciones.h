#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
using numero = int;
using letra = char;
using arreglo=vector<char>;
#include "robot.h"
#include "instruccion.h"

vector<vector<char>> llena_almacen (vector <int> home_filas,vector <int> home_columnas, int filas, int columnas);

void cantidad_robots(int & n_robots);

void ingresar(vector<robot>robots,numero num_robots);

void num_instrucciones(int &num);

void pide_instrucciones(int n_instrucciones, vector<instruccion> instrucciones);

//void leer_ruta(vector<vector<numero>>);

void bienvenida();

#endif
