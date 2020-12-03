#include <iostream>
using namespace std;
#include <cstdio>
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
    for(int x=0 ;x<cant;x++){
        LeerUsuario(uno[x],x);
    }
    if(GuardarCopiaUsuarioBKP(uno, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
    }
    ///GENERAR COPIA ENTRENAMIENTO
    entrenamiento *dos;
    cant=CantidadEntrenaminto();
    dos=(entrenamiento *) malloc (cant * sizeof(entrenamiento));
    for(int x=0 ;x<cant;x++){
        LeerEntrenamiento(dos[x],x);
    }
    if(GuardarCopiaEntrenamientoBKP(dos, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
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
    for(int x=0 ;x<cant;x++){
        LeerUsuarioBKP(uno[x],x);
    }
    if(GuardarCopiaUsuario(uno, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
    }
    ///GENERAR COPIA ENTRENAMIENTO
    entrenamiento *dos;
    cant=CantidadEntrenamientosBKP();
    dos=(entrenamiento *) malloc (cant * sizeof(entrenamiento));
    for(int x=0 ;x<cant;x++){
        LeerEntrenamientoBKP(dos[x],x);
    }
    if(GuardarCopiaEntrenamiento(dos, cant)==false){
        system("cls");
        msj("ERROR COPIA NO GUARDADA", 15, 3, 1, 1);
    }
    system("cls");
    msj("COPIA GENERADA CORRECTAMENTE", 15, 3, 1, 1);
}
