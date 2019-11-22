#include "biblioteca.h"
#include "funciones.h"
#include "robot.h"
#include "funciones.h"
#include "instruccion.h"
#include "almacen.h"

void ingresar_coordenadas_ruta(robot_t* &robot1, instruccion_t* ins){
  coordenada ubicx=robot1->get_ubicacion_actualx();
  coordenada ubicy=robot1->get_ubicacion_actualy();
  if(ubicx!=ins->get_destinox()||ubicy!=ins->get_destinoy()){
    while(ubicx!=ins->get_destinox()||ubicy!=ins->get_destinoy()){
      int nx=0;
      int ny=0;
      if(ubicx<ins->get_destinox()){
        nx=1;
        if(ubicy<ins->get_destinoy())
          ny=1;
        else if (ubicy==ins->get_destinoy())
          ny=0;
        else
          ny=-1;
      }
      else if(ubicx==ins->get_destinox()){
        if(ubicy<ins->get_destinoy()){
          ny=1;}
        else if (ubicy==ins->get_destinoy()){
          ny=0;
        }
        else{
          ny=-1;}
      }
      else{
        nx=-1;
        if(ubicy<ins->get_destinoy())
          ny=1;
        else if (ubicy==ins->get_destinoy())
          ny=0;
        else
          ny=-1;
      }
      coordenada respaldox=ubicx;
      coordenada respaldoy=ubicy;
      ubicx=ubicx+nx;
      columna coordenadas_ruta1 = {ubicx, ubicy};
      ubicy=ubicy+ny;
      columna coordenadas_ruta2 = {ubicx, ubicy};
      if(coordenadas_ruta1[0]==respaldox&&coordenadas_ruta1[1]==respaldoy){
        robot1->_ruta.push_back(coordenadas_ruta2);
      }
      else{
        if(coordenadas_ruta1[0]==coordenadas_ruta2[0]&&coordenadas_ruta1[1]==coordenadas_ruta2[1]){
          robot1->_ruta.push_back(coordenadas_ruta2);
        }
        else{
          robot1->_ruta.push_back(coordenadas_ruta1);
          robot1->_ruta.push_back(coordenadas_ruta2);
        }
      }
    }
  }
}

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

void cantidad_robots(int & n_robots){
  do{
  cout<<"Ingrese numero de robots: ";cin>>n_robots;}while(n_robots<3);
}

void num_instrucciones(int &num){
  cout<<endl;
  cout<<"Ingrese numero de instrucciones: ";cin>>num;
}

void setea_almacen (numero &filas, numero &columnas, numero &capacidad){
  cout<<endl;
  cout<<"Ingrese cantidad filas del almacen: ";cin>>filas;
  cout<<"Ingrese cantidad de columnas del almacen: ";cin>>columnas;
  cout<<"Ingrese capacidad de cada slot: ";cin>>capacidad;
}

vector<instruccion_t*> pide_instrucciones (numero n_instrucciones,almacen_t* almacen){
  vector<instruccion_t*> instrucciones;
  for (size_t i=0;i<n_instrucciones;i++){
    cout<<endl<<"Instruccion "<<i+1<<": "<<endl;
    cout<<"---------------"<<endl;
    int numero=0;
    cout<<"Numero de robot: ";cin>>numero;
    char op;
    cout<<"Operacion (Ingreso (I)/Retiro (R)): ";cin>>op;
    int fila = 0,columna = 0;
    cout<<"Destino: "<<endl;
    cout<<"Fila: ";cin>>fila;
    cout<<"Columna: ";cin>>columna;
    string product="";
    if(tolower(op)=='i'){
      cout<<"Producto: ";cin>>product;
    }

    instruccion_t* ins = new instruccion_t(numero,op,product,fila,columna);

    instrucciones.push_back(ins);
    almacen->get_robots()[numero-1]->set_instrucciones(ins);
  }
  return instrucciones;
}

