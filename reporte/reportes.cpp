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
    * A partir de una altura y peso que se ingresen por teclado, mostrar todos
    * los usuarios que tengan altura mayor a la ingresa o peso mayor al
    * ingresado.
*/

void reporte1(){
    title("REPORTE 1", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    float altura, peso;
    int pos=0;
    bool estado=false;
    usuario uno;
    cout<<endl<<"Ingrese la altura: ";
    cin>>altura;
    cout<<"Ingrese peso: ";
    cin>>peso;
    while(LeerUsuario(uno, pos++)){
        if(altura<uno.altura && peso<uno.peso){
            MostrarUsuario(uno);
            estado=true;
        }
    }
    ///comprobación
    if(estado==false){
        system("cls");
        msj("NO EXISTE USUARIO CON ESAS CONDICIONES", 15, 3, 1, 1);
        return;
    }

    system("pause");
    system("cls");
}

/*
    *Listar la cantidad de usuarios distintos que hayan entrenado
    *más de 250 minutos en algún registro de entrenamiento.
*/

void reporte2(){
    title("REPORTE 2", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

    usuario *uno;
    entrenamiento dos;
    int cant=CantidadUsuarios(), pos=0, *minutos;
    ///memoria dinamica
    uno=(usuario *)malloc(cant*sizeof(usuario));
    if(uno==NULL){
        return;
    }
    minutos=(int *)malloc(cant*sizeof(int));
    if(minutos==NULL){
        return;
    }
    ///cargar vectores
    for(int x=0;x<cant;x++){
        LeerUsuario(uno[x], x);
        minutos[x]=0;
    }
    for(int x=0;x<cant;x++){
        while(LeerEntrenamiento(dos, pos++)){
            if(uno[x].id==dos.idUsuario){
                minutos[x]+=dos.tiempo;
            }
        }
        pos=0;
    }
    ///buscar la cantidad
    int cantidad=0;
    for(int x=0;x<cant;x++){
        if(minutos[x]>120){
            cantidad++;
        }
    }
    ///mostrar
    cout<<endl<<endl<<"cantidad de usuarios distintos que hayan entrenado más de 250 minutos: "<<cantidad<<endl<<endl;
    free(uno);
    free(minutos);

    system("pause");
    system("cls");
}
