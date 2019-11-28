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

void cantidad_robots(int & n_robots, numero f, numero c){
  cout<<endl<<"Nota: Mínimo 3 robots"<<endl<<endl;
  do{
  cout<<"Ingrese numero de robots: ";cin>>n_robots;}while(n_robots<3||n_robots>(f*c)/2);
}

void num_instrucciones(int &num){
  cout<<endl;
  cout<<"Ingrese numero de instrucciones: ";cin>>num;
}

void setea_almacen (numero &filas, numero &columnas, numero &capacidad){
  cout<<endl;
  do{
  cout<<"Ingrese cantidad filas del almacen: ";cin>>filas;
  cout<<"Ingrese cantidad de columnas del almacen: ";cin>>columnas;
  cout<<endl;
  }while(filas<3||columnas<3);
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
  cout<<endl<<endl<<"                   REPORTE DE INSTRUCCIONES                   "<<endl;
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

void rutas(numero n_instrucciones,vector<instruccion_t*> instrucciones,numero filas_almacen, numero columnas_almacen, almacen_t* a1){
  cout<<endl<<endl<<"                   RUTAS PARA CADA INSTRUCCION                  "<<endl<<"_________________________________________________________"<<endl;
//vector<columna> costruir_ruta_p(coordenada xi, coordenada yi, coordenada xf, coordenada yf)
ofstream rutas ("rutas.txt");
  for (size_t k=0;k<n_instrucciones;k++){
    if(instrucciones[k]->get_estado()==true){
      auto robot=a1->get_robots()[instrucciones[k]->get_n_robot()-1];
      vector <columna> v;
      if(tolower(instrucciones[k]->get_operacion())=='i'){
        
        vector<columna> v1;
        
        if(robot->get_ubicacion_actualx()!=robot->get_homex() && robot->get_ubicacion_actualy()!=robot->get_homey()){
          
          v1=costruir_ruta_p(robot->get_ubicacion_actualx(), robot->get_ubicacion_actualy(), robot->get_homex(),robot->get_homey());

        }

        vector<columna> v2=costruir_ruta_p(robot->get_homex(),robot->get_homey(),instrucciones[k]->get_destinox(),instrucciones[k]->get_destinoy());

        for (auto& i:v1)
          v.push_back(i);
        for (auto& j:v2)
          v.push_back(j);

      }
      else{
        vector<columna> v1=costruir_ruta_p(robot->get_ubicacion_actualx(),robot->get_ubicacion_actualy(),instrucciones[k]->get_destinox(),instrucciones[k]->get_destinoy());
        
        vector<columna> v2=costruir_ruta_p(instrucciones[k]->get_destinox(), instrucciones[k]->get_destinoy(), robot->get_homex(),robot->get_homey()); 
      
      for (auto& i:v1)
          v.push_back(i);
        for (auto& j:v2)
          v.push_back(j);
      }
        //Importante
      for (auto &i:v){
        robot->_ruta.push_back(i);
        }
      robot->_rutas_dibujar.push_back(v);

      vector<arreglo> dibujo_ruta (filas_almacen,arreglo(columnas_almacen,' '));
      
      dibujo_ruta[a1->get_robots()[instrucciones[k]->get_n_robot()-1]->get_ubicacion_actualx()][a1->get_robots()[instrucciones[k]->get_n_robot()-1]->get_ubicacion_actualy()]='*';

      rutas<<"Instruccion "<<k+1<<":"<<endl;
      rutas<<"Numero de robot: "<<instrucciones[k]->get_n_robot()<<endl;
      for (int i = 0; i < v.size(); ++i){
        vector<coordenada> posicion(2);
        int p=0;
        for (int j = 0; j < v[i].size(); ++j){
          rutas<<v[i][j]<<" ";
          posicion[p]=v[i][j];
          p++;
        }
        rutas<<endl;
        char number='a'+i;
        dibujo_ruta[posicion[0]][posicion[1]]=number;

        a1->get_robots()[instrucciones[k]->get_n_robot()-1]->set_ubicacion_actual(posicion[0],posicion[1]);
      }

      cout<<endl<<"Ruta de instruccion "<<k+1<<":"<<endl;
      cout<<"_______________________"<<endl;
      dibuja_ruta(columnas_almacen, filas_almacen, dibujo_ruta);
    }
  rutas<<endl;
  }
}

void genera_archivos_slots(almacen_t* almacen_de_slots){
  ofstream slots("slots.txt");
  for (size_t i=0;i<almacen_de_slots->get_filas();i++){
    for (size_t j=0;j<almacen_de_slots->get_columnas();j++){
      if(almacen_de_slots->get_matriz_slots()[i][j]->get_tipo_slot()==false){
      slots<<endl<<"Slot "<<"["<<i<<"]["<<j<<"]:"<<endl;
      slots<<"Tipo de producto: "<<almacen_de_slots->get_matriz_slots()[i][j]->get_tipo_producto()<<endl;
      slots<<"Cantidad: "<<almacen_de_slots->get_matriz_slots()[i][j]->get_cantidad()<<endl;
      }
      else{
      slots<<endl<<endl<<"Slot "<<"["<<i<<"]["<<j<<"]:"<<endl;
      slots<<"Es un home de un robot.";
      }
    }
  }
}

void logo(){
  ifstream archivo;
  archivo.open("logo.txt");
  string texto;
  while(!archivo.eof()){
    getline(archivo,texto);
    cout<<texto<<endl;
  }
  archivo.close();

  char x = '0';
  cout<<"Ingrese cualquier caracter para continuar..."<<endl;
  do{
    cin>>x;
  }while(x == '0');
  limpiar();
}

void limpiar(){
  cout<<"\033[2J\033[0;0H";
}

void menu(vector<instruccion_t*> instrucciones, almacen_t* a1, numero n_instrucciones, numero filas_almacen, numero columnas_almacen){
  numero opcion;
  cout<<endl<<endl<<endl<<"MENÚ:"<<endl<<endl<<"1. Reporte de instrucciones."<<endl<<"2. Rutas de robots."<<endl<<"3. Reporte de slots";
  cout<<endl<<endl<<"Ingrese opción: ";cin>>opcion;
  switch(opcion){
    case 1:
      reporte(instrucciones,a1,n_instrucciones); //Reporte
      break;
    case 2:
      rutas(n_instrucciones, instrucciones, filas_almacen, columnas_almacen, a1);
      break;
    case 3:
      reporte_slots(a1);
      break;
    default:
      cout<<endl<<"Opción no válida.";
  } //Menu
}
