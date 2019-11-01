#include "robot.h"
using namespace::std;

void robot::set_home(numero* home){
  _home=home;
}
 
void robot::set_tipo_producto(string tipo_producto){
  _tipo_producto=tipo_producto;
}
  
void robot::set_ubicacion_actual(numero* ubicacion_actual){
  _ubicacion_actual=ubicacion_actual;
}

void robot::set_id_robot(numero id_robot){
  _id_robot=id_robot;
}

void robot::set_instrucciones(vector<instruccion> instrucciones){
  _instrucciones=instrucciones;
}

void robot::set_estado(string estado){
  _estado=estado;
}

numero* robot::get_home(){
  return _home;
}

string robot::get_tipo_producto(){
  return _tipo_producto;
}

numero* robot::get_ubicacion_actual(){
  return _ubicacion_actual;
}

numero robot::get_id_robot(){
  return _id_robot;
}

vector<instruccion> robot::get_instrucciones(){
  return _instrucciones;
}

string robot::get_estado(){
  return _estado;
}

void robot::dejar(string tipo_producto, instruccion &la_instruccion, vector <vector<slot>> slots, vector<robot> &robots, almacen &a1){
  if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_tipo_slot()==true){
    cout<<"Este es el home de un robot.";
  }
  else{
    if (robots[la_instruccion.get_n_robot()-1].get_ubicacion_actual()[0]==robots[la_instruccion.get_n_robot()-1].get_home()[0] && robots[la_instruccion.get_n_robot()-1].get_ubicacion_actual()[1]==robots[la_instruccion.get_n_robot()-1].get_home()[1]){
      
      vector<vector<numero>> ruta=mover(robots,robots[la_instruccion.get_n_robot()-1], robots[la_instruccion.get_n_robot()-1].get_home(), la_instruccion.get_destino());
      
      a1.dibujar(ruta, la_instruccion.get_n_robot()-1);

    }
    
    else{
      vector<vector<numero>> ruta1=mover(robots,robots[la_instruccion.get_n_robot()-1], robots[la_instruccion.get_n_robot()-1].get_ubicacion_actual(), robots[la_instruccion.get_n_robot()-1].get_home());

      a1.dibujar(ruta1, la_instruccion.get_n_robot()-1);

      vector<vector<numero>> ruta2= mover(robots,robots[la_instruccion.get_n_robot()-1], robots[la_instruccion.get_n_robot()-1].get_home(), la_instruccion.get_destino());

      a1.dibujar(ruta2, la_instruccion.get_n_robot()-1);
    };
    
    //Acá empieza el reporte
    if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_estado()=='E'){
      slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].set_tipo_producto(tipo_producto);
      cout<<"No hubo problemas.";
    }
    else if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_estado()=='L'){
        if(tipo_producto==slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_tipo_producto()){
        slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].adicionar();
        cout<<"No hubo problemas.";
        }
        else{
          cout<<"Este slot contiene un producto diferente al cual desea ingresar.";
        }
    }
    else{
      cout<<"Este slot esta lleno.";
    }    
  }
}

void robot::recoger(string tipo_producto, instruccion &la_instruccion, vector <vector<slot>> slots, vector<robot> &robots,almacen &a1){
  if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_tipo_slot()==true){
    cout<<"Este es el home de un robot.";
  }
  else{      
      vector<vector<numero>> _ruta=mover(robots,robots[la_instruccion.get_n_robot()-1], robots[la_instruccion.get_n_robot()-1].get_home(), la_instruccion.get_destino());

      a1.dibujar(_ruta, la_instruccion.get_n_robot()-1);
  };
    
    //Acá empieza el reporte
  if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_estado()=='E'){
      cout<<"Este slot está vacío.";
  }
  else if(slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].get_estado()=='L'){
      cout<<"No hubo problemas.";
      slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].retirar();
  }
  else{
      cout<<"No hubo problemas.";
      slots[(la_instruccion.get_destino())[0]][(la_instruccion.get_destino())[1]].retirar();
    } 
}


vector<vector<numero>> robot::mover(vector<robot> robots, robot robot_evaluado, numero* salida, numero* destino){
  numero d_fil=destino[0] - salida[0];
  numero d_col=destino[1] - salida[1];
  vector<vector<numero>> v_mov((abs(d_fil) + abs(d_col)), vector<numero>(2));
  if (colision(robots, robot_evaluado)==false){
    for (int i=0;i<sizeof(v_mov);i++){
      //son 4 posibles direcciones del robot
      if (d_fil>=0 && d_col>=0){
        if(i+1<=d_fil){
          v_mov[i][0]=salida[0]+i+1;
          v_mov[i][1]=salida[1];
        }
        else{
          v_mov[i][0]=destino[0];
          v_mov[i][1]=salida[1]+(i-d_fil)+1;
        }
      }
      else if (d_fil<=0 && d_col>=0){
        if(i+1<=d_fil){
          v_mov[i][0]=salida[0]-i-1;
          v_mov[i][1]=salida[1];
        }
        else{
          v_mov[i][0]=destino[0];
          v_mov[i][1]=salida[1]+(i-d_fil)+1;
        }
      }
      else if (d_fil>=0 && d_col<=0){
        if(i+1<=d_fil){
          v_mov[i][0]=salida[0]+i+1;
          v_mov[i][1]=salida[1];
        }
        else{
          v_mov[i][0]=destino[0];
          v_mov[i][1]=salida[1]-(i-d_fil)-1;
        }
      }
      else if (d_fil<=0 && d_col<=0){
        if(i+1<=d_fil){
          v_mov[i][0]=salida[0]-i-1;
          v_mov[i][1]=salida[1];
        }
        else{
          v_mov[i][0]=destino[0];
          v_mov[i][1]=salida[1]-(i-d_fil)-1;
        }
      }
        
    }
  }
  return v_mov;
}

bool robot::colision(vector<robot> robots, robot robot_evaluado){
  return false;
}

robot::~robot(){
  delete[]_home;
  delete[]_ubicacion_actual;
  _home=nullptr;
  _ubicacion_actual=nullptr;
}