void dibuja_ruta(numero columnas, numero filas, vector<arreglo> matriz){
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

void reporte_slots(almacen_t* almacen_de_slots){
  cout<<endl<<endl<<"                      REPORTE DE SLOTS                   "<<endl;
  cout<<"__________________________________________________________"<<endl;
  for (size_t i=0;i<almacen_de_slots->get_filas();i++){
    for (size_t j=0;j<almacen_de_slots->get_columnas();j++){
      cout<<endl<<endl<<"Slot "<<"["<<i<<"]["<<j<<"]:"<<endl;
      cout<<"Tipo de producto: "<<almacen_de_slots->get_matriz_slots()[i][j]->get_tipo_producto()<<endl;
      cout<<"Cantidad: "<<almacen_de_slots->get_matriz_slots()[i][j]->get_cantidad()<<endl;
      cout<<"Estado: ";
      if(almacen_de_slots->get_matriz_slots()[i][j]->get_estado()=='E'){
        cout<<"Vacío";
      }
      else if(almacen_de_slots->get_matriz_slots()[i][j]->get_estado()=='L'){
        cout<<"Libre";
      }
      else{
        cout<<"Lleno";
      }
    }
  }
}

void reporte(vector<instruccion_t*> instrucciones, almacen_t* a1, numero num_ins){
  cout<<endl<<"                   REPORTE DE INSTRUCCIONES                   "<<endl;
  cout<<"__________________________________________________________"<<endl;
  for (size_t i=0;i<num_ins;i++){
    cout<<endl<<endl<<"Reporte de instruccion "<<i+1<<":"<<endl;
    cout<<"---------------------------"<<endl;
    if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_tipo_slot() == true){
          cout<<"Este es el home de un robot.";
          instrucciones[i]->set_estado(false);
    }
    else{
      if(tolower(instrucciones[i]->get_operacion())=='i'){
        if (a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_estado()=='E'){
          cout<<"No hubo problemas.";
          instrucciones[i]->set_estado(true);
        }
        else if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_estado()=='L'){
            if(instrucciones[i]->get_producto()==a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_tipo_producto()){
              cout<<"No hubo problemas.";
              instrucciones[i]->set_estado(true);
            }
            else{
              cout<<"Este slot contiene un producto diferente al cual desea ingresar.";
              instrucciones[i]->set_estado(false);
            }
        }
        else{
          cout<<"Este slot esta lleno.";
          instrucciones[i]->set_estado(false);
        }
      }
      else{
        if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_estado()=='E'){
          cout<<"Este slot está vacío.";
          instrucciones[i]->set_estado(false);
        }
        else if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_estado()=='L'){
          cout<<"No hubo problemas.";
          instrucciones[i]->set_estado(true);
        }
        else{
          cout<<"No hubo problemas.";
          instrucciones[i]->set_estado(true);
        } 
      } 
    cout<<endl;
    }
  }
}

void rutas(numero n_instrucciones,vector<instruccion_t*> instrucciones,numero filas_almacen, numero columnas_almacen, almacen_t* a1){
  cout<<endl<<endl<<"                   RUTAS PARA CADA INSTRUCCION                  "<<endl<<"_________________________________________________________"<<endl;

  for (size_t k=0;k<n_instrucciones;k++){
    if(instrucciones[k]->get_estado()==true){
      ingresar_coordenadas_ruta(a1->get_robots()[instrucciones[k]->get_n_robot()-1],instrucciones[k]);
      
      vector<columna> v=a1->get_robots()[instrucciones[k]->get_n_robot()-1]->_ruta;

      vector<arreglo> dibujo_ruta (filas_almacen,arreglo(columnas_almacen,' '));

      dibujo_ruta[a1->get_robots()[instrucciones[k]->get_n_robot()-1]->get_ubicacion_actualx()][a1->get_robots()[instrucciones[k]->get_n_robot()-1]->get_ubicacion_actualy()]='*';
    
      for (int i = 0; i < v.size(); ++i){
        vector<coordenada> posicion(2);
        int p=0;
        for (int j = 0; j < v[i].size(); ++j){
          posicion[p]=v[i][j];
          p++;
        }
        dibujo_ruta[posicion[0]][posicion[1]]='-';

        a1->get_robots()[instrucciones[k]->get_n_robot()-1]->set_ubicacion_actual(posicion[0],posicion[1]);
      }

      cout<<endl<<"Ruta de instruccion "<<k+1<<":"<<endl;
      cout<<"_______________________"<<endl;
      dibuja_ruta(columnas_almacen, filas_almacen, dibujo_ruta);

      if(tolower(instrucciones[k]->get_operacion())=='i'){
        
        a1->get_matriz_slots()[instrucciones[k]->get_destinox()][instrucciones[k]->get_destinoy()]->adicionar(instrucciones[k]->get_producto());
      }
      
      else{
        a1->get_matriz_slots()[instrucciones[k]->get_destinox()][instrucciones[k]->get_destinoy()]->retirar(instrucciones[k]->get_producto());
      }
    }
  }
}
