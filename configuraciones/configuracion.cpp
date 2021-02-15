#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "configuracion.h"
#include "ArchivosConfiguracion.h"
#include "../estructura.h"
#include "../usuarios/ArchivosUsuarios.h"
#include "../entrenamientos/ArchivosEntrenamiento.h"
#include "../validaciones.h"
#include "../InterfazGrafica/ui.h"

void CopiaSeguridad(){
    title("COPIA DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Desea continuar (SI/NO): ";
    if(continuar()==false){
        system ("cls");
        return;
    }
    ///GENERAR COPIA USUARIO
    usuario *uno;
    int cant;
    cant=CantidadUsuarios();
    uno=(usuario *) malloc (cant * sizeof(usuario));
    if(uno==NULL){
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    for(int x=0 ;x<cant;x++){
        LeerUsuario(uno[x],x);
    }
    if(GuardarCopiaUsuarioBKP(uno, cant)==false){
        system("cls");
        free(uno);
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    ///GENERAR COPIA ENTRENAMIENTO
    entrenamiento *dos;
    cant=CantidadEntrenaminto();
    dos=(entrenamiento *) malloc (cant * sizeof(entrenamiento));
    if(dos==NULL){
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    for(int x=0 ;x<cant;x++){
        LeerEntrenamiento(dos[x],x);
    }
    free(uno);
    free(dos);
    if(GuardarCopiaEntrenamientoBKP(dos, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    system("cls");
    msj("COPIA GENERADA CORRECTAMENTE", 15, 3, 1, 1);
}

void RestaurarCopia(){
    title("RESTAURAR COPIA DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    cout<<endl<<"Desea continuar (SI/NO): ";
    if(continuar()==false){
        system ("cls");
        return;
    }
    ///GENERAR COPIA USUARIO
    usuario *uno;
    int cant;
    cant=CantidadUsuariosBKP();
    uno=(usuario *) malloc (cant * sizeof(usuario));
    if(uno==NULL){
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    for(int x=0 ;x<cant;x++){
        LeerUsuarioBKP(uno[x],x);
    }
    if(GuardarCopiaUsuario(uno, cant)==false){
        system("cls");
        free(uno);
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    ///GENERAR COPIA ENTRENAMIENTO
    entrenamiento *dos;
    cant=CantidadEntrenamientosBKP();
    dos=(entrenamiento *) malloc (cant * sizeof(entrenamiento));
    if(dos==NULL){
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    for(int x=0 ;x<cant;x++){
        LeerEntrenamientoBKP(dos[x],x);
    }
    free(uno);
    free(dos);
    if(GuardarCopiaEntrenamiento(dos, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
        return;
    }
    system("cls");
    msj("COPIA GENERADA CORRECTAMENTE", 15, 3, 1, 1);
}
