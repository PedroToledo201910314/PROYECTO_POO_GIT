#ifndef PROYECTO_H
#define PROYECTO_H

#include "funciones.h"
#include "robot.h"
#include "instruccion.h"
#include "slot.h"
#include "almacen.h"
#include "biblioteca.h"

vector<vector<letra>> instrucciones_robot (numero num_instrucciones,vector<instruccion> &instrucciones);

void cantidad_robots(numero & n_robots);

void ingresar(vector<robot> &robots, numero num_robots, vector<vector<slot>> slots);

void num_instrucciones(numero &num);

void pide_instrucciones(numero n_instrucciones, vector<instruccion> &instrucciones, vector<robot> robots);

void realiza_instrucciones(vector<instruccion> instrucciones, vector<robot> robots, almacen &a1);

void reporte_slots(almacen almacen_de_slots);

void bienvenida();

#endif
