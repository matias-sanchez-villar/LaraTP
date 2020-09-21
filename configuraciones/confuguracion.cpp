#include <iostream>
using namespace std;
#include <cstdlib>
#include "confuguracion.h"
#include "../InterfazGrafica/ui.h"
#include "../estructura.h"
#include "ArchivosConfiguraciones.h"
#include "../usuario/ArchivosUsuario.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"
#include "../validacion.h"

void CopiaSeguridad(){
    title("COPIA DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    while(ConfirmacionConfiguracion()==false){
        if(continuar()==false){
            return;
        }
        system ("cls");
    }
    ///guardamos usuarios
    int cant=TotalUsuarios();
    if(cant==-1){
        msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
        free(uno);
        return;
    }
    for(int x=0;x<cant;x++){
        uno[x]=TraerUsuario(x);
    }
    if(GuardamosCopiaUsuario(uno, cant)!=cant){
        msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
        free(uno);
        return;
    }
    free(uno);
    ///guardamos entrenamiento
    cant=TotalEntremanitos();
    if(cant==-1){
        msj("ERROR DE ARCHIVO 1", 15, 3, 1, 1);
        return;
    }
    entrenamiento *dos;
    dos=(entrenamiento *)malloc(cant * sizeof(entrenamiento));
    if(dos==NULL){
        msj("Error de archivo 2", 15, 3, 1, 1);
        free(dos);
        return;
    }
    for(int x=0;x<cant;x++){
        dos[x]=TreaerEntrenamiento(x);
    }
    if(GuardamosCopiaEntrenamiento(dos, cant)!=cant){
        msj("ERROR DE ARCHIVO 3", 15, 3, 1, 1);
        free(dos);
        return;
    }
    free(dos);
    system ("cls");
    msj("COPIA DE SEGURIDAD GUARDADA", 15, 3, 1, 1);
}

void RestaurarCopia(){
    title("RESTAURAR COPIA DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);cout<<endl;
    while(ConfirmacionConfiguracion()==false){
        if(continuar()==false){
            return;
        }
        system ("cls");
    }
    ///cambiamos usuario
    int cant=TotalUsuariosbkp();
    if(cant==-1){
        msj("ERROR DE ARCHIVO ", 15, 3, 1, 1);
        return;
    }
    participante *uno;
    uno=(participante *)malloc(cant * sizeof(participante));
    if(uno==NULL){
        msj("ERROR DE ARCHIVO 2", 15, 3, 1, 1);
        free(uno);
        return;
    }
    if(CargarUsuariobkp(uno, cant)!=cant){
        msj("ERROR DE ARCHIVO 3", 15, 3, 1, 1);
        free(uno);
        return;
    }
    if(GuardarUsuarioBKP_en_DAt(uno, cant)!=cant){
        msj("Error de archivo 4", 15, 3, 1, 1);
        free(uno);
        return;
    }
    free(uno);
    ///cambiamos entrenamiento
    cant=TotalEntremanitosbkp();
    if(cant==-1){
        msj("Error de archivo 1", 15, 3, 1, 1);
        return;
    }
    entrenamiento *dos;
    dos=(entrenamiento *)malloc(cant*sizeof(entrenamiento));
    if(dos==NULL){
        msj("Error de archivo 2", 15, 3, 1, 1);
        free(dos);
        return;
    }
    if(CargarEntrenamientosbkp(dos, cant)!=cant){
        msj("Error de archivo 3", 15, 3, 1, 1);
        return;
    }
    if(GuardarEntrenamietoBKP_en_DAt(dos, cant)!=cant){
        msj("Error de archivo 4", 15, 3, 1, 1);
        free(dos);
        return;
    }
    free(dos);
    system ("cls");
    msj("COPIA DE SEGURIDAD GUARDADA", 15, 3, 1, 1);
}

