#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "reportes.h"
#include "ArchivosReportes.h"
#include "../estructura.h"
#include "../validaciones.h"
#include "../InterfazGrafica/ui.h"
#include "../entrenamientos/ArchivosEntrenamiento.h"
#include "../usuarios/ArchivosUsuarios.h"
#include "../configuraciones/ArchivosConfiguracion.h"
#include "../entrenamientos/entrenamiento.h"
#include "../usuarios/usuario.h"

/*
    *A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento
    *de mayor cantidad de calorías y la fecha en que las registró.
    *Si hay dos registro con misma cantidad, mostrar el primero de ellos.
*/

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;

    int ID, pos=0;
    float Calorias=0;
    entrenamiento uno;
    cout<<"Ingrese el ID de Usuario: ";
    cin>>ID;
    for(int x=0;x<CantidadEntrenaminto();x++){
        LeerEntrenamiento(uno, x);
        if(uno.idUsuario==ID && uno.calorias>Calorias){
            pos=x;
            cout<<pos;
            Calorias=uno.calorias;
            cout<<Calorias;
        }
    }
    LeerEntrenamiento(uno, pos);
    MostrarEntramiento(uno);

    system("pause");
    system("cls");
}

/*

*/

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;

    system("pause");
    system("cls");
}
