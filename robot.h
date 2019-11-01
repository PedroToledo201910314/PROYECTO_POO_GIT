#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>

using numero=int;
using letra=char;

class robot{
  private:
    numero* _home=new numero[2];
    string _tipo_producto;
    numero* _ubicacion_actual=new numero[2];
    numero _id_robot;
    vector<instruccion> _instrucciones;
    string _estado;
  public:
    //setter
    void set_home(numero* home);
    void set_tipo_producto(string tipo_producto);
    void set_ubicacion_actual(numero* ubicación actual);
    void set_id_robot(numero id_robot);
    void set_instrucciones(vector<instruccion> instrucciones);
    void set_estado(string estado);
    
    //getter
    numero* get_home();
    string get_tipo_producto();
    numero* get_ubicacion_actual();
    numero get_id_robot();
    vector<instruccion> get_istrucciones();
    string get_estado();

    void dejar(string tipo_producto, instruccion &la_instruccion, vector <vector<slot>> slots, vector<robot> &robots, almacen &a1);   
  
    void recoger(string tipo_producto, instruccion &la_instruccion, vector <vector<slot>> slots, vector<robot> &robots, almacen &a1);   
  
    vector<vector<numero>> mover(vector<robot> robots, robot robot_evaluado, numero* salida, numero* destino);

    bool colision(vector<robot> robots, robot robot_evaluado);
    virtual ~robot();

};
  
#endif
  
