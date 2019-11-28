#include "biblioteca.h"
#include "funciones.h"
#include "robot.h"
#include "funciones.h"
#include "instruccion.h"
#include "almacen.h"

vector<columna> costruir_ruta_p(coordenada xi, coordenada yi, coordenada xf, coordenada yf){
  vector<columna> ruta_p;
  coordenada ubicx=xi;
  coordenada ubicy=yi;
  if(ubicx!=xf||ubicy!=yf){
    while(ubicx!=xf||ubicy!=yf){
      int nx=0;
      int ny=0;
      if(ubicx<xf){
        nx=1;
        if(ubicy<yf)
          ny=1;
        else if (ubicy==yf)
          ny=0;
        else
          ny=-1;
      }
      else if(ubicx==xf){
        if(ubicy<yf)
          ny=1;
        else
          ny=-1;
      }
      else{
        nx=-1;
        if(ubicy<yf)
          ny=1;
        else if (ubicy==yf)
          ny=0;
        else
          ny=-1;
      }
      coordenada respaldox=ubicx;
      coordenada respaldoy=ubicy;
      ubicx=ubicx+nx;
      columna coordenadas_ruta1= {ubicx, ubicy};
      ubicy=ubicy+ny;
      columna coordenadas_ruta2= {ubicx, ubicy};
      if(coordenadas_ruta1[0]==respaldox&&coordenadas_ruta1[1]==respaldoy){
        ruta_p.push_back(coordenadas_ruta2);
      }
      else{
        if(coordenadas_ruta1[0]==coordenadas_ruta2[0]&&coordenadas_ruta1[1]==coordenadas_ruta2[1]){
          ruta_p.push_back(coordenadas_ruta2);
        }
        else{
          ruta_p.push_back(coordenadas_ruta1);
          ruta_p.push_back(coordenadas_ruta2);
        }
      }
    }
  }
  return ruta_p;
}

void bienvenida(){
  ifstream archivo;
  archivo.open("inicio.txt");
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
    else{
      product=almacen->get_matriz_slots()[fila][columna]->get_tipo_producto();
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
  numero x,y;
  cout<<endl<<"Si desea finalizar proceso ingrese -1 en filas.";

  genera_archivos_slots(almacen_de_slots);

  do{
    cout<<endl<<endl<<"Ingrese fila de slot: ";cin>>x;
    if(x==-1){
      break;
    }
    cout<<"Ingrese columna de slot: ";cin>>y;
    if(almacen_de_slots->get_matriz_slots()[x][y]->get_tipo_slot()==false){

      cout<<endl<<endl<<"Slot "<<"["<<x<<"]["<<y<<"]:"<<endl;
      cout<<"Tipo de producto: "<<almacen_de_slots->get_matriz_slots()[x][y]->get_tipo_producto()<<endl;
      cout<<"Cantidad: "<<almacen_de_slots->get_matriz_slots()[x][y]->get_cantidad()<<endl;
      cout<<"Estado: ";
      if(almacen_de_slots->get_matriz_slots()[x][y]->get_estado()=='E'){
        cout<<"Vacío";
      }
      else if(almacen_de_slots->get_matriz_slots()[x][y]->get_estado()=='L'){
        cout<<"Libre";
      }
      else{
        cout<<"Lleno";
      }
    }
    else{
      cout<<endl<<endl<<"Slot "<<"["<<x<<"]["<<y<<"]:"<<endl;
      cout<<"Es un home de un robot.";
    }
  }while(true);
}

void reporte(vector<instruccion_t*> instrucciones, almacen_t* a1, numero num_ins){
  cout<<endl<<"                   REPORTE DE INSTRUCCIONES                   "<<endl;
  cout<<"__________________________________________________________"<<endl;
  for (size_t i=0;i<num_ins;i++){
    cout<<endl<<endl<<"Reporte de instruccion "<<i+1<<":"<<endl;
    cout<<"---------------------------"<<endl;
    if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_tipo_slot() == true){
          cout<<"Este es el home de un robot."<<endl;
          instrucciones[i]->set_estado(false);
    }
    else{
      if(tolower(instrucciones[i]->get_operacion())=='i'){
        if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_cantidad()==a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_capacidad()){
            
            cout<<"Slot lleno";
            instrucciones[i]->set_estado(false);
        }

        else if (a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_cantidad()== 0){

            instrucciones[i]->set_estado(true);

            a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->adicionar(instrucciones[i]->get_producto());
        }

        else{
          instrucciones[i]->set_estado(true);

          a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->adicionar(instrucciones[i]->get_producto());
        }
      }

      else{
        if(a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->get_cantidad()==0){
          cout<<"Slot vacío.";
          instrucciones[i]->set_estado(false);
        }

        else{ 
          cout<<"No hubo problemas.";
          instrucciones[i]->set_estado(true);

          a1->get_matriz_slots()[instrucciones[i]->get_destinox()][instrucciones[i]->get_destinoy()]->retirar();
        } 

      }
    }
    cout<<endl<<"Estado: ";
    if(instrucciones[i]->get_estado()==true){
      cout<<"Activo.";
    }
    else {cout<<"Inactivo.";}
  }
}


//De rutas en adelante
