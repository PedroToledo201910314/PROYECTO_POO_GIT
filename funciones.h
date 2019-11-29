#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "instruccion.h"
#include "robot.h"
#include "biblioteca.h"
#include "almacen.h"

void bienvenida();
void ingresar_coordenadas_ruta(robot_t* robot1, instruccion_t* ins);

bool colision(columna coord, robot_t* robot);
numero posicion_colision(robot_t* robot_a, robot_t* robot_b);
vector<columna> rut_alt(robot_t* robot_p, robot_t* robot_s, almacen_t* almacen);
void agregar_ruta_alterna(robot_t* robot_p, vector<robot_t*> robots, almacen_t* almacen);

void cantidad_robots(int & n_robots, numero f, numero c);
void num_instrucciones(int &num);
void setea_almacen (numero &filas, numero &columnas, numero &capacidad);
vector<instruccion_t*> pide_instrucciones(numero n_instrucciones,almacen_t* almacen);
void dibuja_ruta(numero columnas, numero filas, vector<arreglo> matriz);
void reporte_slots(almacen_t* almacen_de_slots);
void reporte(vector<instruccion_t*> instrucciones, almacen_t* a1, numero num_ins);

void rutas(numero n_instrucciones,vector<instruccion_t*> instrucciones,numero filas_almacen, numero columnas_almacen, almacen_t* a1);

void genera_archivos_slots(almacen_t* almacen_de_slots);

void logo();

void limpiar();

void menu(vector<instruccion_t*> instrucciones, almacen_t* a1, numero n_instrucciones, numero filas_almacen, numero columnas_almacen);

#endif
