#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "ArchivosReportes.h"
#include "../estructura.h"
#include "../entrenamiento/entrenamiento.h"
#include "../InterfazGrafica/ui.h"
#include "../usuario/ArchivosUsuario.h"
#include "../entrenamiento/ArchivosEntrenamientos.h"

struct fecha MayorCantidadCalorias(int id, float *calorias){
    entrenamiento uno;
    fecha dos;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            dos.dia=-1;
            fclose(p);
            return dos;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if (id==uno.idUsuario){
            if(*calorias==0 || *calorias<uno.calorias){
                *calorias=uno.calorias;
                dos.dia=uno.entrenamiento.dia;
                dos.mes=uno.entrenamiento.mes;
                dos.anio=uno.entrenamiento.anio;
            }
        }
    }
    fclose(p);
return dos;
}

int CantidadEntrenamientos(int x){
    int cantidad=0;
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return -1;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(x==uno.actividad){
            cantidad++;
        }
    }
    fclose(p);
return cantidad;
}

void MostrarPerfilUsuario(int x){
    entrenamiento uno;
    FILE *p=fopen("archivos/entrenamientos.dat","rb");
        if(p==NULL){
            fclose(p);
            return;
        }
    while(fread(&uno, sizeof(entrenamiento),1,p)){
        if(uno.actividad==x){
        MostarUsuario(uno.idUsuario);
        }
    }
    fclose(p);
}
